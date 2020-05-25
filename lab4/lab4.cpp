#include <iostream>
#include "Pack.h"
#include "Archiver.h"

using namespace std;

void arguments(int argc, char* argv[], char& option, string& output, vector <string>& input);
void perform_arch(vector <string> input, string output);
void perform_dearch(string output);

int main(int argc, char* argv[])
{
	

	//vector <string> input = { "file1.txt","file2.txt" };
	//string output = "our_archive.mgzip";
	//perform_arch(input, output);
	//perform_dearch(output);

	if (argc >= 3) {
		char option;
		string output;
		vector <string> input;
		arguments(argc, argv, option, output, input);

		if (option == 'c') perform_arch(input, output);
		if (option == 'd') perform_dearch(output);
	}
	else {
		cout << "You need to run the program from cmd" << endl;		
	}
	

}








void perform_arch(vector <string> input, string output) {
	Arch ar = Arch(input, output);
	ar.archive();
	for (int i = 0; i < input.size(); i++) {
		cout <<"Compressing file "<< input[0] << "..... Done!" << endl;
	}
	cout << "Result written to " << output;
}

void perform_dearch(string output) {
	Arch dear(output);
	dear.dearchive();
}