#include "Object.hpp"

namespace dup_finder {

// Object::Object()
// {
//     _name = "";
//     _path = "";
//     _size = 0;
// }

Object::Object(const std::string sObjectPath) {
    _name = "";
    _path = sObjectPath;
    _size = 0;
}

Object::Object(const std::string iName,
                const std::string iPath)
{
    _name = iName;
    _path = iPath;
    _size = 0;
}

Object::~Object()
{
    _size = 0;
    _name = "";
    _path = "";
}

void Object::updateSize()
{
    if (this->_path == "")
    {
        // check how to output error
        return;
    }

    return; // do nothing for now
}

std::string Object::getName()
{
    return _name;
}

void Object::setName(const std::string iName)
{
    _name = iName;
}

std::string Object::getPath()
{
    return _path;
}

void Object::setPath(const std::string iPath)
{
    _path = iPath;
}

unsigned int Object::getSize()
{
    return _size;
}

void Object::setSize(const unsigned int & iSize)
{
    _size = iSize;
}

} // namespace dup_finder