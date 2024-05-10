

#include <systemc.h>

SC_MODULE(Driver) {
    sc_out<bool> s,r;
    sc_in<bool>clk;

    void drive_signals() {
        s.write(true);
        r.write(false);
        wait(5, SC_NS);
        s.write(false);
        r.write(true);
        wait(5, SC_NS);
        s.write(false);
        r.write(false);
        wait(5, SC_NS);
        
        s.write(true);
        r.write(true);
        wait(5, SC_NS);
        sc_stop();
    }

    SC_CTOR(Driver) {
        SC_THREAD(drive_signals);
        sensitive <<clk.pos();
    }
};



