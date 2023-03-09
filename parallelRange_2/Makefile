PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin
INCLUDEDIR = $(PREFIX)/include
DESTDIR =

CC = gcc
CXX = g++
CPPFLAGS = -O3 -Wall -Wextra -ffast-math -funroll-loops -DNDEBUG -D__GUNC__ -fopenmp
LIBFLAGS = -shared -fPIC
LDFLAGS_DIV = -ldivsufsort
LDFLAGS_PRANGE = -lprange
INCLUDETHIS = -I ./include -Wl,--hash-style=sysv,-Bsymbolic,-rpath=./ -L .

STDF = -std=c++11

MYCFLAGS = $(STDF) $(CPPFLAGS) $(LIBFLAGS)
MYPROGFLAGS = $(STDF) $(CPPFLAGS)

INSTALL = install

PROGS = libprange_test
DLLS = libprange.so

OBJPRANGE = parallel-range.o

HEADER_PRANGE = parallel.hpp blockRadixSort.hpp parallel.hpp parutils.hpp \
                quicksort.hpp sequence.hpp timer.hpp transpose.hpp

all : $(DLLS) $(PROGS)
	@echo done.

libprange.so: $(OBJPRANGE)
	$(CXX) -shared -fPIC $(OBJPRANGE) -o $@ $(LIBFLAGS)

libprange_test: libprange.so
	$(CXX) -o $@ tests/libprange_test.cpp $(MYPROGFLAGS) $(LIBS) $(INCLUDETHIS) $(LDFLAGS_PRANGE)

parallel-range.o: lib/parallel-range.cpp
	$(CXX) -o $@ -c lib/parallel-range.cpp $(MYCFLAGS) $(LDFLAGS) $(LIBS) $(INCLUDETHIS)


clean :
	rm -f *.o *.a *.exe *~ $(PROGS) *.aps *.so

install : all
	mkdir -p $(DESTDIR)$(LIBDIR)
	chmod 755 $(DESTDIR)$(LIBDIR)
	mkdir -p $(DESTDIR)$(BINDIR)
	chmod 755 $(DESTDIR)$(BINDIR)
	chmod 755 $(SCRIPTS)
	chmod 755 $(PROGS)
	$(INSTALL) $(PROGS) $(DESTDIR)$(LIBDIR)
