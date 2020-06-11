#include <systemc.h>

SC_MODULE (sc_mutex_example) {
  sc_in<bool> clock;

  sc_mutex   bus;
  int     cnt;


  void do_bus(int who) {
    cout << "@" << sc_time_stamp() <<" Bus access by instance " << who << endl;
  }

  void do_test1() {
    cout << "@" << sc_time_stamp() <<" Inside do_test1" << endl;
    while (true) {
      wait();
      cout << "@" << sc_time_stamp() <<" Checking mutex intance 0"<<endl;
      // Check if mutex is available
      if (bus.trylock() != -1) {
        cout << "@" << sc_time_stamp() <<" Got mutex for intance 0"<<endl;
        cnt ++;
        do_bus(0);
        wait(2);
        // Unlock the mutex
        bus.unlock();
      }
      if (cnt >= 3) {
        sc_stop(); // sc_stop triggers end of simulation
      }
    }
  }

  void do_test2() {
    cout << "@" << sc_time_stamp() <<" Inside do_test2" << endl;
    while (true) {
      wait();
      cout << "@" << sc_time_stamp() <<" Checking mutex intance 1"<<endl;
      // Wait till mutex is available
      bus.lock();
      cout << "@" << sc_time_stamp() <<" Got mutex for intance 1"<<endl;
      do_bus(1);
      wait(3);
      // Unlock the mutex
      bus.unlock();
      cout << "@" << sc_time_stamp() <<" mutex unlocked by intance 1"<<endl;
    }
  }

  SC_CTOR(sc_mutex_example) {
    cnt = 0;
    SC_CTHREAD(do_test1,clock.pos());
    SC_CTHREAD(do_test2,clock.pos());
  }
}; 

int sc_main (int argc, char* argv[]) {

  sc_time period(1,SC_NS);
  sc_clock clock ("my_clock",period,0.5);

  sc_mutex_example  object("wait");
    object.clock (clock);

  sc_start(0,SC_NS); // First time called will init schedular
  sc_start();  // Run the simulation till sc_stop is encountered
  
  return 0;// Terminate simulation
}
