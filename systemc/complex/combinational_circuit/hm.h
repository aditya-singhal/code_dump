#ifndef __HM_H__
#define __HM_H__

#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include <vector>

class hm : public sc_module {
public:
	sc_in<bool> in_A;
	sc_in<bool> in_B;
	sc_in<bool> in_C;
	sc_in<bool> in_D;
	sc_out<bool> out;
	sc_buffer<bool> s_out_not_C;
	sc_buffer<bool> s_out_not_B;
	sc_buffer<bool> s_out_not_D;
	sc_buffer<bool> s_out_and_ac;
	sc_buffer<bool> s_out_and_ab;
	sc_buffer<bool> s_out_and_cb;
	sc_buffer<bool> s_out_and_bcd;
	sc_buffer<bool> s_or_and_ac_ab;

	sc_vector<AndGate> op_and;
	sc_vector<OrGate> op_or;
	sc_vector<NotGate> op_not;

	hm(sc_module_name name);
};

#endif