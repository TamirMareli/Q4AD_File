#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iostream> 
#include <iomanip>
using namespace std;
class AD_File {
	bool checkProhibitedCharacters(const std::string& str);
protected:
	string FileName;
	tm lastUpadateTime;
public:
	AD_File();
	AD_File(string& newName);
	string getFN() { return this->FileName; }
	void setFN(string& FM)throw(const char*);
	string getTime()const;
	void setTime();
	const bool operator==(const AD_File& o) { return this->FileName ==o.FileName ? true : false; };
};