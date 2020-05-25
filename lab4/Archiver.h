#pragma once
#include <direct.h>
#include <string>
#include <vector>
using namespace std;
//second variant(?)
class Arch {
	//int n;
	//string* input;
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
	void archive() { //for each file
		//_mkdir("");
		FILE* main;
		fopen_s(&main, archive_name.c_str(), "wb");
		this->put_info(main);
		for (int i = 0; i < files.size(); i++) {
			FILE* in;
			fopen_s(&in, files[i].c_str(), "rb");
			rle_comp(in, main);
			fclose(in);
		}
		fclose(main);
		//begin
		//test for rle_decomp() 
		//should be deleted
		//and doesn't work
		//FILE* ind;
		//fopen_s(&ind, "file1_z.txt", "rb");
		//FILE* maind;
		//fopen_s(&maind, "file1_z_decompr.txt", "wb");
		//rle_decomp(ind, maind);
		//fclose(ind);
		//fclose(maind);
		//end
	}
	void dearchive() {
		vector<string> sizes;
		FILE* ar;
		fopen_s(&ar, archive_name.c_str(), "rb");
		char ch = fgetc(ar);
		string n_files = "";
		while (isdigit(ch)) {
			n_files += ch;
			ch = fgetc(ar);
		}
		ch = fgetc(ar);
		for (int i = 0; i < stoi(n_files); ++i) {
			files.push_back("");
			sizes.push_back("");
			while (ch != '/') {
				files[i] += ch;
				ch = fgetc(ar);
			}
			ch = fgetc(ar);
			while (ch != '/') {
				sizes[i] += ch;
				ch = fgetc(ar);
			}
			ch = fgetc(ar);
		}
		for (int i = 0; i < stoi(n_files); ++i) {
			FILE* out;
			fopen_s(&out, files[i].c_str(), "wb");
			rle_decomp(ar, out, stoi(sizes[i]));
			fclose(out);
		}
		fclose(ar);
	}
	void rle_comp(FILE*, FILE*);
	void rle_decomp(FILE* input, FILE* output, int size);
	void put_info(FILE* main);
	void get_info();
	int get_size(FILE* input);
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
	fputc('/', output);
}

inline void Arch::rle_decomp(FILE* input, FILE* output, int size)
{
	char ch, prev_ch;
	int numb_of_same = 0;
	ch = fgetc(input);
	--size;
	while (size >= 0) {
		if (48 <= ch && ch <= 57) {
			string s = "";
			while (48 <= ch && ch <= 57) {
				s += ch;
				ch = fgetc(input);
				--size;
			}
			numb_of_same = stoi(s);
			for (int i = 0; i < numb_of_same; ++i) {
				fputc(ch, output);
			}
			ch = fgetc(input);
			--size;
			numb_of_same = 0;
		}
		else {
			fputc(ch, output);
			ch = fgetc(input);
			--size;
		}
	}
}
void Arch::get_info() {

}
int Arch::get_size(FILE* input) {
	int size = 0;
	char ch, prev_ch;
	int numb_of_same;
	ch = fgetc(input);
	while (ch != EOF) {
		prev_ch = ch;
		ch = fgetc(input);
		if (ch != prev_ch) {
			++size;
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
				pch++;
				++size;
			}
			++size;
		}
	}
	return size;
}
void Arch::put_info(FILE* main) {
	string n_files = to_string(files.size());
	for (auto ch : n_files) {
		fputc(ch, main);
	}
	fputc('/', main);
	for (int i = 0; i < files.size(); i++) {
		FILE* in;
		fopen_s(&in, files[i].c_str(), "rb");
		string size = to_string(get_size(in));
		for (auto ch : files[i]) {
			fputc(ch, main);
		}
		fputc('/', main);
		for (auto ch : size) {
			fputc(ch, main);
		}
		fputc('/', main);
		fclose(in);
	}
	fputc('/', main);
	cout << "lala" << endl;
}