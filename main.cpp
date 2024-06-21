#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string.h>
using namespace std;

// 1. Get length of the password
// 2. Ask for specifications
// Specification-01: Include Uppercase
// Specification-02: Include Lowercase
// Specification-03: Include Numbers
// Specification-04: Include Symbols
// 3. Generate a password according to the specifications

int getLength() {
	int length = 0;

	cout << "Enter the length of your password: " << endl;
	cin >> length;

	return length;
}

void getSpecifications(bool& upperCase, bool& lowerCase, bool& number, bool& symbol) {
	cout << "---Please enter the specifications that you want regarding your password---" << endl;

	cout << "Include Uppercase (press 1 to include and 0 to skip)" << endl;
	cin >> upperCase;

	cout << "Include Lowercase (press 1 to include and 0 to skip)" << endl;
	cin >> lowerCase;

	cout << "Include Numbers (press 1 to include and 0 to skip)" << endl;
	cin >> number;

	cout << "Include Symbols (press 1 to include and 0 to skip)" << endl;
	cin >> symbol;
}

char upperCase() {
	srand(time(0));
	char letter = '\0';

	letter = rand() % (90 - 65 + 1) + 65;

	return letter;
}

char lowerCase() {
	srand(time(0));
	char letter = '\0';

	letter = rand() % (122 - 97 + 1) + 97;

	return letter;
}

char number() {
	srand(time(0));
	char number = '\0';

	number = rand() % (57 - 48 + 1) + 48;

	return number;
}

char symbol(char symbols[]) {
	char symbol = rand() % 32;

	return symbols[symbol];
}

//string generatePassword(int length, bool upperCase, bool lowerCase, bool number, bool symbol) {
//	string password = "";
//
//
//}

int main() {
	int length = 0;
	bool upperCase = 0, lowerCase = 0, number = 0, symbol = 0;
	char symbols[32] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '{', '[', '}', ']', '|', '\\', ':', ';', '"', '\'', '<', ',', '>', '.', '?', '/' , '`', '~' };

	length = getLength();
	cout << symbols[19];
}