#ifndef TLM_GP_EXTENSIONS_TARGET_H
#define TLM_GP_EXTENSIONS_TARGET_H

#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"
#include <systemc.h>
#include <tlm.h>
#include "simple_ext.h"

class simple_target: public sc_module, public tlm::tlm_fw_transport_if<>
{
  private:
    unsigned char* m_mem;

  public:
    tlm::tlm_target_socket<32> targ_socket;

    simple_target(sc_module_name nm): sc_module(nm), targ_socket("targ_socket")
  {
    targ_socket.bind(*this);
    m_mem = new unsigned char[1024];
  }

    virtual tlm::tlm_sync_enum nb_transport_fw(
        tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_core::sc_time& t) {
      return tlm::TLM_COMPLETED;                             // Dummy implementation
    }

    virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay );

    virtual bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data)
    { return false; }                                        // Dummy implementation

    virtual unsigned int transport_dbg(tlm::tlm_generic_payload& trans)
    { return 0; }                                            // Dummy implementation
};

void simple_target ::b_transport(tlm::tlm_generic_payload& trans, sc_time& delay)
{
  simple_ext* ext;
  trans.get_extension(ext);

  tlm::tlm_command cmd = trans.get_command();
  sc_dt::uint64 addr = trans.get_address();
  unsigned char* ptr = trans.get_data_ptr();
  unsigned int len = trans.get_data_length();
  unsigned char* byte = trans.get_byte_enable_ptr();
  unsigned int width = trans.get_streaming_width();

  if (cmd == tlm::TLM_WRITE_COMMAND)
  {
    if ((ext->m_master_id == 2) && (ext->m_trans_id == 1))
      memcpy(m_mem, ptr, len);
  }

  if (cmd == tlm::TLM_READ_COMMAND)
  {
    if ((ext->m_master_id == 2) && (ext->m_trans_id == 2))
      memcpy(ptr, m_mem, len);
  }

  if (addr + len > 4)
  {
    trans.set_response_status(tlm::TLM_ADDRESS_ERROR_RESPONSE);
    return;
  }
  if (byte)
  {
    trans.set_response_status(tlm::TLM_BYTE_ENABLE_ERROR_RESPONSE);
    return;
  }
  if (width != 0 && width < len)
  {
    trans.set_response_status(tlm::TLM_BURST_ERROR_RESPONSE);
    return;
  }
  trans.set_response_status(tlm::TLM_OK_RESPONSE);
}

#endif //TLM_GP_EXTENSIONS_TARGET_H
