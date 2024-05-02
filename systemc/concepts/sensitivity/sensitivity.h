#include <iostream>
#include "systemc.h"

SC_MODULE(two_processes) {
	sc_out<int> data;
	
	void sensitive_set_thread(void); 	// process
	void blinker_method(void); 			// process
	SC_CTOR(two_processes) {
		SC_THREAD(sensitive_set_thread); 	// register process
		SC_METHOD(blinker_method); 			// register process
		sensitive << data;
	}
};
