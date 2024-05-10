#include <systemc.h>
#include "mux.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> a,b,c,d,f,s0,s1;

	mux mux1("mux");
	driver drive("driver");
	monitor mon("monitor");

	mux1.a(a); mux1.b(b); mux1.f(f); mux1.c(c); mux1.d(d); mux1.s0(s0); mux1.s1(s1); 
	drive.a(a); drive.b(b);  drive.c(c); drive.d(d); drive.s0(s0); drive.s1(s1);
	mon.a(a); mon.b(b); mon.f(f); mon.c(c); mon.d(d); mon.s0(s0); mon.s1(s1); 
	
	// waveform

	sc_trace_file *Tf;
	Tf = sc_create_vcd_trace_file("traces");
	sc_trace(Tf, a, "a");
	sc_trace(Tf, b, "b");
	sc_trace(Tf, c, "c");
	sc_trace(Tf, d, "d");
	sc_trace(Tf, f, "f");
	sc_trace(Tf, s0, "s0");
	sc_trace(Tf, s1, "s1");
	sc_start(30, SC_NS);
	sc_close_vcd_trace_file(Tf);
	return 0; 
}
