#include "ObjectManager.hpp"

#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

namespace dup_finder {

ObjectManager::ObjectManager() {
    mPathToAnalyze = "";

}

ObjectManager::~ObjectManager() {

}

void ObjectManager::analyzePath() {

}

void ObjectManager::loadPath(const string sPath) {

    // TODO: make log line(s) to be enable by flag
    if (this->mPathToAnalyze != "") {
        cout << "Updating old path :'" << mPathToAnalyze 
        << "'\nTo new path: '" << sPath << "'\n";
    }
    mPathToAnalyze = sPath;
}

VecVecStr ObjectManager::getDuplicateBySize() {
    VecVecStr res;

    return res;
}

bool isValidPath(const string sPath) {
    fs::path cur_path(sPath);

    if (fs::exists(cur_path) ) {
        return true;
    }
    return false;
}

void ObjectManager::getListOfFileFrom(const std::string sPath, VecStr& fileList) {

    if (not isValidPath(sPath)) {
        cout << "Path: " << sPath << " is invalide. Please have a look there!\n";
        return;
    }

    fs::path root_path(sPath);
    for (const auto & entry : fs::directory_iterator(root_path) ) {
        const auto filenameStr = entry.path().filename().string();

        if(entry.is_regular_file()) {
            fileList.push_back(entry.path().string());
        }
        else if (entry.is_directory()) {
            getListOfFileFrom(entry.path().string(), fileList);
        }
    }
}

VecStr ObjectManager::getListOfAllFiles() {
    VecStr res;

    if (this->mPathToAnalyze == "") {
        return res;
    }

    getListOfFileFrom(this->mPathToAnalyze, res);

    return res;
}

} // namespace dup_finder