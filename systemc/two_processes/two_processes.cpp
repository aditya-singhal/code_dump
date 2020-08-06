#include "two_processes.h"

void two_processes::wiper_thread(void) {
	while (true) {
		//wipe_left();
		std::cout << "@" << sc_time_stamp() << " Wipe left" << endl;
		wait(500,SC_MS);
		//wipe_right();
		std::cout << "@" << sc_time_stamp() << " Wipe right" << endl;
		wait(500,SC_MS);
	}//endwhile
}

void two_processes::blinker_thread(void) {
	while (true) {
		//blinker = true;
		std::cout << "@" << sc_time_stamp() << " Blink ON" << endl;
		wait(1,SC_SEC);
		std::cout << "@" << sc_time_stamp() << " Blink OFF" << endl;
		//blinker = false;
		wait(1,SC_SEC);
	}//endwhile
}

int sc_main( int argc, char* argv[]) {
	two_processes hello("hello");
	sc_start(50,SC_SEC);

	return 0;
}
