#include "ObjectManager.hpp"

#include <iostream>
#include <filesystem>
#include <map>

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

int ObjectManager::getFileSize(const string sFile) {
    if (not isValidPath(sFile)) {
        cout << "File: " << sFile << " is invalide. Please have a look there!\n";
        return 0;
    }

    int fileSize =0;

    fs::path filePath = sFile;
    try {
        fileSize = fs::file_size(filePath);
    } catch (const std::filesystem::filesystem_error & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return fileSize;

}

VecVecStr ObjectManager::getDuplicateBySize() {
    VecVecStr res;

    VecStr pathList = getListOfAllFiles();

    if(pathList.size() ==0) {
        return res;
    }

    map<int, VecStr> fileSizeDictionary;

    for (string file: pathList) {
        int size = getFileSize(file);
        if (size != 0) {
            fileSizeDictionary[size].push_back(file);
        } else {
            cout << "Skipping file :'" << file << "' with size 0\n";
        }
    }

    for (auto item: fileSizeDictionary) {
        if (item.second.size() >1 ) {
            res.push_back(item.second);
        }
    }


    return res;
}

bool ObjectManager::isValidPath(const string sPath) {
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
        // const auto filenameStr = entry.path().filename().string();
        // TO DO: implement ignore rule
        // ex: '.git', '.vscode', etc..

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