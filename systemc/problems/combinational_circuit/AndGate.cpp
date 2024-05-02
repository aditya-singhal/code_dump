#include <iostream>
#define DEBUG_SYSTEMC
#include "systemc.h"
#include "AndGate.h"

#define DBG() std::cout << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << std::endl

/**************************************************
Function name: AndGate()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
AndGate::AndGate( sc_module_name name ) : sc_module(name) {
	//std::cout << "Bus constructor called\t" << this << "\n";
	DBG();
	SC_HAS_PROCESS(AndGate);
	SC_METHOD(evaluate);
	dont_initialize();
	sensitive << in0 << in1;
}
	
/**************************************************
Function name: end_of_elaboration()
Description: Initialize outputs
Parameters: None
Return type: None
**************************************************/
void AndGate::end_of_elaboration( ) {
	out.write(false);
}

/**************************************************
Function name: evaluate()
Description: Drive the output
Parameters: None
Return type: None
**************************************************/
void AndGate::evaluate() {
	std::cout << "AndGate: t=" << sc_time_stamp() << ", delta=" <<	\
	sc_delta_count() << std::endl;

	out.write( in0.read() && in1.read() );
}
