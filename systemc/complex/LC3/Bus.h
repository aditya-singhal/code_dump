#ifndef __BUS_H__
#define __BUS_H__

#include <systemc.h>
#include <tlm.h>
#include <vector>
#include <tlm_utils/multi_passthrough_initiator_socket.h>
#include <tlm_utils/multi_passthrough_target_socket.h>

typedef struct slave_port_address_range { 
	slave_port_address_range() : low_addr(0), high_addr(0), is_range_set(false){}
	
	uint16_t low_addr;
	uint16_t high_addr;
	bool is_range_set;
}slave_port_address_range_t;

class Bus : public sc_module {
public:
	Bus( sc_module_name name, int nSlaves);
	~Bus();
 	int add_address_range( uint16_t low_addr, uint16_t high_addr, uint16_t port );
	void end_of_elaboration();
	
	tlm_utils::multi_passthrough_target_socket<Bus> master_socket;
	tlm_utils::multi_passthrough_initiator_socket<Bus> slave_socket;
	void b_transport( int id, tlm::tlm_generic_payload& trans, sc_time& delay );

private:
	std::vector<slave_port_address_range_t> addr_range;
};

#endif
