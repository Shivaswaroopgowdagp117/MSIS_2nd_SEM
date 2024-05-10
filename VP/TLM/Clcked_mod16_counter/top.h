//#ifndef TOP_H
#define TOP_H

#include "initiator.h"
#include "first_counter1.h"

SC_MODULE(Top)
{
  Initiator *initiator;
  first_counter  *counter;

  SC_CTOR(Top)
  {
    // Instantiate components
    initiator = new Initiator("initiator");
    counter   = new first_counter("counter");

    // One initiator is bound directly to one target with no intervening bus

    // Bind initiator socket to target socket
    initiator->socket.bind(counter->socket );
  }
};

