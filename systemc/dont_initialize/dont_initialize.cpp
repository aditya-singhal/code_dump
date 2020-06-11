#include "systemc.h"

SC_MODULE (tff_sync_reset) {
  sc_in    <bool> data, clk, reset  ;
  sc_out   <bool> q;

  bool q_l ;

  void tff () {
    if (reset.read()) {
      q_l = 0;
    } else if (data.read()) {
      q_l = !q_l;
    }
    q.write(q_l);
  }

  SC_CTOR(tff_sync_reset) {
    SC_METHOD (tff);
      dont_initialize();
      sensitive << clk.pos();
  }

};

SC_MODULE (tff_tb) {
  sc_in<bool> clk;
 
  sc_signal <bool> data, reset  ;
  sc_signal <bool> q;
  tff_sync_reset *dut;

  void do_test() {
    cout << "@" << sc_time_stamp() <<" Starting test"<<endl;
    wait();
    cout << "@" << sc_time_stamp() <<" Asserting reset"<<endl;
    reset = true; 
    wait(4);
    cout << "@" << sc_time_stamp() <<" De-Asserting reset"<<endl;
    reset = false; 
    wait(3);
    cout << "@" << sc_time_stamp() <<" Asserting Data input"<<endl;
    data = true; 
    wait(3);
    data = false; 
    cout << "@" << sc_time_stamp() <<" De-Asserting Data input"<<endl;
    wait(3);
    cout << "@" << sc_time_stamp() <<" Terminating simulation"<<endl;
    sc_stop();
  }

  SC_CTOR(tff_tb) {
    dut = new tff_sync_reset ("TFF");
    dut->clk    (clk);
    dut->reset  (reset);
    dut->data   (data);
    dut->q      (q);
    SC_THREAD (do_test);
      dont_initialize();
      sensitive << clk.pos();
  }
};

int sc_main (int argc, char* argv[]) {
  sc_clock clock ("my_clock",1,0.5);

  tff_tb  object("TFF_TB");
  object.clk (clock);

  //sc_start(0);
  sc_start();
  return 0;// Terminate simulation
}
