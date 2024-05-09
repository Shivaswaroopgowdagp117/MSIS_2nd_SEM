#include "systemc.h"
#include "clock_halfadder.h"
#include "driver.h"
#include "monitor.h"

int sc_main( int argc, char* argv[] ) {
sc_signal <bool> a1,b1,sum,carry;
sc_clock clk("TestClock",20,0.5,0,1);

halfadder hadder("halfadder");
driver drive("driver");
monitor mon("monitor");

hadder.a1(a1); hadder.clk(clk); hadder.b1(b1);  hadder.sum(sum);hadder.carry(carry);
drive.a1(a1); drive.clk(clk); drive.b1(b1); mon.a1(a1);
mon.b1(b1); mon.sum(sum);mon.carry(carry);mon.clk(clk);

sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, a1, "a1"); 
sc_trace(Tf, b1, "b1");
sc_trace(Tf, sum, "sum");
sc_trace(Tf, carry, "carry");
sc_start(120,SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
