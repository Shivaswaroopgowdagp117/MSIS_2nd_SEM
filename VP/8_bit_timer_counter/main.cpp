#include "systemc.h"
#include "timer_counter.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
    sc_clock clk("TestClock",10,0.5,0,1);
       sc_bv<8> ctrl=0;
       sc_bv<8> compare=0;
       sc_bv<8> interrupt=0;
       
    timer_counter count("timer_counter");
    driver drive("driver");
    monitor mon("monitor");

    
    
   count.ctrl(ctrl);
    count.compare(compare);
   count.interrupt(interrupt);
    count.value(value);

    drive.ctrl(ctrl);
    drive.compare(compare);
    drive.interrupt(interrupt);
    
    
   mon.ctrl(ctrl);
    mon.compare(compare);
   mon.interrupt(interrupt);
    mon.value(value);

   /* sc_trace_file *Tf;
    Tf = sc_create_vcd_trace_file("traces");
    sc_trace(Tf, d_in, "d_in");
    sc_trace(Tf, q, "q");
    sc_trace(Tf, clk, "clk");
    sc_trace(Tf, qbar, "qb");
    sc_start(8*10, SC_NS);
    sc_close_vcd_trace_file(Tf); */
    return 0;
}
