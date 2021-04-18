#ifndef OBJECT_H
#define OBJECT_H
#pragma once

#include <string>

class Object
{
private:
    std::string _name;
    std::string _path;
    unsigned int _size;

public:
    Object();
    Object(const std::string iName,
           const std::string iPath);

    ~Object();

    std::string getName();
    void setName(const std::string iName);

    std::string getPath();
    void setPath(const std::string iPath);

    unsigned int getSize();
    void setSize(const unsigned int &iSize);
};
#endif