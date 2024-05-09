#include "systemc.h"
#include "mux.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> a0;
    sc_signal<bool> a1;
    sc_signal<bool> a2;
    sc_signal<bool> a3;

    sc_signal<bool> sel0;
    sc_signal<bool> sel1;

    sc_signal<bool> out;

    mux my_mux("mux");
    driver drive("driver");
    monitor mon("monitor");

    my_mux.a0(a0);
    my_mux.a1(a1);
    my_mux.a2(a2);
    my_mux.a3(a3);

    my_mux.out(out);
    my_mux.sel0(sel0);
    my_mux.sel1(sel1);

    drive.a0(a0);
    drive.a1(a1);
    drive.a2(a2);
    drive.a3(a3);

    // drive.out(out);
    drive.sel0(sel0);
    drive.sel1(sel1);

    mon.a0(a0);
    mon.a1(a1);
    mon.a2(a2);
    mon.a3(a3);

    mon.out(out);
    mon.sel0(sel0);
    mon.sel1(sel1);

    sc_trace_file *Tf;
    Tf = sc_create_vcd_trace_file("traces");
    sc_trace(Tf, a0, "a0");
    sc_trace(Tf, a1, "a1");
    sc_trace(Tf, a2, "a2");
    sc_trace(Tf, a3, "a3");
    sc_trace(Tf, sel0, "sel0");
    sc_trace(Tf, sel1, "sel1");
    sc_trace(Tf, out, "out");
    sc_start(4*16*5, SC_NS);
    sc_close_vcd_trace_file(Tf);
    return 0;
}
