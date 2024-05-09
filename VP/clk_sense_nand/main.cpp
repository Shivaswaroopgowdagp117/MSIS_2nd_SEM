#include "systemc.h"
#include "clock_nand.h"
#include "driver.h"
#include "monitor.h"

int sc_main( int argc, char* argv[] ) {
sc_signal <bool> a1,b1,d1;
sc_clock clk("TestClock",20,0.5,0,1);

andgate agate("andgate");
driver drive("driver");
monitor mon("monitor");

agate.a1(a1); agate.clk(clk); agate.b1(b1);  agate.d1(d1);
drive.a1(a1); drive.clk(clk); drive.b1(b1); mon.a1(a1);
mon.b1(b1); mon.d1(d1);mon.clk(clk);

sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, a1, "a1"); 
sc_trace(Tf, b1, "b1");
sc_trace(Tf, d1, "d1");
sc_start(45,SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
