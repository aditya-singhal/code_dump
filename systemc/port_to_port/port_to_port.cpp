#include <systemc.h>

SC_MODULE (module_1) {
  sc_in<sc_bit> a;
 
  void funct(){
    std::cout << "@" << sc_time_stamp() << " Inside func1 " << a->read() << "\n";
  }

  SC_CTOR(module_1) {
    SC_METHOD(funct);
      sensitive << a;
  }
};

SC_MODULE (module_2) {
  sc_in<sc_bit> b;

  void funct1() {
    std::cout << "@" << sc_time_stamp() << " Inside func2 " << b->read() << "\n";
  }
  
  SC_CTOR(module_2) {
    SC_METHOD(funct1);
      sensitive << b;
  }
};

int sc_main (int argc, char* argv[]) {
  sc_signal<sc_bit> clock;
  sc_in<sc_bit> c;

  c(clock);

  module_2 mod2("mod2");
  mod2.b(c);

  module_1 mod1("mod1");
  mod1.a(mod2.b);

  clock = sc_bit('0');
  sc_start(1,SC_NS);
  clock = sc_bit('1');
  sc_start(1,SC_NS);
  clock = sc_bit('0');
  sc_start(1,SC_NS);
  clock = sc_bit('1');
  sc_start(1,SC_NS);

  return 0;// Terminate simulation
}
