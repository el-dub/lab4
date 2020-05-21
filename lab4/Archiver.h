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
	prev_ch = fgetc(input);
	ch = fgetc(input);
	fputc(prev_ch, output);
	while (ch  != EOF) {
		fputc(ch, output);
		if (ch == prev_ch) {
			numb_of_same = 0;
			while ((ch = fgetc(input)) != EOF) {
				if (ch == prev_ch) {
					numb_of_same++;
				}
				else {
					string s = to_string(numb_of_same);
					char const* pch = s.c_str();
					while (*pch) {
						fputc(*pch++, output);
					}
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

inline void Arch::rle_decomp(FILE* input, FILE* output)//error here
{
	char ch, prev_ch;
	int numb_of_same;
	prev_ch = fgetc(input);
	fputc(prev_ch, output);
	ch = fgetc(input);
	

	while (ch != EOF) {
		if (isdigit(ch)) {
			//error
			//needs to be the thing that reads digits like "12" (reads only something like "1")
			int numb_of_same = (int)ch;
			while (numb_of_same > 0) {
				fputc(prev_ch, output);
			}
		}
		else {
			fputc(ch, output);
			prev_ch = ch;
			ch = fgetc(input);
		}
	}
}
