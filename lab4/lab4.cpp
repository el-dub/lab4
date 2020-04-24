#include <iostream>

using namespace std;

void arguments(int argc, char* argv[], char& option, string& output, string* input);

int main(int argc, char* argv[])
{
	cout << "Hello, world!" << endl;


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
		cout << "You need to run the program from cmd";
	}

}
