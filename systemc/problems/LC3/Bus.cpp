#include <fstream>
#include "Bus.h"
#include "Memory.h"
#include "debug.h"
#include <iterator>
#include <tlm_utils/multi_passthrough_initiator_socket.h>
#include <tlm_utils/multi_passthrough_target_socket.h>

#define MAX(a,b)	( (a > b) ? a : b )
#define MIN(a,b)	( (a < b) ? a : b )

inline bool is_overlap(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2){
	if ( MAX(x1,y1) <= MIN(x2,y2) ){
		return true;
	} else {
		return false;
	}
}

/**************************************************
Function name: Bus()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
Bus::Bus( sc_module_name name, int nSlaves) : sc_module(name),
											  master_socket("master_socket"),
											  slave_socket("slave_socket"),
											  addr_range(nSlaves) {
	//std::cout << "Bus constructor called\t" << this << "\n";
	FUNC_INFO();
	master_socket.register_b_transport(this, &Bus::b_transport);
}

/**************************************************
Function name: ~Bus()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
Bus::~Bus() {
	//std::cout << "Bus destructor called\t" << this << "\n";
}

/**************************************************
Function name: add_address_range()
Description: port gets associated to the address range from 'low_addr' to 'high_addr'.
			 Gets called multiple times, once for each slave.
Parameters: low_addr, high_addr, port
Return type: status
**************************************************/	
int Bus::add_address_range(uint16_t low_addr, uint16_t high_addr, uint16_t port){
	//check if value of port is greater than total slave ports 
	//return error or exception
	// if ( port > (sport.size())-1 ){
	// 	return -1;
	// }
	if (low_addr > high_addr){
		return -1;
	}
	if (this->addr_range[port].is_range_set != false){
		return -1;
	}

	this->addr_range[port].low_addr = low_addr;
	this->addr_range[port].high_addr = high_addr;
	this->addr_range[port].is_range_set = true;
	return 0;
}

/**************************************************
Function name: end_of_elaboration()
Description: Check that all slaves have an address range. Check that
			 address range doesn't overlap.Check that low_addr <= high_addr
Parameters: None
Return type: None
**************************************************/	
void Bus::end_of_elaboration() {
	bool status = false;
	FUNC_INFO();

	std::vector<slave_port_address_range_t>::iterator outer_itr;
	std::vector<slave_port_address_range_t>::iterator inner_itr;
	
	for (outer_itr = addr_range.begin(); outer_itr < addr_range.end(); outer_itr++){
		if(outer_itr->is_range_set != true){
			cout << "Address range not set\n";
			sc_stop();
		}
	}

	for (outer_itr = addr_range.begin(); outer_itr < addr_range.end(); outer_itr++){
		for (inner_itr = addr_range.begin(); inner_itr < addr_range.end(); inner_itr++) {
			if ( outer_itr == inner_itr){
				break;
			} else {
				status = is_overlap(inner_itr->low_addr, inner_itr->high_addr,
					outer_itr->low_addr, outer_itr->high_addr);
				if (status == true){
					cout << "Address range overlap\n";
					sc_stop();
				}
			}
		}
	}

}

void Bus::b_transport( int id, tlm::tlm_generic_payload& trans,
					   sc_time& delay ){
	//Call forward to memory
	//FUNC_INFO();
	int port_number = 0;
	bool is_addr_mapped = false;
	std::vector<slave_port_address_range_t>::iterator itr;
	uint64_t addr = trans.get_address();

	for (itr = addr_range.begin(); itr < addr_range.end(); itr++){
		if ( ( addr >= itr->low_addr) && ( addr <= itr->high_addr) ) {
			is_addr_mapped = true;
			break;
		} else {
			port_number++;
		}
	}

	if ( is_addr_mapped == false ){
		cout << "Bus error\n";
		while(1);	//should be handled by caller 
	}

	//cout << "Port number: " << port_number << "  "<< addr << "\n";
	slave_socket[port_number]->b_transport( trans, delay );
}
