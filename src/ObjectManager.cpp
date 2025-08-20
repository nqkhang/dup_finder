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

VecStr ObjectManager::getListOfAllFiles() {
    VecStr res;

    if (this->mPathToAnalyze == "") {
        return res;
    }

    if (not isValidPath(this->mPathToAnalyze)) {
        return res;
    }

    fs::path root_path(this->mPathToAnalyze);

    for (const auto & entry : fs::directory_iterator(root_path) ) {
        const auto filenameStr = entry.path().filename().string();

        if(entry.is_regular_file()) {
            res.push_back(entry.path().string());
        }
        // else if (entry.is_directory) {}

    }
    

    return res;
}

} // namespace dup_finder