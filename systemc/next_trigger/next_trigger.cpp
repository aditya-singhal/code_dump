#include <systemc.h>

SC_MODULE (next_trigger_example) {
  sc_in<bool> clock;

  sc_event  e1,e2;
  int cnt;

  void do_test1() {
      cout << "@" << sc_time_stamp() <<" Inside do_test1"<<endl;

    switch (cnt) {
      case 0 : cout << "@" << sc_time_stamp() <<" Default trigger clk triggered"<<endl;
               next_trigger(e1);
               break;
      case 1 : cout << "@" << sc_time_stamp() <<" Event e1 triggered"<<endl;
               next_trigger(10, SC_NS);
               break;
      case 2 : cout << "@" << sc_time_stamp() <<" Event e1 occured or time 10ns passed"<<endl;
               next_trigger(e1 | e2);
               break;
      case 3 : cout << "@" << sc_time_stamp() <<" Event e1 or e2 triggered"<<endl;
               break;
      default :cout << "@" << sc_time_stamp() <<" Default trigger clk triggered"<<endl;
               break;
    }
    cnt ++;
  }

  void do_test2() {
    while (true) {
      cout << "@" << sc_time_stamp() <<" Inside do_test2"<<endl;
      wait(2);
      // Trigger event e1
      cout << "@" << sc_time_stamp() <<" Triggering e1"<<endl;
      e1.notify();
      wait(20);
      cout << "@" << sc_time_stamp() <<" Triggering e2"<<endl;
      e2.notify();
      cout << "@" << sc_time_stamp() <<" After Triggering e2"<<endl;
      // Wait for  2 posedge of clocks
      wait(2);
      cout << "@" << sc_time_stamp() <<" Terminating simulation"<<endl;
      sc_stop(); // sc_stop triggers end of simulation
    }
  }

  SC_CTOR(next_trigger_example) {
    cnt = 0;
    SC_METHOD(do_test1);
      sensitive << clock;
    SC_CTHREAD(do_test2,clock.pos());
  }
}; 

int sc_main (int argc, char* argv[]) {
  sc_time period(1,SC_NS);
  sc_clock clock ("my_clock",period,0.5);

  next_trigger_example  object("wait");
    object.clock (clock);

  //sc_start(1,SC_NS); // First time called will init schedular
  sc_start();  // Run the simulation till sc_stop is encountered
  return 0;// Terminate simulation
}
