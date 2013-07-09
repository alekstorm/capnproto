// Generated code, DO NOT EDIT




  public  final class TestAllTypes implements capnproto.composite.StructFactory<TestAllTypes.Reader, TestAllTypes.Builder> {
    public static final TestAllTypes FACTORY = new TestAllTypes();

    public static final int DATA_SIZE = 1;
    public static final int POINTER_SIZE = 1;

    

    private TestAllTypes() {}

    public final Reader reader(capnproto.internal.NearContext<capnproto.internal.StructPointerTarget> context) {
      return new Reader(context);
    }

    public final Builder builder(capnproto.internal.NearContext<capnproto.internal.StructPointerTarget> context) {
      return new Builder(context);
    }

    
    public static /*final*/ class Reader implements capnproto.composite.Struct<Reader, Builder> {
      protected capnproto.internal.BaseContext<capnproto.internal.StructPointerTarget> _context;

      protected void _init(capnproto.internal.BaseContext<capnproto.internal.StructPointerTarget> context) {
        _context = context;

                  _structList_gateway = new capnproto.composite.ListGateway<capnproto.composite.StructGateway<TestAllTypes.Reader, TestAllTypes.Builder>>(new capnproto.internal.Context<capnproto.internal.ListPointerTarget>(_context.manager(), _context.segmentId(), _context.near().targetOffset() + DATA_SIZE + 0), scala.Option.<byte[]>apply(null), capnproto.composite.Formatter$.MODULE$.<TestAllTypes.Reader, TestAllTypes.Builder>structFormatter(TestAllTypes.FACTORY, TestAllTypes.DATA_SIZE, TestAllTypes.POINTER_SIZE));
              }

      public Reader(capnproto.internal.BaseContext<capnproto.internal.StructPointerTarget> context) {
        _init(context);
      }

      public Reader(capnproto.Manager manager) {
        manager.allocateSegment(DATA_SIZE + POINTER_SIZE + 1);
        _init(new capnproto.internal.NearContext<capnproto.internal.StructPointerTarget>(manager, manager.segmentCount() - 1, 0));
        _context.writeNearPointer(1, new capnproto.internal.StructPointerTarget(DATA_SIZE, POINTER_SIZE));
      }

      // TODO avoid name collisions
      public capnproto.internal.BaseContext context() { return _context; }

              // int8Field@0: Int8;  # bits[0, 8)
                              
            /*private static final*/ byte _int8Field_default = 0;
            public byte getInt8Field() { return _context.isReset() ? _int8Field_default : capnproto.internal.Segment.readInt8$extension(_context.near().segment(), _context.near().targetOffset() * 8 + 0, _int8Field_default); }
                    public byte int8Field() { return getInt8Field(); }
                              // structList@1: List(.TestAllTypes);  # ptr[0]
                          /*private final*/ capnproto.composite.ListGateway<capnproto.composite.StructGateway<TestAllTypes.Reader, TestAllTypes.Builder>> _structList_gateway;
          public capnproto.composite.ListGateway<capnproto.composite.StructGateway<TestAllTypes.Reader, TestAllTypes.Builder>> getStructList() { return _structList_gateway; }
          public capnproto.composite.ListGateway<capnproto.composite.StructGateway<TestAllTypes.Reader, TestAllTypes.Builder>> structList() { return getStructList(); }
                  }

    
    public static final class Builder extends Reader {
      @Override
      protected void _init(capnproto.internal.BaseContext<capnproto.internal.StructPointerTarget> context) {
        _context = context;

                  _structList_gateway = new capnproto.composite.ListGateway<capnproto.composite.StructGateway<TestAllTypes.Reader, TestAllTypes.Builder>>(new capnproto.internal.Context<capnproto.internal.ListPointerTarget>(_context.manager(), _context.segmentId(), _context.near().targetOffset() + DATA_SIZE + 0), scala.Option.<byte[]>apply(null), capnproto.composite.Formatter$.MODULE$.<TestAllTypes.Reader, TestAllTypes.Builder>structFormatter(TestAllTypes.FACTORY, TestAllTypes.DATA_SIZE, TestAllTypes.POINTER_SIZE));
              }

      public Builder(capnproto.internal.BaseContext<capnproto.internal.StructPointerTarget> context) { super(context); }
      public Builder(capnproto.Manager manager) {
        super(manager);
        capnproto.internal.NearContext.eraseComposite(_context.near(), capnproto.internal.NearContext.enrichStructGlue());
      }

      
      
              // int8Field@0: Int8;  # bits[0, 8)
                  public void setInt8Field(byte value) { capnproto.internal.Segment.writeInt8$extension(_context.near().segment(), _context.near().targetOffset() * 8 + 0, value, _int8Field_default); }
          // FIXME - java annotation that adds required information for setters to work from Scala
          //public void int8Field_$eq(byte value) { setInt8Field(value); }
                              // structList@1: List(.TestAllTypes);  # ptr[0]
                          /*private final*/ capnproto.composite.ListGateway<capnproto.composite.StructGateway<TestAllTypes.Reader, TestAllTypes.Builder>> _structList_gateway;
                        }

    



  }


