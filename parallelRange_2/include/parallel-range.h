// This code is part of the Problem Based Benchmark Suite (PBBS)
// Copyright (c) 2011 Guy Blelloch and the PBBS team
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights (to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#ifndef __PARALLEL_RANGE__
#define __PARALLEL_RANGE__
#include <stdint.h>

#ifdef _WINDLL
#define dlltype(x) __declspec(dllexport) x __stdcall
#define dllcall(x) x __stdcall
#else
#define dlltype(x) x
#define dllcall(x) x
#endif


dlltype(void) parallelrangelite(uint32_t* ISA, uint32_t* SA, uint32_t n);
dlltype(void) parallelrangelite(uint64_t* ISA, uint64_t* SA, uint64_t n);

dlltype(int) sufcheck(const uint32_t* T, const uint32_t* SA,
	uint32_t n, bool verbose);
dlltype(int) sufcheck(const uint64_t* T, const uint64_t* SA,
	uint64_t n, bool verbose);

dlltype(int) getWorkers();
dlltype(void) setWorkers(int n);

#endif // __PARALLEL_RANGE__
