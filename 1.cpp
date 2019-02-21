#include "1.hpp"
#include <string>
#include <iostream>
#include <fstream>

int main() {
	std::string input;
	while(true) {
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "new_file") new_file();
		if (input == "ls") list();
		if (input == "src") src();
		if (input == "find") find();
		if (input == "python") python();
		if (input == "quit" | input == "q") return 0;
		if (input == "error") return 1;
	}
}

void new_file(){
	std::cout << "NEW FILE" << std::endl;
	std::cout << "> ";
	std::string filename = "";
	getline(std::cin, filename);
	std::ofstream file(filename);
	while(true) {
		std::string textLine;
		std::cout << ">> ";
		getline(std::cin, textLine);
		if (textLine == "<EOF>") {
			break;
		}
		file << textLine << std::endl;
	}
	file.close();
	std::cout << "File " << filename << " created\n";
}

void list(){
	std::cout << "LS" << std::endl;
	system("ls -la");
}

void find(){
	std::cout << "FIND" << std::endl;
	std::string grepString = "";
	std::cout << ">> ";
	getline(std::cin, grepString);
	std::string command = "find . | grep " + grepString;
	system(command.c_str());
}

void python(){
	std::cout << "PYTHON" << std::endl;
	system("python");
}

void src() {
	int fd = syscall(SYS_open, "1.cpp", O_RDONLY, 0755);	// Gebruik de SYS_open call om een bestand te openen.
	char byte[1];											// 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
	while(syscall(SYS_read, fd, byte, 1))					// Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte;										// 	 zet de gelezen byte in "byte" zodat deze geschreven kan worden.
}