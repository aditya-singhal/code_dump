#ifndef TLM_GP_EXTENSIONS_INITIATOR_H
#define TLM_GP_EXTENSIONS_INITIATOR_H

#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"
#include <systemc.h>
#include <tlm.h>
#include "simple_ext.h"

class simple_initiator: public sc_module, public tlm::tlm_bw_transport_if<>
{
  public:
    tlm::tlm_initiator_socket<32> init_socket;
    SC_HAS_PROCESS(simple_initiator);
    simple_initiator(sc_module_name nm): sc_module(nm), init_socket("init_socket")
  {
    init_socket.bind(*this);
    SC_THREAD(thread_process);
  }

    void thread_process()
    {
      tlm::tlm_generic_payload trans, trans2;
      simple_ext* ext;
      simple_ext* ext2;
      sc_time delay = SC_ZERO_TIME;

      ext = new simple_ext;
      ext2 = new simple_ext;
      ext->m_master_id = 2;
      ext->m_trans_id = 1;
      trans.set_extension(ext);
      trans.set_command(tlm::TLM_WRITE_COMMAND);
      trans.set_data_length(1);
      trans.set_byte_enable_ptr(0);
      trans.set_streaming_width(1);

      int word = 1;

      trans.set_address(1);
      trans.set_data_ptr((unsigned char*)(&word));
      trans.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

      init_socket->b_transport(trans, delay);

      if (trans.get_response_status() <= 0)
        SC_REPORT_ERROR("TLM2", trans.get_response_string().c_str());

      ext2->m_master_id = 2;
      ext2->m_trans_id = 2;
      trans2.set_extension(ext2);
      trans2.set_command(tlm::TLM_READ_COMMAND);
      trans2.set_data_length(1);
      trans2.set_byte_enable_ptr(0);
      trans2.set_streaming_width(1);

      int word_read;

      trans2.set_address(1);
      trans2.set_data_ptr((unsigned char*)(&word_read));
      trans2.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

      init_socket->b_transport(trans2, delay);

      if (trans2.get_response_status() <= 0)
        SC_REPORT_ERROR("TLM2", trans2.get_response_string().c_str());

      if ((word) == *(trans2.get_data_ptr()))
        cout << "DATA MATCHED" << endl;
      else
        cout << "DATA MISMATCH" << endl;
    }

    virtual tlm::tlm_sync_enum nb_transport_bw(
        tlm::tlm_generic_payload& trans,
        tlm::tlm_phase& phase,
        sc_core::sc_time& t) {
      return tlm::TLM_COMPLETED;                             // Dummy implementation                    
    }

    virtual void invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range)
    { }                                                      // Dummy implementation
};

#endif //TLM_GP_EXTENSIONS_INITIATOR_H
