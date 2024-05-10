#include <systemc.h>

#include "mod.h"
#include "driver.h"
#include "monitor.h"


int sc_main(int argc,char *argv[])
{
sc_signal<bool>rst;
sc_signal<sc_uint<5>>counter;
sc_clock clk("clk",2,SC_NS,0.5);

mod logic("mod");
logic.clk(clk);
logic.rst(rst);
logic.counter(counter);

driver drive("driver");
drive.rst(rst);
drive.clk(clk);

monitor mon("monitor");
mon.clk(clk);
mon.rst(rst);
mon.counter(counter);

sc_trace_file *Tf;
	Tf=sc_create_vcd_trace_file("traces");
	sc_trace(Tf,clk,"clk");
	sc_trace(Tf,rst,"rst");
	sc_trace(Tf,counter,"counter");
	
    sc_start(60,SC_NS);
    sc_close_vcd_trace_file(Tf);
    
    return 0;

}
