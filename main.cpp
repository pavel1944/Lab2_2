#include "Header.h"

int main() 
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	ifstream fileStream("text.txt");
	string str, res;
	int i, j, max, cnt;
	max = i = j = cnt = 0;
	while (!fileStream.eof()) {
		getline(fileStream, str);
		for (i = 0; i < str.length(); i++) {
			if (ispunct(str[i]))
				j++;
			if (j >= max) {
				max = j;
				res = str;
			}
		}
		j = 0;
	}
	fileStream.seekg(0, ios_base::beg);
	while (!fileStream.eof()) {
		getline(fileStream, str);
		for (i = 0; i < str.length(); i++) {
			if (ispunct(str[i]))
				j++;
			if (j == max) {
				res = str;
				cout << res << endl;
			}
		}
		j = 0;
	}
}