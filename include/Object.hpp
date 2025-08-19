#ifndef OBJECT_H
#define OBJECT_H
#pragma once

#include <string>

namespace dup_finder {

class Object
{
private:
    std::string _name;  // file name
    std::string _path;  // absolute path
    unsigned int _size; // in Byte

    void updateSize();

public:
    // Object();
    Object(const std::string sObjectPath);

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
}

#endif