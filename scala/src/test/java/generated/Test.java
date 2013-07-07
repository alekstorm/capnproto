// Generated code, DO NOT EDIT

package capnproto.test.generated;



  public  final class Test implements capnproto.composite.StructFactory<Test.Reader, Test.Builder> {
    public static final Test FACTORY = new Test();

    public static final int DATA_SIZE = 2;
    public static final int POINTER_SIZE = 4;

    

    private Test() {}

    public final Reader reader(capnproto.NearContext<capnproto.StructPointerTarget> context) {
      return new Reader(context);
    }

    public final Builder builder(capnproto.NearContext<capnproto.StructPointerTarget> context) {
      return new Builder(context);
    }

    
    public static /*final*/ class Reader implements capnproto.composite.Struct<Reader, Builder> {
      protected capnproto.BaseContext<capnproto.StructPointerTarget> _context; // should be private[capnproto]

      private void _init(capnproto.BaseContext<capnproto.StructPointerTarget> context) {
        _context = context;

                  _name_gateway = new capnproto.composite.TextGateway(new capnproto.Context<capnproto.ListPointerTarget>(_context.manager(), _context.segmentId(), _context.near().targetOffset() + DATA_SIZE + 0), scala.Option.<byte[]>apply(null));
                  _description_gateway = new capnproto.composite.TextGateway(new capnproto.Context<capnproto.ListPointerTarget>(_context.manager(), _context.segmentId(), _context.near().targetOffset() + DATA_SIZE + 1), scala.Option.<byte[]>apply(null));
              }

      public Reader(capnproto.BaseContext<capnproto.StructPointerTarget> context) {
        _init(context);
      }

      public Reader(capnproto.Manager manager) {
        manager.allocateSegment(DATA_SIZE + POINTER_SIZE + 1);
        _init(new capnproto.NearContext<capnproto.StructPointerTarget>(manager, manager.segmentCount() - 1, 0));
        _context.writeNearPointer(1, new capnproto.StructPointerTarget(DATA_SIZE, POINTER_SIZE));
      }

      // TODO avoid name collisions
      public capnproto.BaseContext context() { return _context; }

              // name@0: Text;  # ptr[0]
                          /*private final*/ capnproto.composite.TextGateway _name_gateway;
          public capnproto.composite.TextGateway getName() { return _name_gateway; }
          public capnproto.composite.TextGateway name() { return getName(); }
                      // description@1: Text;  # ptr[1]
                          /*private final*/ capnproto.composite.TextGateway _description_gateway;
          public capnproto.composite.TextGateway getDescription() { return _description_gateway; }
          public capnproto.composite.TextGateway description() { return getDescription(); }
                      // direction@2: .Test.Direction;  # bits[0, 16)
                              /*private static final*/ char _direction_default = 0;
            public capnproto.test.generated.Test.Direction getDirection() { return capnproto.test.generated.Test.Direction.values()[_context.isReset() ? _direction_default : capnproto.Segment.readEnum$extension(_context.near().segment(), _context.near().targetOffset() * 4 + 0, _direction_default)]; }
                    public capnproto.test.generated.Test.Direction direction() { return getDirection(); }
                              // id@3: UInt64;  # bits[64, 128)
                              
            /*private static final*/ long _id_default = 0L;
            public long getId() { return _context.isReset() ? _id_default : capnproto.Segment.readUInt64$extension(_context.near().segment(), _context.near().targetOffset() * 1 + 1, _id_default); }
                    public long id() { return getId(); }
                              // json@4: Object;  # ptr[2]
                              // capnp@5: Data;  # ptr[3]
                          }

    
    public static final class Builder extends Reader implements capnproto.composite.Modifiable<Reader> {
      public Builder(capnproto.BaseContext<capnproto.StructPointerTarget> context) { super(context); }
      public Builder(capnproto.Manager manager) {
        super(manager);
        capnproto.NearContext.eraseComposite(_context.near(), capnproto.NearContext.enrichStructGlue());
        /*new scala.runtime.AbstractFunction1<capnproto.BaseContext<capnproto.StructPointerTarget>, capnproto.RichContext>() {
          public capnproto.RichContext apply(capnproto.Context<capnproto.StructPointerTarget> context) { return new capnproto.RichStructContext(context); }
        });*/
      }

      // redefined here because Java can't handle trait inheritance
      public Reader reader() { return this; }

      
      
      
      // TODO capnpc should error out when input file doesn't exist
              // name@0: Text;  # ptr[0]
                      // description@1: Text;  # ptr[1]
                      // direction@2: .Test.Direction;  # bits[0, 16)
                  public void setDirection(capnproto.test.generated.Test.Direction value) { capnproto.Segment.writeEnum$extension(_context.near().segment(), _context.near().targetOffset() * 4 + 0, (char)value.ordinal(), _direction_default); }
          // FIXME - java annotation that adds required information for setters to work from Scala
          //public void direction_$eq(capnproto.test.generated.Test.Direction value) { setDirection(value); }
                      // id@3: UInt64;  # bits[64, 128)
                  public void setId(long value) { capnproto.Segment.writeUInt64$extension(_context.near().segment(), _context.near().targetOffset() * 1 + 1, value, _id_default); }
          // FIXME - java annotation that adds required information for setters to work from Scala
          //public void id_$eq(long value) { setId(value); }
                      // json@4: Object;  # ptr[2]
                      // capnp@5: Data;  # ptr[3]
                        }

    

  public enum Direction {
    
    JSON2_CAPNP, CAPNP2_JSON
    
    
  }


  }


