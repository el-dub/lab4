#include <iostream>
#include <string>
#include <vector>
using namespace std;

void arguments(int argc, char* argv[], char &option,string &output, vector <string>& input) {
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
		input.push_back(argv[i]);
	}
}







