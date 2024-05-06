#ifndef DRIVER_H
#define DRIVER_H

#include "systemc.h"

SC_MODULE(Driver) {
public:
    sc_out<bool> en;
    sc_out<sc_uint> sel;
    sc_clock clk;

    Driver(sc_module_name name, sc_time period) : sc_module(name), clk("clk", period) {
        SC_CTOR(Driver);
        SC_THREAD(driverProcess);
    }

private:
    void driverProcess() {
        while (true) {
            en.write(1); // Enable the decoder initially
            sel.write(0);  // Start with all outputs low
            wait();

            for (int i = 0; i < 4; i++) {
                sel.write(i);
                wait();
            }

            en.write(0); // Disable the decoder after iterating through all combinations
            wait();
        }
    }

    SC_HAS_PROCESS(Driver);
};

#endif
