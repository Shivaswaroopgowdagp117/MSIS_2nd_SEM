

#include <systemc.h>

SC_MODULE(Monitor) {
    sc_in<bool> s,r,q,qbar,clk;

    void monitor_process() {
        cout << "Input A = " << s.read() << ", B = " << r.read()
             << "\tOutput = " << q.read() <<qbar.read()<< endl;
    }

    SC_CTOR(Monitor) {
        SC_METHOD(monitor_process);
        sensitive << clk.pos();
    }
};



