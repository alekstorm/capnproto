// Generated code, DO NOT EDIT

package capnproto.test.generated;



  public  final class TestSuite implements capnproto.composite.StructFactory<TestSuite.Reader, TestSuite.Builder> {
    public static final TestSuite FACTORY = new TestSuite();

    public static final int DATA_SIZE = 0;
    public static final int POINTER_SIZE = 1;

    

    private TestSuite() {}

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

                  _tests_gateway = new capnproto.composite.ListGateway<capnproto.composite.StructGateway<Test.Reader, Test.Builder>>(new capnproto.Context<capnproto.ListPointerTarget>(_context.manager(), _context.segmentId(), _context.near().targetOffset() + DATA_SIZE + 0), scala.Option.<byte[]>apply(null), capnproto.composite.Formatter$.MODULE$.<capnproto.test.generated.Test.Reader, capnproto.test.generated.Test.Builder>structFormatter(capnproto.test.generated.Test.FACTORY, capnproto.test.generated.Test.DATA_SIZE, capnproto.test.generated.Test.POINTER_SIZE));
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

              // tests@0: List(.Test);  # ptr[0]
                          /*private final*/ capnproto.composite.ListGateway<capnproto.composite.StructGateway<Test.Reader, Test.Builder>> _tests_gateway;
          public capnproto.composite.ListGateway<capnproto.composite.StructGateway<Test.Reader, Test.Builder>> getTests() { return _tests_gateway; }
          public capnproto.composite.ListGateway<capnproto.composite.StructGateway<Test.Reader, Test.Builder>> tests() { return getTests(); }
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
              // tests@0: List(.Test);  # ptr[0]
                        }

    



  }


