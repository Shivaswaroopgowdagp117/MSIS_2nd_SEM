#include <systemc.h>

SC_MODULE(sr_ff){
    sc_in<bool>s,r;
    sc_in<bool>clk;
    sc_out<bool>q,qbar;

    void compute(){
        if(s.read()==0 && r.read()==0){
            q=q;
            qbar=qbar;
        }
        else if(s.read()==0 && r.read()==1){
           q.write(0);
           qbar.write(1);
        }
        else if(s.read()==1 && r.read()==0){
           q.write(1);
           qbar.write(0);
        }
        else if(s.read()==1 && r.read()==1){
           q.write(0);
           qbar.write(0);
        }
    }
    SC_CTOR(sr_ff){
        SC_METHOD(compute);
        sensitive <<clk.pos();
    }
};
