## Program to find sum of first N numbers



# Benchmarks


#### Multithreaded
```
$ g++ -std=c++11 -pthread thread.cpp 
$ time ./a.out 
```
##### OUTPUT

```
50000005000000
real	0m0.048s
user	0m0.136s
sys	0m0.000s
```

#### Single threaded
```
$ g++ -std=c++11 wothread.cpp 
$ time ./a.out 
```

##### OUTPUT

```
50000005000000
real	0m0.093s
user	0m0.088s
sys	0m0.004s
```