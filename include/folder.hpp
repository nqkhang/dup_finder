#ifndef FOLDER_H
#define FOLDER_H
#pragma

#include <string>
#include "Object.hpp"
#include "file.hpp"

class Folder:public Object
{
private:
std::string _subFolder = "";
public:
Folder();
~Folder();
};
#endif