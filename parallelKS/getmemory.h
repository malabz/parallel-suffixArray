#if defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#include <sys/resource.h>
#else
#include <Windows.h>
#include <Psapi.h>
#endif

size_t getPeakRSS() {
#if defined(__linux__) || defined(__APPLE__)
	struct rusage rusage;
	getrusage( RUSAGE_SELF, &rusage);
	return (size_t)(rusage.ru_maxrss * 1024L);
#elif defined(_WIN32) || defined(_WIN64)
	PROCESS_MEMORY_COUNTERS info;
	GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
	return (size_t)info.WorkingSetSize;
#else
	cout << "Cannot supported" << endl;
	return 0;
#endif
}
