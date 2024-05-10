#include <systemc.h>
#include "sr_ff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> s,r,q,qbar;
    sc_clock clk("clk",2,SC_NS,0.5);
    
    sr_ff sr_f("sr");
    sr_f.s(s);
    sr_f.r(r);
    sr_f.clk(clk);
    sr_f.q(q);
    sr_f.qbar(qbar);

    Driver driver("Driver");
    driver.s(s);
    driver.r(r);
    driver.clk(clk);

    Monitor monitor("Monitor");
    monitor.s(s);
    monitor.r(r);
    monitor.clk(clk);
    monitor.q(q);
    monitor.qbar(qbar);

	sc_trace_file *Tf;
	Tf=sc_create_vcd_trace_file("traces");
	sc_trace(Tf,s,"s");
	sc_trace(Tf,r,"r");
	sc_trace(Tf,clk,"clk");
	sc_trace(Tf,q,"q");
	sc_trace(Tf,qbar,"qbar");
    sc_start(45,SC_NS);
    sc_close_vcd_trace_file(Tf);

    return 0;
}

