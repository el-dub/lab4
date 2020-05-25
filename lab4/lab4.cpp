#include <iostream>
#include "Pack.h"
#include "Archiver.h"

using namespace std;

void arguments(int argc, char* argv[], char& option, string& output, string* input);


int main(int argc, char* argv[])
{
	
	
	/*string path = "G:\\2019 учебный год\\КПИ\\2 семестр\\Prog";
	vector<string> files = { "photo.jpg" };
	string result = "result.txt";
	Pack p1(files, path, result);
	p1.Compress();*/

	vector <string> input = { "file1.txt","file2.txt" };
	string output = "our_archive.mgzip";
	Arch ar = Arch(input, output);
	ar.archive();
	Arch dear("our_archive.mgzip");
	dear.dearchive();
	cout << "smthng";

	if (argc >= 4) {
		char option;
		string output;
		string* input = new string[argc - 3];
		arguments(argc, argv, option, output, input);
	
		//test:
		cout << "Your option is --" << option << endl;
		cout << "Output file is " << output << endl;
		cout << "Input files: ";
		for (int i = 3; i < argc; i++) {
			cout << input[i - 3] << " ";
		}
	}
	else {
		cout << "You need to run the program from cmd" << endl;		
	}
	

}
