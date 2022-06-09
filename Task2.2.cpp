#include <iostream>
#include <conio.h>

const int CHAR_LIMIT = 1000;

char* scanstr(char* str);
int len(char* str);
void copy(char* src, char* dest);
bool insert(char* str, char symb, int pos);
void check_ws(char* txt);
void printstr(char* txt);
int find_max(char* txt);

int main() {
	char* txt = new char[CHAR_LIMIT];

	std::cout << "Enter your text without new line:" << std::endl << std::endl;

	txt = scanstr(txt);

	check_ws(txt);

	std::cout << "Your fixed text:" << std::endl << std::endl;

	printstr(txt);
	std::cout << std::endl << "Max size: " << find_max(txt);

	delete[] txt;

	return 0;
}

int find_max(char* txt) {
	int prev_len = 0;
	int max_len = 0;
	int i = 0;

	while (txt[i] != '\0') {
		if (txt[i] == '.' && txt[i + 1] == ' ') {
			if (prev_len > max_len) {
				max_len = prev_len;
				prev_len = -1;
				i++;
				continue;
			}
			prev_len = -1;
		}

		prev_len++;
		i++;
	}

	return max_len;
}

void printstr(char* txt) {
	int i = 0;

	while (txt[i] != '\0') {
		std::cout << txt[i];
		i++;
	}
}

void check_ws(char* txt) {
	int i = 0;

	while (txt[i] != '\0') {
		if (txt[i] == '.' && txt[i] != ' ')
			insert(txt, ' ', i + 1);

		i++;
	}
}

char* scanstr(char* str) {
	std::cin.getline(str, CHAR_LIMIT);

	return str;
}


int len(char* str) {
	int len = 0;
	int i = 0;

	while (str[i] != '\0') {
		i++;
		len++;
	}

	return len;
}

bool insert(char* str, char symb, int pos) {
	int length = len(str);
	if (pos > length || pos < 0)
		return false;
	else {
		char* temp = new char[length - pos + 1];

		copy(str + pos, temp);

		str[pos] = symb;

		copy(temp, str + pos + 1);

		delete[] temp;

		return true;
	}
}

void copy(char* src, char* dest) {
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}