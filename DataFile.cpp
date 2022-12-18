#include "DataFile.h"

DataFile::DataFile(const string& fileName,const string& data):AD_File(fileName)
{
	this->data = data;
}

const bool DataFile::operator==(const DataFile& o)
{
	return AD_File::operator==(o)  ? true : false;
}

