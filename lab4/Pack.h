#pragma once
#include <vector>
#include <string>
#include <fstream>

using namespace std;
class Pack {
public:
	Pack(const vector<string>& file_names, const string& p, const string& result_name);
	void Compress();
	void RLE();
private:
	vector<string> files;//набор имен файлов
	string path;//путь к файлам
	string archive_file_name;//имя файла-результата архивирования
};