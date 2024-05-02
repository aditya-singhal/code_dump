#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <systemc.h>
#include "tlm.h"
#include <vector>
#include <tlm_utils/multi_passthrough_target_socket.h>

class Memory : public sc_module {
public:

	tlm_utils::multi_passthrough_target_socket<Memory> memory_socket;

	Memory(sc_module_name name);
	~Memory();
 	bool load(char* file_name);
 	void b_transport(int id, tlm::tlm_generic_payload& trans, sc_time& delay);

private:
	std::vector<unsigned int> memory_content;
};

#endif
