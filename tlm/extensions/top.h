#ifndef TLM_GP_EXTENSIONS_TOP_H
#define TLM_GP_EXTENSIONS_TOP_H

#include <systemc.h>
#include "initiator.h"
#include "target.h"

class top : public sc_module
{
  public:
    simple_initiator init;
    simple_target targ;
    top(sc_module_name nm): sc_module(nm), init("init"), targ("targ")
  {
    init.init_socket(targ.targ_socket);
  }
};

#endif //TLM_GP_EXTENSIONS_TOP_H
