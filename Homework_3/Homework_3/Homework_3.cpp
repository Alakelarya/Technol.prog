//Сформировать новую строку из символов, общих для двух исходных строк.
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


char* new_line_char(char* result, const char* line1, const char* line2) {
	int i = 0, j = 0, k = 0;
	int symbol[256]{};

	while (line1[i] != '\0') {
		j = 0;
		while (line2[j] != '\0') {
			if (line1[i] == line2[j]) {
				symbol[(int)line1[i]] = 1;
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (line1[i] != '\0') {
		j = (int)line1[i];
		if (symbol[j] == 1 ) {
			if (result[k-1] == (char)(j)) {
				i++;
				continue;
			}
			result[k] = (char)(j);
			k++;
		}
		i++;
	}
	
	result[k] = '\0';
	return result;
}

std::string new_line_string(const std::string& line1, const std::string& line2) {

	std::string result1;
	int t, m;

	for (int i = 0; i < size(line1); i++) {
		t = line2.find(line1[i]);
		m = result1.find(line1[i]);
		if ((t >= 0) && (m < 0)) {
			result1 = result1 + line2[t];
		}
		else continue;
	}

	return result1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Cтроки в стиле С \n";
	int n, m;

	std::ifstream in("infile.txt");

	if (!in.is_open()){
		std::cerr << "Файл не может быть открыт\n";
		return 1;
	}

	while (!in.eof()) {
		in >> n;
		char* line1 = new char[n];
		in.ignore(n,'\n');
		in.getline(line1, n, '\n');
		in >> m;
		char* line2 = new char[m];
		in.ignore(m, '\n');
		in.getline(line2, m, '\n');
		char *result_char= new char [n*m];
		std::cout << "Первая строка - " << line1 << std::endl << "Вторая строка - " << line2 << std::endl;
		std::cout <<new_line_char(result_char, line1, line2) << std::endl;
		std::cout << std::endl;
		std::cout << "Cтроки типа string\n";
		std::string string1 = line1;
		std::string string2 = line2;
		std::cout << "Первая строка - " << string1 << std::endl << "Вторая строка - " << string2 << std::endl;
		std::string result_string;
		result_string = new_line_string(string1, string2);
		std::cout << result_string << std::endl;
		std::cout << std::endl;
		delete[] line1;
		delete[] line2;

	}
	in.close();
	return 0;
}