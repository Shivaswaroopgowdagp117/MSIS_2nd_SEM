#include "systemc.h"
#include "encoder.h"
#include "driver.h"
#include "monitor.h"

int sc_main( int argc, char* argv[] ) {
sc_signal <bool> a0,a1,a2,a3,en;
sc_signal<sc_uint<2>> d;

encoder encode("encoder");
driver drive("driver");
monitor mon("monitor");

encode.a0(a0);encode.a1(a1); encode.a2(a2);encode.a3(a3); encode.en(en); encode.d(d);
drive.a0(a0); drive.a1(a1); drive.a2(a2); drive.a3(a3); drive.en(en); 
mon.a0(a0);mon.a1(a1);mon.a2(a2);mon.a3(a3); mon.d(d);mon.en(en);

sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, a0, "a0"); 
sc_trace(Tf, a1, "a1"); 
sc_trace(Tf, a2, "a2"); 
sc_trace(Tf, a3, "a3"); 
sc_trace(Tf, en, "en"); 
sc_trace(Tf, d, "d");
sc_start(50,SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
