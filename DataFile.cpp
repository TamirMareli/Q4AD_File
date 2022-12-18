#include "DataFile.h"

DataFile::DataFile(string& fileName, string& data):AD_File(fileName)
{
	this->data = data;
}

const bool DataFile::operator==(const DataFile& o)
{
	return AD_File::operator==(o) && this->data == o.data ? true : false;
}

