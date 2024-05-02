#define DEBUG_SYSTEMC
#include <systemc.h>
#include "hm.h"
#include "hm_test.h"

#define DBG() std::cout << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << std::endl

class test_circuit : public sc_module {
public:
	hm *hm_obj;
	hm_test *hm_test_obj;
	sc_buffer<bool> sig_A;
	sc_buffer<bool> sig_B;
	sc_buffer<bool> sig_C;
	sc_buffer<bool> sig_D;
	sc_buffer<bool> sig_in;

	test_circuit(sc_module_name name) : sc_module(name) {
		//SC_HAS_PROCESS(test_circuit);

		DBG();
	 	hm_obj = new hm("hm");
	 	hm_test_obj = new hm_test("hm_test");
	 	
	 	hm_test_obj->out_A.bind(sig_A);
	 	hm_test_obj->out_B.bind(sig_B);
	 	hm_test_obj->out_C.bind(sig_C);
	 	hm_test_obj->out_D.bind(sig_D);
	 	hm_test_obj->in.bind(sig_in);

	 	hm_obj->in_A.bind(sig_A);
	 	hm_obj->in_B.bind(sig_B);
	 	hm_obj->in_C.bind(sig_C);
	 	hm_obj->in_D.bind(sig_D);
	 	hm_obj->out.bind(sig_in);

	 	std::cout << " test_circuit done\n";
	}
};

int sc_main(int argc, char *argv[]) {
	test_circuit test_circuit_obj( "test_circuit");

	//sc_start(2,SC_NS);
	sc_start();
	return 0;
}
