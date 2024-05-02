#include <iostream>
#include "cell.h"
#include "debug.h"
#include <systemc.h>

/**************************************************
Function name: cell()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
cell::cell(sc_module_name name) : sc_module(name), neighbour("neighbour") {
	
	FUNC_INFO();
	SC_HAS_PROCESS(cell);
	SC_METHOD(step);
	dont_initialize();
	sensitive << clk.pos();
	//cout << "neighbour size: " << neighbour.size() << "\n";
}

/**************************************************
Function name: ~cell()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
cell::~cell(){
	FUNC_INFO();
}

/**************************************************
Function name: step()
Description: Update state based on neighbors' current state
Parameters: None
Return type: None
**************************************************/
void cell::step() {
	uint16_t neighbour_alive_count = 0;

	for (uint16_t i=0; i < neighbour.size(); i++ ){
		if( neighbour[i]->read() == true ){
			neighbour_alive_count++;
		}
	}

	if ( neighbour_alive_count < 2 ){
		state->write(false);
	} else if ((neighbour_alive_count == 3)){
		state->write(true);
	} else if (neighbour_alive_count > 3) {
		state->write(false);
	}
	//PRINT("step");
}

/**************************************************
Function name: set_neighbour_size()
Description: Update neighbour vector size
Parameters: None
Return type: None
**************************************************/
void cell::set_neighbour_size(int size){
	neighbour.init(size);
}
