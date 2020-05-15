#include <iostream>
#include <string>

using namespace std;

void arguments(int argc, char* argv[], char &option,string &output, string*input) {
	string s = "";

	//second param is option "--compress" or "--decompress"
	string option1 = argv[1];
	if (option1 == "--compress") option = 'c';
	else if (option1 == "--decompress") option = 'd';
	else option = '-';

	//third param is output file name
	output = argv[2];

	//to get all that is left 
	for (int i = 3; i < argc; i++) {
		input[i-3] = argv[i];
	}
}

//
//
//
//
//class Arch {
//	/*
//	поля:
//		список файлов для сжатия
//		имя выходного файла
//	методы:
//		сжать файл
//		добавить файл в архив(?)
//		перебрать все файлы(?)
//	*/
//	int n;
//	string* input;
//	string output;
//public:
//	Arch(string*in,int n, string out) {
//		input = in;
//		output = out;
//		this->n = n;
//	}
//	void archive() { //for each file
//		for (int i = 0; i < n; i++) {
//			FILE* in = fopen(input[i].c_str(), "rb");
//			FILE* compressed = rle_alg(in);
//		}
//	}
//};
//
//FILE* rle_alg(FILE* file) {
//	while (!feof(file)) {
//		int count = 1;
//
//		while (code[i] == code[i + 1] && i < code.length() - 1) {
//			count++;
//			i++;
//		}
//	}
//
//	
//	for (int i = 0; i < code.length(); i++) {
//		int count = 1;
//
//		while (code[i] == code[i + 1] && i < code.length() - 1) {
//			count++;
//			i++;
//		}
//
//}
//
///*
//	другие функции:
//		открыть файл из списка
//		открыть архив
//*/