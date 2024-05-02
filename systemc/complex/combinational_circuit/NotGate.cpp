#include <iostream>
#define DEBUG_SYSTEMC
#include "systemc.h"
#include "NotGate.h"

#define DBG() std::cout << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << std::endl

/**************************************************
Function name: NotGate()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
NotGate::NotGate( sc_module_name name ) : sc_module(name) {
	//std::cout << "Bus constructor called\t" << this << "\n";
	DBG();
	SC_HAS_PROCESS(NotGate);
	SC_METHOD(evaluate);
	dont_initialize();
	sensitive << in;
}
	
/**************************************************
Function name: end_of_elaboration()
Description: Initialize outputs
Parameters: None
Return type: None
**************************************************/
void NotGate::end_of_elaboration( ) {
	out.write(false);
}

/**************************************************
Function name: evaluate()
Description: Drive the output
Parameters: None
Return type: None
**************************************************/
void NotGate::evaluate() {
	std::cout << "NotGate: t=" << sc_time_stamp() << ", delta=" <<	\
	sc_delta_count() << std::endl;

	out.write( !(in.read()));
}
