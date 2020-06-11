#include <systemc.h>

SC_MODULE (events) {
  sc_in<bool> clock;

  sc_event  e1;
  sc_event  e2;
  sc_event  e3;

  void do_test1() {
    while (true) {
      cout<<"In do_test1"<<endl;
      // Wait for posedge of clock
      wait();
      cout << "@" << sc_time_stamp() <<" Starting test"<<endl;
      // Wait for posedge of clock
      wait();
      cout << "@" << sc_time_stamp() <<" Triggering e1"<<endl;
      // Trigger event e1
      e1.notify(5,SC_NS);
      // Wait for posedge of clock
      wait();
      cout << "@" << sc_time_stamp() <<" In do_test1"<<endl;
      // Wait for event e2
      wait(e2);
      cout << "@" << sc_time_stamp() <<" Got Trigger e2"<<endl;
      // Wait for posedge of clock
      wait();
      cout<<"Terminating Simulation"<<endl;
      //This will not make any effect since the simulation has been stopped in
      //the next instruction
      e1.notify();
      sc_stop(); // sc_stop triggers end of simulation
    }
  }

  void do_test2() {
    while (true) {
      // Wait for event e2
      cout<<"In do_test2"<<endl;
      //wait(e1);
      //cout << "@" << sc_time_stamp() <<" Got Trigger e1"<<endl;
      // Wait for 3 posedge of clock
      wait(3);
      cout << "@" << sc_time_stamp() <<" Triggering e2"<<endl;
      // Trigger event e2
      e2.notify();
    }
  }

  void func(){
  	cout << "@" << sc_time_stamp() <<" I am in func"<<endl;
  	next_trigger(e3);
  }


  SC_CTOR(events) {
    // /SC_CTHREAD(do_test1,clock.pos());
    SC_CTHREAD(do_test2,clock.pos());
    SC_METHOD(func);
    sensitive << e2;
  }
}; 

int sc_main (int argc, char* argv[]) {
  sc_time period(1,SC_NS);

  sc_clock clock ("my_clock",period,0.5);

  events  object("events");
    object.clock (clock);

  //sc_start(0,SC_NS); // First time called will init schedular
  sc_start(50,SC_NS);  // Run the simulation till sc_stop is encountered
  
  return 0;// Terminate simulation
}
