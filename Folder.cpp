#pragma once
#include "Folder.h"



Folder::Folder(string& fileName, string& path):AD_File(fileName)
{
	this->path = path;
	this->fSize = 0;
	this->dfSize = 0;
	this->f = NULL;
	this->df = NULL;
}

Folder::~Folder() {
	for (int i = 0; i < this->fSize; i++) 
		delete this->f[i];
	delete[]this->f;

	for (int i = 0; i < this->dfSize; i++) 
		delete this->df[i];
	delete[] this->df;
}



void Folder::addFileToArray(const DataFile& df)throw(const char*)
{
		for (int i = 0; i < this->dfSize; i++) 
			if (this->df[i][0] == df) 
				throw "File allready exists";
		Folder temp;
		temp.df = new DataFile * [this->dfSize];
		temp.dfSize = this->dfSize;
		for (int i = 0; i < this->dfSize; i++) {
			temp.df[i]= new DataFile(*this->df[i]);
			delete this->df[i];
		}
		delete[] this->df;
		this->dfSize++;
		this->df = new DataFile * [this->dfSize];
		for (int i = 0; i < this->dfSize; i++) {
			this->df[i] = new DataFile(*temp.df[i]);
			delete temp.df[i];
		}
		delete[]temp.df;
		this->df[this->dfSize - 1] = new DataFile(df);
	
}

//void Folder::addFileToArray(const Folder& nf) {
//	for (int i = 0; i < this->fSize; i++)
//		if (this->f[i]->AD_File::FileName == nf.AD_File::FileName)
//			throw "File allready exists";
//	Folder** temp = new Folder * [this->fSize];
//	for (int i = 0; i < this->fSize; i++) {
//		temp[i]=new
//	}
//
//}
