export SYSTEMC_HOME=/usr/local/systemc-2.3.3/



g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o hello hello.cpp -lsystemc -lm

or   

g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux -Wl,-rpath=$SYSTEMC_HOME/lib-linux -o hello hello.cpp -lsystemc -lm


./hello


gtkwave traces.vcd
