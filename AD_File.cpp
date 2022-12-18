#include "AD_File.h"

bool AD_File::checkProhibitedCharacters(const std::string& str)
{
    // Check if the string contains any of the prohibited characters
    if (str.find('<') != string::npos ||
        str.find('>') != string::npos ||
        str.find('?') != string::npos ||
        str.find('*') !=string::npos ||
        str.find(':') != string::npos ||
        str.find('/') != string::npos ||
        str.find('\\',str.size() - 2) != string::npos ||
        str.find('|') != std::string::npos) {
        return true;
    }
    return false;
}

AD_File::AD_File()
{
    this->FileName = "new file";
    //this->lastUpadateTime = new tm;
    this->setTime();
}

AD_File::AD_File(string& newName)
{
    setFN(newName);
    //this->lastUpadateTime = new tm;
    this->setTime();
}

void AD_File::setFN(string& FM)throw(char*)
{

    if (checkProhibitedCharacters(FM)) 
        throw "The string contains prohibited characters.";
        this->FileName = FM;
    }

string AD_File::getTime() const
{
    char buf[80];
    //strftime(buf, sizeof(buf), "%d/%m/%Y %X", &*(lastUpadateTime));
    strftime(buf, sizeof(buf), "%d/%m/%Y %X", &lastUpadateTime);
    char* stringTime = new char[strlen(buf) + 1];
    strcpy(stringTime, buf);
    return stringTime;
}

void AD_File::setTime()
{
    time_t t1 = time(0);
    struct tm* now = localtime(&t1);
    //*(this->lastUpadateTime) = *now;
    this->lastUpadateTime = *now;
}


   


