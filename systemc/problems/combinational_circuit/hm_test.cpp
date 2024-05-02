#include <iostream>
#define DEBUG_SYSTEMC
#include "systemc.h"
#include "hm_test.h"

#define DBG() std::cout << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << std::endl

/**************************************************
Function name: hm_test()
Description: Constructor
Parameters: Name
Return type: None
**************************************************/
hm_test::hm_test(sc_module_name name) : sc_module(name) {
	DBG();
	SC_HAS_PROCESS(hm_test);
	SC_THREAD(test);
}

/**************************************************
Function name: end_of_elaboration()
Description: Initialize outputs
Parameters: None
Return type: None
**************************************************/
void hm_test::end_of_elaboration( ) {
	DBG();
}

/**************************************************
Function name: stimulate_n_monitor()
Description: 
Parameters: None
Return type: None
**************************************************/
void hm_test::stimulate_n_monitor(bool a, bool b, bool c, bool d) {
	out_A = a; out_B = b; out_C = c; out_D = d;
	std::cout << "@"<< sc_time_stamp() << " HM test: A: " << a << ", B: " << b 
		<< ", C:" << c << ", D:" << d << std::endl;
	wait(1, SC_NS);
	std::cout << "@" << sc_time_stamp() << " HM test: Result: " << in << std::endl;
	wait(1, SC_NS);
}

/**************************************************
Function name: test()
Description: Call stimulate_n_monitor() with various patterns
Parameters: None
Return type: None
**************************************************/
void hm_test::test() {
	stimulate_n_monitor( 0, 0, 0, 0 );
	// stimulate_n_monitor( 0, 0, 0, 1 );
	// stimulate_n_monitor( 0, 0, 1, 0 );
	// stimulate_n_monitor( 0, 0, 1, 1 );
	// stimulate_n_monitor( 0, 1, 0, 0 );
	// stimulate_n_monitor( 0, 1, 0, 1 );
	// stimulate_n_monitor( 0, 1, 1, 0 );
	// stimulate_n_monitor( 0, 1, 1, 1 );
	// stimulate_n_monitor( 1, 0, 0, 0 );
	// stimulate_n_monitor( 1, 0, 0, 1 );
	// stimulate_n_monitor( 1, 0, 1, 0 );
	// stimulate_n_monitor( 1, 0, 1, 1 );
	// stimulate_n_monitor( 1, 1, 0, 0 );
	// stimulate_n_monitor( 1, 1, 0, 1 );
	// stimulate_n_monitor( 1, 1, 1, 0 );
	// stimulate_n_monitor( 1, 1, 1, 1 );
}
