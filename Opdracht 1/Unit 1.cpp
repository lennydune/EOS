#include "Unit 1.hpp"
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

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
	std::string filepath = "";
	getline(std::cin, filepath);
	
	// std::ofstream file(filename);
	int fileDescriptor;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	const char *pathname = filepath.c_str();
	fileDescriptor = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);

	while(true) {
		std::string textLine;
		std::cout << ">> ";
		getline(std::cin, textLine);
		if (textLine == "<EOF>") {
			break;
		}
		// fileDescriptor << textLine << std::endl;
		textLine = textLine + '\n';
		const char *buffer = textLine.c_str();
		write(fileDescriptor, buffer, textLine.size());
	}
	// file.close();
	std::cout << "File " << filepath << " created\n";
}

void list(){
	std::cout << "LS" << std::endl;
	// system("ls -la");
	pid_t pid = fork();
	int status;
	if (pid == -1) {
		std::cerr << "Can't fork";
		exit(-1);
	}
	else if (pid == 0) {
		char * argv[] = {"ls", "-la", NULL};
		execvp("ls", argv);
	}
}

void find(){
	std::cout << "FIND" << std::endl;
	char* grepString;
	std::cout << ">> ";
	// getline(std::cin, grepString);

	// system(command.c_str());
	pid_t pid = fork();
	int status;
	if (pid == -1) {
		std::cerr << "Can't fork";
		exit(-1);
	}
	else if (pid == 0) {
		char * argv[] = {"find", "." , "|", "grep", grepString, NULL};
		execvp("find .", argv);
	}
}

void python(){
	std::cout << "PYTHON" << std::endl;
	// system("python");
	pid_t pid = fork();
	int status;
	if (pid == -1) {
		std::cerr << "Can't fork";
		exit(-1);
	}
	else if (pid == 0) {
		char * argv[] = {NULL};
		execvp("python", argv);
	}
}

void src() {
	int fd = syscall(SYS_open, "1.1.cpp", O_RDONLY, 0755);	// Gebruik de SYS_open call om een bestand te openen.
	char byte[1];											// 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
	while(syscall(SYS_read, fd, byte, 1))					// Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte;										// 	 zet de gelezen byte in "byte" zodat deze geschreven kan worden.
}