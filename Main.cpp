#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iostream> 
#include <iomanip>
#include "AD_File.h"
#include "DataFile.h"
#include "Folder.h"
using namespace std;

void main() {
	string s = "fsdc";
	string fn1 = "fsdc";
	string fn2 = "fsdc";
	string d1= "fsfwefewdc";
	string d2= "fsfwefewdc";
	AD_File a1 = AD_File(s);
	AD_File a2 = AD_File(fn1);
	cout << a1.operator==(a2);
	cout << a1.getFN()<<endl;
	cout << a1.getTime()<<endl;
	cout << a2.getFN() << endl;
	cout << a2.getTime() << endl;
	DataFile df1 = DataFile(fn1, d1);
	DataFile df2 = DataFile(fn2, d2);
	cout << df1.operator==(df2) << endl;
	cout << df1.getSize() << endl;


}