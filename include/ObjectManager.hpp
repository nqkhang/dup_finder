#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#pragma once

#include <vector>
#include <string>
#include <map>

#include "Object.hpp"
// #include <Object.hpp>

using VecVecStr = std::vector<std::vector<std::string>>;
using VecStr = std::vector<std::string>;

namespace dup_finder {

class ObjectManager {
private:
    std::map< int , std::vector<std::string> > mGroupBySize; // size in Byte ; all files have the same size

    std::string mPathToAnalyze;

    void analyzePath();
    void getListOfFileFrom(const std::string sPath, VecStr& fileList);
    int getFileSize(const std::string sFile);

    bool isValidPath(const std::string sPath);


public:

    ObjectManager();
    ~ObjectManager();


    void loadPath(const std::string sPath);

    VecVecStr getDuplicateBySize();

    VecVecStr getDuplicateByHash(const VecVecStr vecfiles);

    VecStr getListOfAllFiles();

};


} //namespace dup_finder
#endif