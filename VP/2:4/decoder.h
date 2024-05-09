#include "systemc.h"
SC_MODULE(decoder)
{
	sc_in<bool> a1;
	sc_in<bool> a2;
	sc_in<bool> en;
	
	sc_out<bool> d1;
	sc_out<bool> d2;
	sc_out<bool> d3;
	sc_out<bool> d4;
	void decoderr()
	{	
	if(en.read()){
		d1.write((a1.read()==false &&  a2.read()==false));
		d2.write((a1.read()==false &&  a2.read()==true));
		d3.write((a1.read()==true &&  a2.read()==false));
		d4.write((a1.read()==true &&  a2.read()==true));
	}
	}
	SC_CTOR(decoder)
	{
		SC_METHOD(decoderr);
		sensitive << a1 << a2 << en;
	}
};
