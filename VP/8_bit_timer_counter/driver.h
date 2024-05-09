#include "systemc.h"
SC_MODULE(driver)
{

       sc_bv<8> ctrl=0;
       sc_bv<8> compare=0;
       sc_bv<8> interrupt=0;
       
	sc_in<bool> clk;
	void inputs()
	{
		for (int i = 0; i < 256; i++)
		{
			ctrl=1;
			compare=50;
			interrupt=0x03;
			wait();
		}
	}

	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		sensitive << clk.pos();
	}
};
