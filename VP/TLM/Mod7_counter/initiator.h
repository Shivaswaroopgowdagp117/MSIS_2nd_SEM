#ifndef INITIATOR_H
#define INITIATOR_H

#include "systemc"
using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"


// Initiator module generating generic payload transactions

struct Initiator: sc_module
{

  //sc_out<bool>clk;
  // TLM-2 socket, defaults to 32-bits wide, base protocol
  tlm_utils::simple_initiator_socket<Initiator> socket;

  SC_CTOR(Initiator)
  : socket("socket")  // Construct and name socket
  {
    SC_THREAD(thread_process);
   // sensitive <<clk.pos();
  }

  void thread_process()
  {
    // TLM-2 generic payload transaction, reused across calls to b_transport
    tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay = sc_time(10, SC_NS);

    // Generate a random sequence of reads and writes
    for (int i = 32; i <= 96; i += 4)
    {

      tlm::tlm_command cmd = static_cast<tlm::tlm_command>(rand() % 2);
     

      // Initialize 8 out of the 10 attributes, byte_enable_length and extensions being unused
      trans->set_command( cmd );
      
      trans->set_response_status( tlm::TLM_INCOMPLETE_RESPONSE ); // Mandatory initial value

      socket->b_transport( *trans, delay );  // Blocking transport call

      // Initiator obliged to check response status and delay
        if ( trans->is_response_error() )
        SC_REPORT_ERROR("TLM-2", "Response error from b_transport");

      cout << "trans = { " << (cmd ? 'W' : 'R') << ", " << hex << i<<endl;
          

      // Realize the delay annotated onto the transport call
      wait(delay);
    }
  }

  // Internal data buffer used by initiator with generic payload
  int data;
};

#endif

