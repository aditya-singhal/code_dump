#include "sensitivity.h"

void two_processes::sensitive_set_thread(void) {
	while (true) {
		std::cout << "@" << sc_time_stamp() << " Value set" << endl;
		data.write(1);
		wait(1,SC_NS);
		std::cout << "@" << sc_time_stamp() << " Value clear" << endl;
		data.write(0);
		wait(1,SC_NS);
		//wait(500,SC_MS);
	}//endwhile
}

void two_processes::blinker_method(void) {
		std::cout << "@" << sc_time_stamp() << " Value: " << data.read() << endl;
}

int sc_main( int argc, char* argv[]) {
	sc_signal<int> data_signal;

	two_processes hello("hello");
	hello.data(data_signal);
	sc_start(20,SC_NS);
	//sc_start();

	return 0;
}
