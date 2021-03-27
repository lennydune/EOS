#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <typeinfo>
using namespace std;

string rotateString(string words, int rot) {
	vector<char> vect(words.begin(), words.end());
	string rotWords = "";
	while (rot) {
		vect.push_back(vect[0]);
		vect.erase(vect.begin());
		rot--;
	}
	for (char c : vect) {
		rotWords += c;
	}
	return rotWords;
}

void printHelp() {
	cout << "Usage: ./1.0 [OPTION]...\n";
	cout << "Rotates or counts the characters in the given string.\n\n";
	cout << "Without -i, read standard input.\n\n";
	cout << "  -i\tstring to rotate or count characters.\n";
	cout << "  -r{X}\trotate the string X times.\n";
	cout << "  -c\tcount the characters in the string.\n";
	cout << "  -h\tdisplay this help.\n\n";
	cout << "Examples:\n";
	cout << "  ./1.0 -i \"Hello world\" -c\toutputs the amount of characters of \"Hello world\", which are 11.\n";
	cout << "  ./1.0 -r 5\trotates the string read from standard input 5 positions.\n";
}

int main(int argc, char* argv[]) {
	char opt;
	string input = "";
	bool I = true;
	while ((opt = getopt(argc,argv,":i:r:ch?")) != -1) {
		if (opt == 'h' || opt == '?') {
			printHelp();
			break;
		}
		if (opt == 'i') {
			I = false;
			input = optarg;
		}
		if (I) {
			// dit als mensen echo gebruiken met een pipe
			// of wanneer ze de -i vergeten
			getline(cin, input);
		}
		switch(opt) {
			case 'c':
				cout << input.size() << endl;
				break;
			case 'r':
				cout << rotateString(input, atoi(optarg)) << endl;
				break;
		}
	}
}