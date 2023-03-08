#ifndef __SA__
#define __SA__

#include "parallel.h"

#ifdef _WINDLL
#define dlltype(x) __declspec(dllexport) x __stdcall
#define dllcall(x) x __stdcall
#else
#define dlltype(x) x
#define dllcall(x) x
#endif


dlltype(uintT*) suffixArray(unsigned char* s, uintT n);
dlltype(uintT*) LCP(unsigned char* s, uintT n);

#endif