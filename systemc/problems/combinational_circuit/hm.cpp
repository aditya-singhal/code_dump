#include <iostream>
#define DEBUG_SYSTEMC
#include "systemc.h"
#include "hm.h"

#define DBG() std::cout << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << std::endl

/**************************************************
Function name: hm()
Description: Constructor, connect child instances

Parameters: None
Return type: None
**************************************************/
hm::hm (sc_module_name name) : sc_module(name), op_and("op_and", 4),
								op_or("op_or", 2), op_not("op_not", 3) {
	//std::cout << "Bus constructor called\t" << this << "\n";
	DBG();

	// (!C)
	op_not[0].in.bind(in_C);
	op_not[0].out.bind(s_out_not_C);

	// (!B)
	op_not[1].in.bind(in_B);
	op_not[1].out.bind(s_out_not_B);

	// (!D)
	op_not[2].in.bind(in_D);
	op_not[2].out.bind(s_out_not_D);

	// A.(!C)
	op_and[0].in0.bind(in_A);
	op_and[0].in1.bind(s_out_not_C);
	op_and[0].out.bind(s_out_and_ac);

	// A.(!B)
	op_and[1].in0.bind(in_A);
	op_and[1].in1.bind(s_out_not_B);
	op_and[1].out.bind(s_out_and_ab);

	// B.C
	op_and[2].in0.bind(in_B);
	op_and[2].in1.bind(in_C);
	op_and[2].out.bind(s_out_and_cb);

	// B.C.(!D)
	op_and[3].in0.bind(s_out_and_cb);
	op_and[3].in1.bind(s_out_not_D);
	op_and[3].out.bind(s_out_and_bcd);

	// A.(!B) + A.(!C)
	op_or[0].in0.bind(s_out_and_ac);
	op_or[0].in1.bind(s_out_and_ab);
	op_or[0].out.bind(s_or_and_ac_ab);

	// A.(!B) + C.(!D) + B.C.(!D)
	op_or[1].in0.bind(s_or_and_ac_ab);
	op_or[1].in1.bind(s_out_and_bcd);
	op_or[1].out.bind(out);
}
