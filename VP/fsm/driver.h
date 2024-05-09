#include "systemc.h"
SC_MODULE(driver)
{
sc_out<bool>rst,in;
sc_in<bool>clk;
void inputs()
{	
rst.write(false);
in.write(true);
wait();
rst.write(true);
in.write(true);
wait();
rst.write(false);
in.write(true);
wait();
in.write(false);
wait();
in.write(true);
wait();
in.write(false);
wait();
}

SC_CTOR(driver)
{
SC_THREAD(inputs);
sensitive << clk.pos();
}
};

