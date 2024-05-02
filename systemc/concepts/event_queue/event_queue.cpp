#include <iostream>
#include "systemc.h"

class event_test : public sc_module {
		sc_event_queue EQ;
public:
	event_test(sc_module_name name) : sc_module(name) {
		SC_HAS_PROCESS(event_test);
		SC_THREAD(T);
		SC_METHOD(M);
		sensitive << EQ;
		dont_initialize();
	}
	void T() {
		EQ.notify(2, SC_NS);
		EQ.notify(2, SC_NS);
		EQ.notify(1, SC_NS);
		EQ.notify(SC_ZERO_TIME);
		EQ.notify(1, SC_NS);
		std::cout << "@" << sc_time_stamp() << ": T method\n";
		//wait(EQ);
	}

	void M(){
		std::cout << "@" << sc_time_stamp() << ": M method\n";
	}
};


int sc_main(int argc, char* argv[]){
	event_test obj("obj");

	sc_start(10, SC_NS);
	return 0;
}
