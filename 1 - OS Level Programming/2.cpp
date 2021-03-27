#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*  Note dat new-line characters ook meetellen als character
	Dit kan soms zorgen voor onverwachte output */

void shuffle(string iFile, string oFile, int shuffleInt) {
	ifstream input(iFile);
	ofstream output(oFile);

	input.seekg(0, ios::end);
	int length = input.tellg();
	input.seekg(0, ios::beg);

	char text[length];

	input.read(text, length);

	for (int j = shuffleInt; j > 0; j--) {
		for (int i = 0; i < length; i++) {
			if ((i+j) % shuffleInt == 0) {
				output << text[i];
			}
		}
	}

	input.close();
	output.close();
}

int main() {
	string inputFile = "";
	string outputFile = "";
	int shuffleInt = 0;

	cout << "Give input file: ";
	cin >> inputFile;

	cout << "Give output file: ";
	cin >> outputFile;

	cout << "Give shuffle integer: ";
	cin >> shuffleInt;

	shuffle(inputFile, outputFile, shuffleInt);
}
