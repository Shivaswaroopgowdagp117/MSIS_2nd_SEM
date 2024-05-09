#include "systemc.h"
SC_MODULE(encoder)
{
	sc_in<bool> a0;
	sc_in<bool> a1;
	sc_in<bool> a2;
	sc_in<bool> a3;
	sc_in<bool> en;
	
	sc_out<sc_uint<2>> d;
	
	void encoderr()
	{	
		if(en.read()){
			if(a0.read() == 1){
				d.write(0);
			}
			if(a1.read() == 1){
				d.write(1);
			}
			if(a2.read() == 1){
				d.write(2);
			}
			if(a3.read() == 1){
				d.write(3);
			}
			//d.write((a4.read()<<3)|(a3.read()<<2)|(a2.read()<<1)|(a1.read()));
		}
	}
	SC_CTOR(encoder)
	{
		SC_METHOD(encoderr);
		sensitive << a0 << a1 << a3 << a2 << en;
	}
};
