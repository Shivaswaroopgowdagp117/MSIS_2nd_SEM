#include "systemc.h"
#include "driver.h"
#include "monitor.h"
#include "fsm1.h"

int sc_main(int argc, char* argv[])
{
sc_signal <bool> rst,in,out;
sc_clock clk("TestClock",10,0.5,0,1);

fsm f_sm("state_machine");
driver drive("driver");
monitor mon("monitor");
	
	f_sm.rst(rst);
	f_sm.in(in);
	f_sm.clk(clk);
	f_sm.out(out);
	
	drive.rst(rst);
	drive.in(in);
	drive.clk(clk);
	mon.rst(rst);
	mon.in(in);
	mon.out(out);
	mon.clk(clk);

//Waveform
sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");

sc_trace(Tf, rst, "rst");
sc_trace(Tf, in, "in1");
sc_trace(Tf, clk, "clk");
sc_trace(Tf, out, "out");
sc_trace(Tf, f_sm.state, "state");

sc_start(100,SC_NS);

sc_close_vcd_trace_file(Tf);

 return 0;
}
