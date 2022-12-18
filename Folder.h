#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream> 
#include <iomanip>
#include "AD_File.h"
#include "DataFile.h"
using namespace std;
class Folder :public AD_File
{
	Folder** f;
	DataFile** df;
	int fSize;
	int dfSize;
	string path;
	static Folder mainF;
public:
	string getFullPath()const { return (this->path + '/' + this->AD_File::FileName); }
	Folder(const string& fileName, const string& path);
	Folder();
	void addFileToArray(const DataFile& df)throw(const char*);
	void addFileToArray(const Folder& nf)throw(const char*);
	~Folder();
	Folder(const Folder& nf)throw(char*);
};