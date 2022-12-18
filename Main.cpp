//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <iostream> 
//#include <iomanip>
//#include "AD_File.h"
//#include "DataFile.h"
//#include "Folder.h"
//using namespace std;
//
//void main() {
//	string s = "fsdc";
//	string fn1 = "fsdc";
//	string fn2 = "fsdc";
//	string d1= "fsfwefewdc";
//	string d2= "fsfwefewdc";
//	AD_File a1 = AD_File(s);
//	AD_File a2 = AD_File(fn1);
//	cout << a1.operator==(a2);
//	cout << a1.getFileName()<<endl;
//	cout << a1.getTime()<<endl;
//	cout << a2.getFileName() << endl;
//	cout << a2.getTime() << endl;
//	DataFile df1 = DataFile(fn1, d1);
//	DataFile df2 = DataFile(fn2, d2);
//	cout << df1.operator==(df2) << endl;
//	cout << df1.getSize() << endl;
//	Folder f1 = Folder("file1", "cc");
//	Folder f2 = Folder("file1", "cc");
//	f1.addFileToArray(f2);
//	f1.dir();
//
//
//}
#include <iostream>
#include "DataFile.h"
#include "Folder.h"
using namespace std;
void main() {
	Folder* root = &Folder::root;
	Folder* curr = root;
	bool quit = false; string path;
	string command, p_command;
	char echoStream[256];
	do {
		std::cout << curr->getFullPath() << ">";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> command;
		if (command == "cd") {
			try {
				cin.ignore(1);
				cin >> p_command;
				if (p_command == root->getFileName())
					curr = root;
			//	else curr = Folder::cd(p_command);
			}
			catch (const char* msg) {
				cout << msg << endl;
				quit = true;
			};
			continue;
		}
		if (command == "mkdir") {
			try {
				cin.ignore(1);
				cin >> p_command;
				curr->mkDir(p_command);
			}
			catch (const char* msg) {
				cout << msg << endl;
				quit = true;
			}
			continue;
		}
		if (command == "dir") {
			curr->dir();
			continue;
		}
		if (command == "echo") {
			cin.ignore(1);
			std::cin.getline(echoStream, 256);
			command = echoStream;
			try {
				curr->mkfile(command.substr(0, command.find('<') - 1), command.substr(command.find('<') + 2));
			}
			catch (const char* msg) {
				cout << msg << endl;
				quit = true;
			};
			continue;
		}
	} while (!quit);
	cout << "The end!" << endl;
}