#ifndef ANDGATE_H
#define ANDGATE_H

#include "systemc.h"

SC_MODULE(AndGate) {
public:
    sc_in<bool> a, b;
    sc_out<bool> y;

    AndGate(sc_module_name name) : sc_module(name) {
        SC_CTOR(AndGate);
    }

private:
    void process() {
        y.write(a.read() & b.read());
    }

    void end_of_simulation() {}

    SC_HAS_PROCESS(AndGate);
};

#endif
