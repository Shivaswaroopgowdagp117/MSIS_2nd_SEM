#include <systemc.h>
#include "modcounter.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc,char* argv[])
{
	sc_signal<bool>rst;
	sc_signal<sc_uint<4>>count;
	sc_clock clk("clk",2,SC_NS,0.5);

	logic countr("logic");
	countr.clk(clk);
	countr.rst(rst);
	countr.count(count);

	monitor moni("monitor");
	moni.clk(clk);
	moni.rst(rst);
	moni.count(count);

	driver dri("driver");
	dri.clk(clk);
	dri.rst(rst);
	//dri.count(count);

	sc_trace_file *Tf;
	Tf=sc_create_vcd_trace_file("traces");
	sc_trace(Tf,clk,"clk");
	sc_trace(Tf,rst,"rst");
	sc_trace(Tf,count,"count");

	sc_start(40,SC_NS);
	sc_close_vcd_trace_file(Tf);

	return 0;
}


