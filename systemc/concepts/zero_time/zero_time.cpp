#include <systemc.h>

SC_MODULE(missing_event) {
	SC_CTOR(missing_event) {
		SC_THREAD(B_thread); // ordered to cause
		SC_THREAD(A_thread); // problems
		SC_THREAD(C_thread);	// a_event is missed by C_thread because of the ordering of the threads
								// If was shift this declarration above then the problem will be solved
	}
	void A_thread() {
		cout << "@" << sc_time_stamp() << " Inside A_thread!" << endl;
		a_event.notify(); // immediate!
		cout << "@" << sc_time_stamp() << " A sent a_event!" << endl;
	}
	void B_thread() {
		cout << "@" << sc_time_stamp() << " Inside B_thread!" << endl;
		wait(a_event);
		cout << "@" << sc_time_stamp() << " B got a_event!" << endl;\
		//b_event.notify(); // immediate!
		//cout << "@" << sc_time_stamp() << " B sent b_event!" << endl;
	}
	void C_thread() {
		cout << "@" << sc_time_stamp() << " Inside C_thread!" << endl;
		wait(a_event);
		cout << "@" << sc_time_stamp() << " C got a_event!" << endl;
	}
	
	sc_event a_event;
	sc_event b_event;
};

int sc_main (int argc, char* argv[]) {
  
  missing_event object("events");
  sc_start(20,SC_NS);  // Run the simulation till sc_stop is encountered
  
  return 0;// Terminate simulation
}