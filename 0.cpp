#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <cstdlib>
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

int main(int argc, char* argv[]) {
	char opt;
	string input = "";
	cout << "Geef een string op:\n> ";
	getline(cin, input);
	while ((opt = getopt(argc,argv,":r:c")) != -1) {
		switch(opt) {
			case 'c':
				cout << "Het aantal characters in \"" << input << "\" is " << input.size() << endl;
				break;
			case 'r':
				cout << "De rotatie van \"" << input << "\" is " << rotateString(input, atoi(optarg)) << endl;
				break;
		}
	}
}