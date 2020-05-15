#pragma once
#include <direct.h>
//second variant(?)
class Arch {
	int n;
	string* input;
	vector<string> files;
	string output;
public:
	Arch(string* in, int n, string out) {
		input = in;
		output = out;
		this->n = n;
		files.push_back("file1.txt");
	}
	void archive() { //for each file
		//_mkdir("");
		for (int i = 0; i < n; i++) {
			FILE* in;
			fopen_s(&in, input[i].c_str(), "rb");
			FILE* main;
			string compress_file_name = input[i];
			compress_file_name.insert(input[i].length() - 4, "_z");//may be not needed(?)
			fopen_s(&main, compress_file_name.c_str(), "wb");
			sytee(in, main);
		}
	}
	void sytee(FILE* inFile, FILE* outFile);
};

void Arch::sytee(FILE* input, FILE* output) {
	char ch, prev_ch; 
	int numb_of_same;
	prev_ch = fgetc(input);
	ch = fgetc(input);

	while (ch  != EOF) {
		fputc(ch, output);
		if (ch == prev_ch) {
			numb_of_same = 0;
			while ((ch = fgetc(input)) != EOF) {
				if (ch == prev_ch) {
					numb_of_same++;
					if (numb_of_same == UCHAR_MAX) {
						fputc(numb_of_same, output);
						break;
					}
				}
				else {
					fputc(numb_of_same, output);
					fputc(ch, output);
					break;
				}
			}
		}
		prev_ch = ch;
		ch = fgetc(input);
	}
	fputc(numb_of_same, output);
}
