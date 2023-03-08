// -*- C++ -*-

#ifndef _BENCH_GETTIME_INCLUDED
#define _BENCH_GETTIME_INCLUDED
#if 1 //defined(__linux__) || defined(__APPLE__)
#define _CALC_TIME
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <chrono>

struct timer {
  double totalTime;
  clock_t lastTime;
  double totalWeight;
  bool on;
  timer() {
    totalTime=0.0; 
    totalWeight=0.0;
    on=0; 
  }
  void clear() { totalTime=0.0; totalWeight=0.0; on=0;}
  clock_t getTime() {
    return clock();
  }
  void start () {
    on = 1;
    lastTime = getTime();
  } 
  double stop () {
    on = 0;
    double d = double(getTime()-lastTime);
    totalTime += d;
    return d;
  } 
  double stop (double weight) {
    on = 0;
    totalWeight += weight;
    double d = (getTime()-lastTime);
    totalTime += weight*d;
    return d;
  } 

  double total() {
    if (on) return (totalTime + getTime() - lastTime) / CLOCKS_PER_SEC;
    else return totalTime / CLOCKS_PER_SEC;
  }

  double next() {
    if (!on) return 0.0;
    double t = getTime();
    double td = t - lastTime;
    totalTime += td;
    lastTime = t;
    return td;
  }

  void reportT(double time) {
    std::cout << "PBBS-time: " << std::setprecision(3) << time <<  std::endl;;
  }

  void reportTime(double time) {
    reportT(time);
  }

  void reportStop(double weight, std::string str) {
    std::cout << str << " :" << weight << ": ";
    reportTime(stop(weight));
  }

  void reportTotal() {
    double to = (totalWeight > 0.0) ? total()/totalWeight : total();
    reportTime(to);
    totalTime = 0.0;
    totalWeight = 0.0;
  }

  void reportTotal(std::string str) {
    std::cout << str << " : "; 
    reportTotal();}

  void reportNext() {reportTime(next());}

  void reportNext(std::string str) {std::cout << str << " : "; reportNext();}
};

static timer _tm;
#define timeStatement(_A,_string) _tm.start();  _A; _tm.reportNext(_string);
#define startTime() _tm.start();
#define stopTime(_weight,_str) _tm.reportStop(_weight,_str);
#define reportTime(_str) _tm.reportTotal(_str);
#define nextTime(_string) _tm.reportNext(_string);
#define nextTimeN() _tm.reportT(_tm.next());
#endif

#endif // _BENCH_GETTIME_INCLUDED

