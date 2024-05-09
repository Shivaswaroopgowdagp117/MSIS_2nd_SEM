#include "systemc.h"
#include "d_ff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
    sc_clock clk("TestClock",10,0.5,0,1);
    sc_signal<bool> d_in, q, qbar;
   

    d_ff d("d_ff");
    driver drive("driver");
    monitor mon("monitor");

    d.q(q);
    d.qbar(qbar);
    d.clk(clk);
    d.d_in(d_in);

    drive.d_in(d_in);
    drive.clk(clk);
    
    mon.q(q);
    mon.qbar(qbar);
    mon.clk(clk);
    mon.d_in(d_in);

    sc_trace_file *Tf;
    Tf = sc_create_vcd_trace_file("traces");
    sc_trace(Tf, d_in, "d_in");
    sc_trace(Tf, q, "q");
    sc_trace(Tf, clk, "clk");
    sc_trace(Tf, qbar, "qb");
    sc_start(8*10, SC_NS);
    sc_close_vcd_trace_file(Tf);
    return 0;
}
