#ifndef MONITOR_H
#define MONITOR_H

#include "systemc.h"

SC_MODULE(Monitor) {
public:
    sc_in<bool> en;
    sc_in<sc_uint> sel;
    sc_in<sc_uint> z;

    Monitor(sc_module_name name) : sc_module(name) {
        SC_CTOR(Monitor);
        SC_THREAD(monitorProcess);
    }

private:
    void monitorProcess() {
        while (true) {
            wait();
            cout << "en: " << en.read() << ", sel: " << sel.read() << ", z: " << z.read() << endl;
        }
    }

    SC_HAS_PROCESS(Monitor);
};

#endif
