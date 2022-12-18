#include "Folder.h"

Folder::Folder(const string& fileName, const string& path):AD_File(fileName)
{
	this->df = NULL;
	this->f = NULL;
	this->dfSize = 0;
	this->fSize = 0;
	this->path = path;

}

Folder::Folder():AD_File()
{
	this->df = NULL;
	this->f = NULL;
	this->dfSize = 0;
	this->fSize = 0;
	this->path = "Empty";

}

void Folder::addFileToArray(const DataFile& df) throw(const char*)
{
	for (int i = 0; i < this->dfSize; i++)
		if (this->df[i][0] == df)
			throw "File allready exists";
	Folder temp;
	temp.df = new DataFile * [this->dfSize];
	temp.dfSize = this->dfSize;
	for (int i = 0; i < this->dfSize; i++) {
		temp.df[i] = new DataFile(*this->df[i]);
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

void Folder::addFileToArray(const Folder& nf) throw(const char*)
{
	for (int i = 0; i < this->fSize; i++)
		if (this->f[i]->FileName == nf.FileName)
			throw "File allready exists";
	Folder** temp = new Folder * [this->fSize];
	for (int i = 0; i < this->fSize; i++) 
		temp[i] = new Folder(*this->f[i]);
	delete[] this->f;
	for (int i = 0; i < this->fSize; i++) {
		this->f[i] = new Folder(*temp[i]);
		delete temp[i];
	}
	delete[] temp;
	this->fSize++;
	this->f[this->fSize - 1] = new Folder(nf);

}

Folder::~Folder()
{
	for (int i = 0; i < this->fSize; i++)
		delete this->f[i];
	delete[]this->f;

	for (int i = 0; i < this->dfSize; i++)
		delete this->df[i];
	delete[] this->df;
}

Folder::Folder(const Folder& nf)throw(const char*):AD_File(nf.FileName)
{
	this->df = nf.df;
	this->dfSize = nf.dfSize;
	this->f = nf.f;
	this->FileName = nf.FileName;
	this->fSize = nf.fSize;
	this->path = nf.path;
	throw "no copy constructor";
}

Folder::Folder(const Folder& other, const string& path)
{
	this->path = path;
	for (int i = 0; i < this->dfSize; i++)
		delete this->df[i];
	delete[] this->df;
	for (int i = 0; i < this->fSize; i++)
		delete this->f[i];
	delete[] this->f;
	this->dfSize = other.dfSize;
	this->fSize = other.fSize;
	for (int i = 0; i < this->dfSize; i++)
		addFileToArray(*other.df[i]);
	for (int i = 0; i < this->fSize; i++)
		addFileToArray(*other.f[i]);
}

void Folder::mkfile(const string& fileName, const string& data)
{
	DataFile temp = DataFile(fileName, data);
	addFileToArray(temp);
			
}

void Folder::mkDir(const string& fileName)
{
	Folder temp = Folder(fileName,this->path);
	addFileToArray(temp);
}

void Folder::dir() const
{
	cout << "Files in directory C::";
	for (int i = 0; i < this->dfSize; i++) {
		cout << this->getTime() << "  " << "<DIR>" << "  " << fixed << setprecision(2) << (float)this->df[i]->getSize() / 1000 << "KB" << "  " << this->df[i]->getFN();
	}

}

