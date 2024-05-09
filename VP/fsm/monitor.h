#include "systemc.h"

SC_MODULE(monitor)
{
  sc_in<bool> rst, in,out;
  sc_in<bool> clk;
	
void mon()
{	
while (true){
   cout << sc_time_stamp();
   cout << " rst "<<rst.read();
   cout << " clk "<<clk.read();
   cout << " in "<<in.read();
   cout << " out "<<out.read() <<endl;
      wait();    
}}

SC_CTOR(monitor)
{
SC_THREAD(mon);
sensitive << clk.pos();
}};
