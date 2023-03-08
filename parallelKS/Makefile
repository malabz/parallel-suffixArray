OPENMP = 1
LONG = 1
#GCILK = 1

include parallelDefs

# required files
SORT =  blockRadixSort.h transpose.h
OTHER = merge.h rangeMin.h
GLOBAL_REQUIRE = parallel.h sequence.h utils.h $(SORT) $(OTHER)
LOCAL_REQUIRE = 
OBJS = pks.o

include ../common/timeRequiredFiles
include MakeBench
