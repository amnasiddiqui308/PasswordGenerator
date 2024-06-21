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

	do {
		cout << "Enter the length of your password: " << endl;
		cin >> length;

		if (length < 4)
			cout << "Password cannot be smaller than 4 characters. Please enter the length again." << endl;

	} while (length < 4);
	

	return length;
}

void getSpecifications(bool& upperCase, bool& lowerCase, bool& number, bool& symbol) {
	cout << "\n---Please enter the specifications that you want regarding your password---" << endl;

	do {
		cout << "\nInclude Uppercase (press 1 to include and 0 to skip)" << endl;
		cin >> upperCase;

		cout << "Include Lowercase (press 1 to include and 0 to skip)" << endl;
		cin >> lowerCase;

		cout << "Include Numbers (press 1 to include and 0 to skip)" << endl;
		cin >> number;

		cout << "Include Symbols (press 1 to include and 0 to skip)" << endl;
		cin >> symbol;

		if (!upperCase && !lowerCase && !number && !symbol)
			cout << "You need to enter atleast one specification. Please enter again." << endl;

	} while (!upperCase && !lowerCase && !number && !symbol);
}

char UpperCase(bool uc) {
	char letter = '\0';
	
	letter = rand() % (90 - 65 + 1) + 65;
	letter *= uc; // checks if user chose uppercase or not. Letter becomes zero if he didn't chose this specification.

	return letter;
}

char LowerCase(bool lc) {
	char letter = '\0';

	letter = rand() % (122 - 97 + 1) + 97;
	letter *= lc; // checks if user chose lowercase or not.

	return letter;
}

char Number(bool n) {
	char number = '\0';

	number = rand() % (57 - 48 + 1) + 48;
	number *= n; // checks if user chose number or not.

	return number;
}

char Symbol(char symbols[], bool s) {
	char symbol = rand() % 32;

	return (symbols[symbol] * s); // (*s) checks if user chose symbol or not.
}

string FisherYatesShuffle(string& password) {
	int count = password.length();

	for (int i = count - 1; i >= 0; i--) {
		int randomIndex = rand() % (i + 1);

		swap(password[i], password[randomIndex]);
	}

	return password;
}

string generatePassword(int length, bool upperCase, bool lowerCase, bool number, bool symbol, char symbols[]) {
	string password = "";
	int i = 0;
	
	while (1) {
		char value = 0;

		value = UpperCase(upperCase);
		if (value != 0) {
			password += value;
			i++;

			if (i == length)
				break;
		}

		value = LowerCase(lowerCase);
		if (value != 0) {
			password += value;
			i++;

			if (i == length)
				break;
		}

		value = Number(number);
		if (value != 0) {
			password += value;
			i++;

			if (i == length)
				break;
		}

		value = Symbol(symbols, symbol);
		if (value != 0) {
			password += value;
			i++;

			if (i == length)
				break;
		}
	}

	return password;
}

int main() {
	srand(time(0));
	int length = 0;
	bool upperCase = 0, lowerCase = 0, number = 0, symbol = 0;
	char symbols[32] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '{', '[', '}', ']', '|', '\\', ':', ';', '"', '\'', '<', ',', '>', '.', '?', '/' , '`', '~' };
	string password = "";

	length = getLength();
	getSpecifications(upperCase, lowerCase, number, symbol);
	password = generatePassword(length, upperCase, lowerCase, number, symbol, symbols);

	cout << "\nPassword: " << FisherYatesShuffle(password) << endl;
}