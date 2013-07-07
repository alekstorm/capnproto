-- Copyright (c) 2013, Kenton Varda <temporal@gmail.com>
-- All rights reserved.
--
-- Redistribution and use in source and binary forms, with or without
-- modification, are permitted provided that the following conditions are met:
--
-- 1. Redistributions of source code must retain the above copyright notice, this
--    list of conditions and the following disclaimer.
-- 2. Redistributions in binary form must reproduce the above copyright notice,
--    this list of conditions and the following disclaimer in the documentation
--    and/or other materials provided with the distribution.
--
-- THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
-- ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
-- WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
-- DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
-- ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
-- (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
-- LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
-- ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
-- (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
-- SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

{-# LANGUAGE TemplateHaskell #-}
{-# LANGUAGE ViewPatterns #-}

module JavaGenerator(generateJava) where

import qualified Codec.Binary.UTF8.String as UTF8
import Data.Binary(encode)
import Data.Binary.IEEE754(floatToWord, doubleToWord)
import Data.ByteString(ByteString, readFile)
import Data.ByteString.Lazy(unpack)
import qualified Data.ByteString.Lazy.Char8 as LZ
import qualified Data.ByteString.UTF8 as ByteStringUTF8
import qualified Data.Digest.MD5 as MD5
import Data.FileEmbed(embedDir)
import System.FilePath(combine)
import Data.Functor((<$>))
import Data.List(stripPrefix)
import qualified Data.Map as Map
import Data.Maybe(catMaybes, fromMaybe, isJust)
import qualified Data.Set as Set
import Data.Word(Word8, Word64)
import Prelude hiding (readFile)
import Text.Hastache
import Text.Hastache.Context
import Text.Printf(printf)
import System.Directory (doesFileExist)
import System.FilePath(takeBaseName)

import Semantics
import Util
import WireFormat

capnpPackage = "capnproto."

muMaybe m = maybe muNull muJust m

-- MuNothing isn't considered a false value for the purpose of {{#variable}} expansion.  Use this
-- instead.
muNull = MuBool False

-- There is no way to make a MuType from a singular MuContext, i.e. for optional sub-contexts.
-- Using a single-element list has the same effect, though.
muJust c = MuList [c]

-- TODO deduplicate with CxxGenerator.hs
packageAnnotationId = 0x55fa396d6a015d11

filePackage desc = fmap testAnnotation $ Map.lookup packageAnnotationId $ fileAnnotations desc

-- TODO generate Haskell code for annotations too, like Scala (here, built-in ones)
testAnnotation (_, TextDesc x) = x
testAnnotation (desc, _) =
    error "Annotation was supposed to be text, but wasn't: " ++ annotationName desc

globalName desc = fromMaybe "" $ globalName' desc where
    globalName' (DescFile desc) = filePackage desc
    globalName' desc = Just $ (maybe "" (++ ".") $ globalName' $ descParent desc) ++ descName desc

-- Flatten the descriptor tree in pre-order, returning struct, union, and interface descriptors
-- only.  We skip enums because they are always declared directly in their parent scope.
flattenTypes :: [Desc] -> [Desc]
flattenTypes [] = []
flattenTypes (d@(DescStruct s):rest) = d:(flattenTypes children ++ flattenTypes rest) where
    children = catMaybes $ Map.elems $ structMemberMap s
flattenTypes (d@(DescUnion u):rest) = d:(flattenTypes children ++ flattenTypes rest) where
    children = catMaybes $ Map.elems $ unionMemberMap u
flattenTypes (d@(DescInterface i):rest) = d:(flattenTypes children ++ flattenTypes rest) where
    children = catMaybes $ Map.elems $ interfaceMemberMap i
flattenTypes (_:rest) = flattenTypes rest

hashString :: String -> String
hashString str =
    concatMap (printf "%02x" . fromEnum) $
    MD5.hash $
    UTF8.encode str

isPrimitive (BuiltinType BuiltinText) = False
isPrimitive (BuiltinType BuiltinData) = False
isPrimitive (BuiltinType BuiltinObject) = False
isPrimitive (BuiltinType _) = True
isPrimitive (EnumType _) = True
isPrimitive _ = False

isComposite t = isStruct t || isList t || isText t

isStruct (StructType _) = True
isStruct _ = False

isList (ListType _) = True
isList _ = False

isText (BuiltinType BuiltinText) = True
isText _ = False

javaTypeString (BuiltinType BuiltinVoid) = "scala.runtime.BoxedUnit"
javaTypeString (BuiltinType BuiltinBool) = "boolean"
javaTypeString (BuiltinType BuiltinInt8) = "byte"
javaTypeString (BuiltinType BuiltinInt16) = "short"
javaTypeString (BuiltinType BuiltinInt32) = "int"
javaTypeString (BuiltinType BuiltinInt64) = "long"
javaTypeString (BuiltinType BuiltinUInt8) = "byte"
javaTypeString (BuiltinType BuiltinUInt16) = "char"
javaTypeString (BuiltinType BuiltinUInt32) = "int"
javaTypeString (BuiltinType BuiltinUInt64) = "long"
javaTypeString (BuiltinType BuiltinFloat32) = "float"
javaTypeString (BuiltinType BuiltinFloat64) = "double"
javaTypeString (BuiltinType BuiltinText) = "capnproto.composite.TextGateway"
javaTypeString (BuiltinType BuiltinData) = "capnproto.composite.DataGateway"
javaTypeString (EnumType desc) = globalName $ DescEnum desc
javaTypeString (StructType desc) = "capnproto.StructGateway<" ++ foo ++ ".Reader, " ++ foo ++ ".Builder>" where
    foo = globalName $ DescStruct desc
javaTypeString (ListType desc) = "capnproto.ListGateway<" ++ (javaTypeString desc) ++ ">"

javaTypeString (InlineStructType desc) = globalName $ DescStruct desc
javaTypeString (InterfaceType desc) = globalName $ DescInterface desc
javaTypeString (BuiltinType BuiltinObject) = _|_ -- FIXME; luckily, not in test.capnp yet
javaTypeString (InlineListType t s) = _|_
javaTypeString (InlineDataType s) = _|_

javaGenericTypeString (BuiltinType BuiltinBool) = "Boolean"
javaGenericTypeString (BuiltinType BuiltinInt8) = "Byte"
javaGenericTypeString (BuiltinType BuiltinInt16) = "Short"
javaGenericTypeString (BuiltinType BuiltinInt32) = "Integer"
javaGenericTypeString (BuiltinType BuiltinInt64) = "Long"
javaGenericTypeString (BuiltinType BuiltinUInt8) = "spire.math.UByte"
javaGenericTypeString (BuiltinType BuiltinUInt16) = "spire.math.UShort"
javaGenericTypeString (BuiltinType BuiltinUInt32) = "spire.math.UInt"
javaGenericTypeString (BuiltinType BuiltinUInt64) = "spire.math.ULong"
javaGenericTypeString (BuiltinType BuiltinFloat32) = "Float"
javaGenericTypeString (BuiltinType BuiltinFloat64) = "Double"
javaGenericTypeString t = javaTypeString t

-- TODO might be duplicating code elsewhere
capnTypeString (BuiltinType BuiltinVoid) = "Void"
capnTypeString (BuiltinType BuiltinBool) = "Bool"
capnTypeString (BuiltinType BuiltinInt8) = "Int8"
capnTypeString (BuiltinType BuiltinInt16) = "Int16"
capnTypeString (BuiltinType BuiltinInt32) = "Int32"
capnTypeString (BuiltinType BuiltinInt64) = "Int64"
capnTypeString (BuiltinType BuiltinUInt8) = "UInt8"
capnTypeString (BuiltinType BuiltinUInt16) = "UInt16"
capnTypeString (BuiltinType BuiltinUInt32) = "UInt32"
capnTypeString (BuiltinType BuiltinUInt64) = "UInt64"
capnTypeString (BuiltinType BuiltinFloat32) = "Float32"
capnTypeString (BuiltinType BuiltinFloat64) = "Float64"
capnTypeString (BuiltinType BuiltinText) = "Text"
capnTypeString (BuiltinType BuiltinData) = "Data"
capnTypeString (EnumType desc) = "Enum"
capnTypeString (StructType desc) = "Struct"
capnTypeString (ListType desc) = "List"

javaDefaultMask VoidDesc = "scala.Unit.box(null)"
javaDefaultMask (BoolDesc    b) = if b then "true" else "false"
javaDefaultMask (Int8Desc    i) = show i
javaDefaultMask (Int16Desc   i) = show i
javaDefaultMask (Int32Desc   i) = show i
javaDefaultMask (Int64Desc   i) = show i ++ "L"
-- users can use their own solution for doing unsigned modular arithmetic (like Guava)
javaDefaultMask (UInt8Desc   i) = toSigned 8 $ fromIntegral i
javaDefaultMask (UInt16Desc  i) = show i -- 'char' is already unsigned
javaDefaultMask (UInt32Desc  i) = toSigned 32 $ fromIntegral i
javaDefaultMask (UInt64Desc  i) = (toSigned 64 $ fromIntegral i) ++ "L" -- TODO figure out how to use spire's UInt/ULong/etc in Java
javaDefaultMask (Float32Desc x) = show x  ++ "F"
javaDefaultMask (Float64Desc x) = show x
javaDefaultMask (EnumerantValueDesc v) = toSigned 16 $ enumerantNumber v

toSigned :: Integer -> Integer -> String
toSigned p i = show $ if (i >= 2 ^ (p - 1)) then i - 2 ^ p else i

-- TODO use in CxxGenerator as well
-- TODO macro version of laziness in scala?
defaultZero (BuiltinType BuiltinVoid) = VoidDesc
defaultZero (BuiltinType BuiltinBool) = BoolDesc False
defaultZero (BuiltinType BuiltinInt8) = Int8Desc 0
defaultZero (BuiltinType BuiltinInt16) = Int16Desc 0
defaultZero (BuiltinType BuiltinInt32) = Int32Desc 0
defaultZero (BuiltinType BuiltinInt64) = Int64Desc 0
defaultZero (BuiltinType BuiltinUInt8) = UInt8Desc 0
defaultZero (BuiltinType BuiltinUInt16) = UInt16Desc 0
defaultZero (BuiltinType BuiltinUInt32) = UInt32Desc 0
defaultZero (BuiltinType BuiltinUInt64) = UInt64Desc 0
defaultZero (BuiltinType BuiltinFloat32) = Float32Desc 0
defaultZero (BuiltinType BuiltinFloat64) = Float64Desc 0
defaultZero (EnumType desc) = EnumerantValueDesc $ head $ enumerants desc

defaultValueBytes _ (TextDesc s) = Just (UTF8.encode s ++ [0])
defaultValueBytes _ (DataDesc d) = Just d
defaultValueBytes t v@(StructValueDesc _) = Just $ encodeMessage t v
defaultValueBytes t v@(ListDesc _) = Just $ encodeMessage t v
defaultValueBytes _ _ = Nothing

elementType (ListType t) = t
elementType _ = error "Called elementType on non-list."

repeatedlyTake _ [] = []
repeatedlyTake n l = take n l : repeatedlyTake n (drop n l)

enumerantContext parent desc = mkStrContext context where
    context s = named parent "enumerantName" (enumerantName desc) s

enumContext parent desc = mkStrContext context where
    context "enumerants" = listOf context enumerantContext ", " $ enumerants desc
    context s = named parent "enumName" (enumName desc) s

descDecl desc = head $ lines $ descToCode "" desc

named fallback prefix name s = case s of
    (stripPrefix prefix -> Just "") -> MuVariable name
    (stripPrefix prefix -> Just "LowerCase") -> MuVariable $ toLowerCase name
    (stripPrefix prefix -> Just "TitleCase") -> MuVariable $ toTitleCase name
    (stripPrefix prefix -> Just "UpperCase") -> MuVariable $ toUpperCaseWithUnderscores name
    _ -> fallback s

primitiveFieldContext parent desc = mkStrContext context where
    context "fieldJavaType" = MuVariable $ javaTypeString typ
    context "fieldScalaType" = MuVariable $ javaTypeString typ
    context "fieldCapnType" = MuVariable $ capnTypeString typ
    context "fieldEnum?" = MuBool $ case typ of
        EnumType _ -> True
        _ -> False
    context "fieldJavaDefaultMask" = MuVariable $ javaDefaultMask $ fromMaybe (defaultZero $ fieldType desc) $ fieldDefaultValue desc
    context s = parent s
    typ = fieldType desc

-- TODO merge with javaGenericTypeString
typeOf (BuiltinType BuiltinText) = capnpPackage ++ "composite.TextGateway"
typeOf (BuiltinType BuiltinData) = capnpPackage ++ "composite.DataGateway"
typeOf t@(BuiltinType _) = javaGenericTypeString t
typeOf t@(EnumType _) = javaGenericTypeString t
typeOf (StructType struct) = capnpPackage ++ "composite.StructGateway<" ++ name ++ ".Reader, " ++ name ++ ".Builder>" where
    name = structName struct
typeOf (ListType list) = capnpPackage ++ "composite.ListGateway<" ++ typeOf list ++ ">"
typeOf (InlineStructType _) = error "InlineStructType unimplemented"
typeOf (InlineListType _ _) = error "InlineListType unimplemented"
typeOf (InlineDataType _) = error "InlineDataType unimplemented"

gatewayTypeOf (BuiltinType BuiltinData) = "Data"
gatewayTypeOf (BuiltinType BuiltinText) = "List"
gatewayTypeOf (ListType list) = "List"
gatewayTypeOf (StructType struct) = "Struct"

listContext parent desc = mkStrContext context where
    context "listElemFormatter" = MuVariable $ bar parent desc
    context s = parent s

bar parent desc = "capnproto.composite.Formatter$.MODULE$." ++ foo where
    foo = case desc of
        ListType listDesc -> "<" ++ (javaGenericTypeString listDesc) ++ ">listFormatter(" ++ (bar parent listDesc) ++ ")"
        BuiltinType BuiltinData -> "dataFormatter(" ++ (bar parent $ BuiltinType BuiltinUInt8) ++ ")"
        StructType structDesc -> "<" ++ qux ++ ".Reader, " ++ qux ++ ".Builder>structFormatter(" ++ qux ++ ".FACTORY, " ++ qux ++ ".DATA_SIZE, " ++ qux ++ ".POINTER_SIZE)" where
            qux = globalName $ DescStruct structDesc
        EnumType enumDesc -> "<" ++ qux ++ ">enumFormatter(" ++ qux ++ ".values())" where
            qux = globalName $ DescEnum enumDesc
        _ -> toLowerCase (capnTypeString desc) ++ "Formatter()"

compositeFieldContext parent desc = mkStrContext context where
    context "fieldGateway" = MuVariable $ typeOf $ typ
    context "fieldList?" = muMaybe $ case typ of
        ListType elemDesc -> Just $ listContext context elemDesc
        _ -> Nothing
    context "fieldStruct?" = muMaybe $ case typ of
        StructType structDesc -> Just $ structContext context structDesc
        _ -> Nothing
    context "fieldGatewayType" = MuVariable $ gatewayTypeOf $ typ
    context "fieldDefaultBytes" = MuVariable $ "scala.Option.<byte[]>apply(" ++ (fromMaybe "null" $ fmap (\bytes -> "new byte[]{" ++ (delimit ",\n    " $ codeLines bytes) ++ "}") (fieldDefaultValue desc >>= defaultValueBytes (fieldType desc))) ++ ")"
    context s = parent s
    codeLines bytes = map (delimit ", ") $ repeatedlyTake 8 $ map (toSigned 8 . fromIntegral) bytes
    typ = fieldType desc

listOf :: Monad m => ([Char] -> MuType m) -> (([Char] -> MuType m) -> a -> MuContext m) -> [Char] -> [a] -> MuType m
listOf parent subContext sep list = MuList $ listOf' list where
    listOf' (x:xs) = (subContext context x) : listOf' xs where
        context "sep" = MuVariable $ case xs of
            _:_ -> sep
            [] -> ""
        context s = parent s
    listOf' [] = []

-- TODO rename these to, e.g. fieldStrContext
fieldContext parent desc = mkStrContext context where
    context "fieldDecl" = MuVariable $ descDecl $ DescField desc
    context "fieldPrimitive?" = muMaybe $ if (isPrimitive typ) then Just $ primitiveFieldContext context desc else Nothing
    context "fieldComposite?" = muMaybe $ if (isComposite typ) then Just $ compositeFieldContext context desc else Nothing
    context "fieldOffset" = MuVariable $ case fieldOffset desc of
        VoidOffset -> 0
        DataOffset size offset -> offset
        PointerOffset offset -> offset
    context "fieldSize" = MuVariable $ case fieldSize typ of
        SizeVoid -> 0
        SizeData size -> 64 `quot` (dataSizeInBits size)
        SizePointer -> 8
    context s = named parent "fieldName" (fieldName desc) s
    typ = fieldType desc

-- TODO what's in unionMembers? why is it a [Desc]?
unionContext parent desc = mkStrContext context where
    context "unionFields" = listOf context fieldContext ", " $ unionFields desc
    context "unionTagOffset" = MuVariable $ unionTagOffset desc
    context s = named parent "unionName" (unionName desc) s

-- TODO annotate with ID in generated code
structContext parent desc = mkStrContext context where
    context "structName" = MuVariable $ structName desc
    --context "structFullName" = MuVariable $ fullName (DescStruct desc)
    context "structDataSize" = MuVariable $ case structDataSize desc of
        DataSectionWords s -> s
        _ -> 1
    context "structPointerCount" = MuVariable $ structPointerCount desc
    context "structFields" = MuList $ map (fieldContext context) $ structFields desc
    context "structUnions" = MuList $ map (unionContext context) $ structUnions desc
    -- TODO deduplicate
    context "inner?" = MuBool $ case structParent desc of
        DescFile _ -> False
        _ -> True
    context s = container (structMembers desc) context parent s

container :: Monad m => [Desc] -> ([Char] -> MuType m) -> ([Char] -> MuType m) -> [Char] -> MuType m
container list context fallback s = let f subContext l = MuList $ map (subContext context) l in case s of
    "structChildren" -> f structContext [e | DescStruct e <- list]
    "enumChildren" -> f enumContext [e | DescEnum e <- list]
    --"constChildren" -> (constContext, (\l-> [e | DescConst e <- l]))
    --"annotationChildren" -> (annotationContext, (\l-> [e | DescAnnotation e <- l]))
    _ -> fallback s

importContext parent packageName = mkStrContext context where
    context "importPackageName" = MuVariable packageName
    context s = parent s

fileContexts :: Monad m => FileDesc -> [(String, MuContext m)]
fileContexts desc = map foo $ filter (isJust . fst) $ map strContext $ fileMembers desc where
    foo (Just name, strCtx) = (name, strCtx)
    strContext member = (name, mkStrContext context) where
        (name, structChild, enumChild) = deconstruct
        isImportUsed dep = Set.member (fileName dep) (fileRuntimeImports desc)

        context "fileId" = MuVariable $ fileId desc
        context "packageName" = case filePackage desc of
            Just packageName -> MuVariable packageName
            Nothing -> muNull
        --context "imports" = MuList $ map (importContext context)
        --                      $ catMaybes $ map filePackage $ filter isImportUsed $ Map.elems $ fileImportMap desc
        context "structChildren" = muMaybe $ structChild
        context "enumChildren" = muMaybe $ enumChild
        context s = error $ "Template variable not defined: " ++ s
        deconstruct = case member of
            DescStruct structDesc -> (Just $ structName structDesc, Just $ structContext context structDesc, Nothing)
            DescEnum enumDesc -> (Just $ enumName enumDesc, Nothing, Just $ enumContext context enumDesc)
            _ -> (Nothing, Nothing, Nothing)

templateExt = ".mustache"
templates = Map.fromList $(embedDir "src/java")
srcTemplateFile = "java" ++ templateExt
srcTemplate = ByteStringUTF8.toString $ Map.findWithDefault (error $ "Source template not found: " ++ srcTemplateFile) srcTemplateFile templates

hastacheConfig :: MuConfig IO
hastacheConfig = MuConfig
    { muEscapeFunc = emptyEscape
    , muTemplateFileDir = Nothing
    , muTemplateFileExt = Just templateExt
    , muTemplateRead = \file -> return $ maybe (error $ "Template not found: " ++ file) Just $ Map.lookup file templates
    }

-- TODO return Map
-- TODO use schemaNodes
generateJava :: [FileDesc] -> [Word8] -> Map.Map Word64 [Word8] -> IO [(FilePath, LZ.ByteString)]
generateJava files _ _ = do
    outputs <- bar $ map foo $ concat $ map fileContexts files
    return $ map (\(name, output) -> (name ++ ".java", output)) outputs where
        bar (x:xs) = do
            y <- x
            ys <- bar xs
            return $ y : ys
        bar [] = return []
        foo (name, contents) = do
            output <- hastacheStr hastacheConfig (encodeStr srcTemplate) contents
            return (name, output)
