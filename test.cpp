 #include <iostream>
#include "func.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

void printHelp() {
	cout << "Program working with string" << endl;
	cout << "Function:" << endl;
	cout << "cut, join, swap" << endl;
	cout << "Using this command: test - o join | cut | swap -f file" << endl;
}

void printError() {
	cout << "ERROR\n";
	printHelp();
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	int op;
	int l;
	int iter = 0;
	string file_name;
	fstream file;
	string stroka1;
	string stroka2;
	int rs;
	opterr = 0;
	while ((rs = getopt(argc, argv, ":o:f:l:h")) != -1) {
		switch (rs)
		{
		case 'h':
			printHelp();
			break;
		case 'o':
			if (strcmp(optarg, "swap") == 0) op = 1;
			if (strcmp(optarg, "join") == 0) op = 2;
			if (strcmp(optarg, "cut") == 0) op = 3;
			if (op == 0) {
				//printError();
			}
			//cout << "TAG -o " << op<<endl;
			break;
		case 'f':
			file_name = optarg;
			file.open(file_name);
			cout << "File name is:" << optarg<<endl;

			while (file) {
				string strok;
				getline(file, strok);
				if (iter == 0) {
					stroka1 = strok;
					iter++;
				}
				else {
					stroka2 = strok;
					iter = 0;
					break;
				}
			}
			cout << "First string is:" << stroka1 << endl;
			cout << "Second string in file is:" << stroka2 << endl;
			if (op == 3) {
				l = atoi(stroka2.c_str());
			}
			cout << endl;
			break;
		default:
			printError();
			exit(EXIT_FAILURE);
			break;
		};
	};
	switch (op)
	{
	case 1:
		cout << "Swap string is " << '"'<< reverseWords(stroka1)<<'"' << endl;
		break;
	case 2:
		cout << "Two joinned string is " << '"' << join(stroka1, stroka2) << '"' << endl;
		break;
	case 3:
		cout << "Cut word: " << '"' << cut(stroka1, l) << '"' << endl;
		break;
	default:
		//printError();
		exit(EXIT_FAILURE);
	}
}