#include <systemc.h>

SC_MODULE (wait_example) {
  sc_in<bool> clock;

  sc_event  e1;
  sc_event  e2;

  void do_test1() {
    while (true) {
      // Wait for posedge of clock
      cout << "@" << sc_time_stamp() <<" Inside do_test1"<<endl;
      wait(12,SC_NS);
      cout << "@" << sc_time_stamp() <<" After wait test1"<<endl;
      wait(12,SC_NS);
      // cout << "@" << sc_time_stamp() <<" Starting test"<<endl;
      // // Wait for 5 posedge of clock
      // wait(5);
      // cout << "@" << sc_time_stamp() <<" Triggering e1"<<endl;
      // // Trigger event e1
      // e1.notify(5,SC_NS);
      // // Wait for 3 NS
      // cout << "@" << sc_time_stamp() <<" Time before wait 3 ns"<<endl;
      // wait(3, SC_NS);
      // cout << "@" << sc_time_stamp() <<" Time after wait 3 ns"<<endl;
      // // Wait for event e2
      // wait(e2);
      // cout << "@" << sc_time_stamp() <<" Got Trigger e2"<<endl;
      // // Wait for posedge of clock
      // wait(30);
      // cout << "@" << sc_time_stamp() <<" Terminating Simulation"<<endl;
      // sc_stop(); // sc_stop triggers end of simulation
    }
  }

  void do_test2() {
    while (true) {
      // Wait for event e2
      cout << "@" << sc_time_stamp() <<" Inside do_test2"<<endl;
      wait(12,SC_NS);
      cout << "@" << sc_time_stamp() <<" After wait test2"<<endl;
      wait(12,SC_NS);
      //wait(e1);
      // cout << "@" << sc_time_stamp() <<" Got Trigger e1"<<endl;
      // // Wait for 3 posedge of clock
      // wait(20);
      // cout << "@" << sc_time_stamp() <<" Triggering e2"<<endl;
      // // Trigger event e2
      // e2.notify();
      // // Wait for either 20ns or event e1
      // wait(20,SC_NS,e1);
      // cout << "@" << sc_time_stamp() <<" Done waiting for 20ns or event e1"<<endl;
    }
  }

  SC_CTOR(wait_example) {
    SC_CTHREAD(do_test1,clock.pos());
    SC_CTHREAD(do_test2,clock.pos());
    // SC_THREAD(do_test1);
    // sensitive << clock.pos();
    // SC_THREAD(do_test2);
    // sensitive << clock.pos();
  }
}; 

int sc_main (int argc, char* argv[]) {
  sc_time period(5,SC_NS);
  sc_clock clock ("my_clock",period,0.5);

  wait_example  object("wait");
    object.clock (clock);

  //sc_start(0, SC_NS); // First time called will init schedular
  sc_start(period*10);  // Run the simulation till sc_stop is encountered
  return 0;// Terminate simulation
}
