#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iostream> 
#include <iomanip>
#include "AD_File.h"

class DataFile :public AD_File
{
protected:
	string data;
public:
	DataFile() :AD_File() { this->data = "Empty"; }
	DataFile(string &fileName, string& data);
	const bool operator==(const DataFile& o);
	int getSize() { return data.size(); };



};