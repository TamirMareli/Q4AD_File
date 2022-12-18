#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream> 
#include <iomanip>
#include "AD_File.h"
#include "DataFile.h"
using namespace std;

class Folder :public AD_File, public DataFile {
	Folder** f;
	DataFile** df;
	int fSize;
	int dfSize;
	string path;
	static Folder sf;
public:
	~Folder();
	Folder(const Folder& nf);
	Folder() :AD_File(), DataFile() { this->f = NULL; this->df = NULL; this->fSize = 0; this->dfSize = 0; }
	const string& getFullPath(){ return (this->path + '/' + this->AD_File::FileName); }
	const bool operator==(const DataFile& f)throw(char*);
	void addFileToArray(const DataFile &df)throw(const char*);
	void addFileToArray(const Folder& nf);
	Folder(string& fileName, string& path);


};