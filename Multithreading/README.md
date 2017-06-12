# Benchmarks

g++ -std=c++11 -pthread thread.cpp 
time ./a.out 

50000005000000
real	0m0.048s
user	0m0.136s
sys	0m0.000s

g++ -std=c++11 wothread.cpp 
time ./a.out 
50000005000000
real	0m0.093s
user	0m0.088s
sys	0m0.004s
