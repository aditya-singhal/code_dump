#ifndef TLM_GP_EXTENSIONS_SIMPLE_EXT_H
#define TLM_GP_EXTENSIONS_SIMPLE_EXT_H

#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"
#include <systemc.h>
#include <tlm.h>

class simple_ext : public tlm::tlm_extension<simple_ext>
{
  public:
    simple_ext(): m_master_id(0), m_trans_id(0){}

    virtual tlm_extension_base* clone() const
    {
      simple_ext* obj = new simple_ext();
      obj->m_master_id = this->m_master_id;
      obj->m_trans_id = this->m_trans_id;
      return obj;
    }

    virtual void copy_from(tlm_extension_base const& other)
    {
      m_master_id = static_cast<simple_ext const&>(other).m_master_id;
      m_trans_id = static_cast<simple_ext const&>(other).m_trans_id;
    }

    unsigned int m_master_id;
    unsigned int m_trans_id;
};

#endif //TLM_GP_EXTENSIONS_SIMPLE_EXT_H
