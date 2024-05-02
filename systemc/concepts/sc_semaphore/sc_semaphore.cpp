#include <systemc.h>

SC_MODULE (sc_semaphore_example) {
  sc_in<bool> clock;

  sc_semaphore   bus;
  int     cnt;

  void bus_semaphore() {
    while (true) {
      wait();
      cout << "@" << sc_time_stamp() <<" Check if semaphore is 0 " << endl;
      if (bus.get_value() == 0) {
        cout << "@" << sc_time_stamp() <<" Posting 2 to semaphore " << endl;
        bus.post();
        cout << "@" << sc_time_stamp() <<" Posting 1st time " << endl;
        bus.post();
        cout << "@" << sc_time_stamp() <<" Posting 2nd time " << endl;
        if (cnt >= 3) {
          sc_stop(); // sc_stop triggers end of simulation
        }
        cnt ++;
      }
    }
  }

  void do_read() {
    while (true) {
      wait();
      cout << "@" << sc_time_stamp() <<" Checking semaphore for intance 0"<<endl;
      // Check if semaphore is available
      if (bus.trywait() != -1) {
        cout << "@" << sc_time_stamp() <<" Got semaphore for intance 0"<<endl;
        wait(2);
      }
    }
  }

  void do_write() {
    while (true) {
      wait();
      cout << "@" << sc_time_stamp() <<" Checking semaphore for intance 1"<<endl;
      // Wait till semaphore is available
      bus.wait();
      cout << "@" << sc_time_stamp() <<" Got semaphore for intance 1"<<endl;
      wait(3);
    }
  }

  SC_CTOR(sc_semaphore_example) : bus(0){
    cnt = 0;
    SC_CTHREAD(do_read,clock.pos());
    SC_CTHREAD(do_write,clock.pos());
    SC_CTHREAD(bus_semaphore,clock.pos());
  }
}; 

int sc_main (int argc, char* argv[]) {
  sc_time period(1,SC_NS);
  sc_clock clock ("my_clock",period,0.5);

  sc_semaphore_example  object("semaphore");
    object.clock (clock);

  sc_start(0,SC_NS); // First time called will init schedular
  sc_start();  // Run the simulation till sc_stop is encountered
  return 0;// Terminate simulation
}
