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
	vector<string> files;//����� ���� ������
	string path;//���� � ������
	string archive_file_name;//��� �����-���������� �������������
};