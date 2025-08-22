#include <iostream>
#include <filesystem>
#include <ObjectManager.hpp>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, const char**argv)
{

    std::string currentPath = fs::current_path().string();

    dup_finder::ObjectManager myObjectManager;

    myObjectManager.loadPath(currentPath);

    vector<string> fileList ;

    fileList = myObjectManager.getListOfAllFiles();

    VecVecStr dupBySize = myObjectManager.getDuplicateBySize();

    if (dupBySize.size() == 0) {
        return 0;
    }

    for (VecStr item: dupBySize) {
        cout<< "\n-------------------------\n";
        for (std::string filePath: item) {
            cout << filePath << endl;
        }
        cout<< "`````````````````````````\n";
    }

    return 0;
}