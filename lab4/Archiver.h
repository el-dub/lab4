#pragma once
#include <direct.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Arch {
	vector<string> files;
	string archive_name;
public:
	Arch(vector<string> f, string ar) {
		files = f;
		archive_name = ar;
	}
	Arch(string ar) {
		archive_name = ar;
	}
	void archive();
	void dearchive();
	void rle_comp(FILE*, FILE*);
	void rle_decomp(FILE* input, FILE* output, int size);
	void put_info(FILE* main);
	void get_info();
	int get_size(FILE* input);
};

