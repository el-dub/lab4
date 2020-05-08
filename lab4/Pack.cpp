#include "Pack.h"
#include <iostream>

void Pack::Compress() {
	char sym;
	for (int i = 0; i < files.size(); ++i) {
		ifstream inFile(path + files[i], ios::binary);//открытие бинарного файла для чтения
		ofstream outFile(path + archive_file_name, ios::binary);
		while (inFile.get(sym)) {
			//cout << sym;
			outFile.write(&sym, sizeof(sym));
		}
		inFile.close();
		outFile.close();
	}
}
Pack::Pack(const vector<string>& file_names, const string& p, const string& result_name) {
	files = file_names;
	path = p + "\\";
	archive_file_name = result_name;
}
void Pack::RLE() {

}