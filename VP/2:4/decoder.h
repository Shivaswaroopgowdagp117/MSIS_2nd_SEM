#ifndef DECODER_H
#define DECODER_H

#include "systemc.h"

SC_MODULE(Decoder) {
public:
    sc_in<bool> en;
    sc_in<sc_uint> sel;
    sc_out<sc_uint> z;

    Decoder(sc_module_name name) : sc_module(name) {
        SC_CTOR(Decoder);
    }

private:
    void process() {
        z.write(0);  // Initialize all outputs to low (inactive)

        if (en.read()) {
            switch (sel.read()) {
                case 0: z.write(0b0001); break;  // Select line 0: Output D0 high
                case 1: z.write(0b0010); break;  // Select line 1: Output D1 high
                case 2: z.write(0b0100); break;  // Select line 2: Output D2 high
                case 3: z.write(0b1000); break;  // Select line 3: Output D3 high
            }
        }
    }

    SC_HAS_PROCESS(Decoder);
};

#endif
