#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream> 
#include <iomanip>
#include "AD_File.h"
#include "DataFile.h"
#include <sstream>
using namespace std;
class Folder :public AD_File
{
	Folder** f;
	DataFile** df;
	int fSize;
	int dfSize;
	string path;
public:
	static Folder root;
	string getFullPath()const { return this->path+'\\'+this->FileName; }
	Folder(const string& fileName, const string& path);
	Folder();
	void addFileToArray(const DataFile& df)throw(const char*);
	void addFileToArray(const Folder& nf)throw(const char*);
	//~Folder();
	Folder(const Folder& nf)throw(char*);
	Folder(const Folder& other, const string& path);
	void mkfile(const string& fileName, const string& data);
	void mkDir(const string& fileName);
	void dir()const;
	

};