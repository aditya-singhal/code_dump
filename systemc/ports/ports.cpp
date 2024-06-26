#include <systemc.h>

SC_MODULE(ports_access) {
  sc_in<sc_bit> a;  
  sc_in<sc_bit> b;  
  sc_in<bool>   en;
  sc_out<sc_lv<2> >  out;

  // Method to manipulate output
  void body () {
    cout << "@" << sc_time_stamp() <<" Inside body" << endl;
    // Ports should use read() method to read values
    if (en.read() == 1) {
      // Should use write() method of write values
      out.write(a.read() + b.read());
    }
  }
  // Method to monitor ports
  void monitor () {
    cout << "@" << sc_time_stamp() <<" a : " << a 
      << " b : " << b << " en : " << en << " out : " 
      << out.read() <<endl;
  }
  
  SC_CTOR(ports_access) {
    SC_METHOD(body);
      sensitive << a << b << en;
    SC_METHOD(monitor);
      sensitive << a << b << en << out;
  }
  
};

// Testbench to generate test vectors
int sc_main (int argc, char* argv[]) {
  sc_signal <sc_bit> a;  
  sc_signal <sc_bit> b;  
  sc_signal <bool>   en;
  sc_signal <sc_lv<2> >  out;

  sc_out <sc_lv<2> > out_port;

  ports_access prt_ac("prt_ac");
    prt_ac.a(a);
    prt_ac.b(b);
    prt_ac.en(en);
    prt_ac.out(out);
    //out_port(out);

  sc_start(0,SC_NS);
  // Open VCD file
  // sc_trace_file *wf = sc_create_vcd_trace_file("ports_access");
  //   sc_trace(wf, a, "a");
  //   sc_trace(wf, b, "b");
  //   sc_trace(wf, en, "en");
  //   sc_trace(wf, out, "out");
  // Start the testing here
  sc_start(1,SC_NS);
  a = sc_bit('0');
  b = sc_bit('0');
  en = 1;
  sc_start(1,SC_NS);
  a = sc_bit('1');
  sc_start(1,SC_NS);
  b = sc_bit('1');
  sc_start(5,SC_NS);

//  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation
}
