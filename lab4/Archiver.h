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
			rle_comp(in, main);
			fclose(in);
			fclose(main);
		}

		//begin
		//test for rle_decomp() 
		//should be deleted
		//and doesn't work
		FILE* ind;
		fopen_s(&ind,"file1_z.txt", "rb");
		FILE* maind;
		fopen_s(&maind,"file1_z_decompr.txt" , "wb");
		rle_decomp(ind, maind);
		fclose(ind);
		fclose(maind);
		//end
	}
	void rle_comp(FILE*, FILE*);
	void rle_decomp(FILE* input, FILE* output);
};

void Arch::rle_comp(FILE* input, FILE* output) {
	char ch, prev_ch;
	int numb_of_same;
	ch = fgetc(input);
	while (ch != EOF) {
		prev_ch = ch;
		ch = fgetc(input);
		if (ch != prev_ch) {
			fputc(prev_ch, output);
		}
		else {
			numb_of_same = 1;
			while (ch == prev_ch) {
				prev_ch = ch;
				ch = fgetc(input);
				++numb_of_same;
			}
			string s = to_string(numb_of_same);
			char const* pch = s.c_str();
			while (*pch) {
				fputc(*pch++, output);
			}
			fputc(prev_ch, output);
		}
	}
}

inline void Arch::rle_decomp(FILE* input, FILE* output)//error here
{
	char ch, prev_ch;
	int numb_of_same=0;
	ch = fgetc(input);
	while (ch != EOF) {
		if (isdigit(ch)) {
			string s = "";
			while (isdigit(ch)) {
				s += ch;
				ch = fgetc(input);
			}
			numb_of_same = stoi(s);
			for (int i = 0; i < numb_of_same; ++i) {
				fputc(ch, output);
			}
			ch = fgetc(input);
			numb_of_same = 0;
		}
		else {
			fputc(ch, output);
			ch = fgetc(input);
		}
	}
}
