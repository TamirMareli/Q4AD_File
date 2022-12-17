#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iostream> 
#include <iomanip>
#include "AD_File.h"
using namespace std;

void main() {
	string s = "fs*dc";
	AD_File a = AD_File(s);
	cout << a.getFN()<<endl;
	cout << a.getTime()<<endl;

}