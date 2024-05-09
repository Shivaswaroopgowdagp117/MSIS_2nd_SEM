#include "systemc.h"
#include "clock_fulladder.h"
#include "driver.h"
#include "monitor.h"

int sc_main( int argc, char* argv[] ) {
sc_signal <bool> a1,b1,cin,sum,carry;
sc_clock clk("TestClock",10,0.5,0,1);

fulladder fadder("fulladder");
driver drive("driver");
monitor mon("monitor");

fadder.a1(a1); fadder.clk(clk); fadder.b1(b1); fadder.cin(cin);  fadder.sum(sum);fadder.carry(carry);
drive.a1(a1); drive.clk(clk); drive.b1(b1); drive.cin(cin); mon.a1(a1);
mon.b1(b1);mon.cin(cin); mon.sum(sum);mon.carry(carry);mon.clk(clk);

sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, a1, "a1"); 
sc_trace(Tf, b1, "b1");
sc_trace(Tf, cin, "cin");
sc_trace(Tf, sum, "sum");
sc_trace(Tf, carry, "carry");
sc_trace(Tf, clk, "clk");
sc_start(175,SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
