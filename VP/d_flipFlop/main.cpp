#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> d,q;
	sc_clock  testclk("testclock",10,SC_NS,0.5);

	dff dff1("dff");
	driver drive("driver");
	monitor mon("monitor");

	dff1.d(d); dff1.q(q); dff1.clk(testclk); 
	drive.d(d); drive.clk(testclk); 
	mon.d(d); mon.q(q); mon.clk(testclk); 
	// waveform

	sc_trace_file *Tf;
	Tf = sc_create_vcd_trace_file("traces");
	sc_trace(Tf, d, "d");
	sc_trace(Tf, q, "q");
	sc_trace(Tf,testclk,"testclk");
	
	sc_start(30, SC_NS);
	sc_close_vcd_trace_file(Tf);
	return 0; 
}
