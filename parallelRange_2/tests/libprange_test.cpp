#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include <parallel-range.h>

using namespace std;

typedef uint64_t int_t;
int main(int argc, char* args[]) {
	if (argc != 2) {
		cout << "Expected one argument (input file)."
			<< endl;	
		return -1;
	}
	setWorkers(12);
	cout << "Use " << getWorkers() << " threads" << endl;
	string text;
	{ // Read input file.
		ifstream input_file(args[1]);
		input_file.seekg(0, ios::end);   
		text.reserve(input_file.tellg());
		input_file.seekg(0, ios::beg);
		text.assign((istreambuf_iterator<char>(input_file)),
				istreambuf_iterator<char>());
	}
	int_t size = text.size();
	int_t *SA,*ISA,*textInt;
	{ // Allocate integer buffers.
		SA = new int_t[size];
		ISA = new int_t[size];
		textInt = new int_t[size];
		for (int i = 0; i < size; ++i) {
			SA[i] = i;
			textInt[i] = ISA[i] = (int_t)(text[i]); // Cannot be negative.
		}
	}
	auto start = chrono::steady_clock::now();
	parallelrangelite(ISA, SA, size);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Parallel Range Light time: " <<
		chrono::duration <double, milli> (diff).count()<< " ms" << endl;
	if (sufcheck(textInt, SA, size, true)) {
		cout << "Sufcheck failed!" << endl;
		return -1;
	}
	return 0;
}
