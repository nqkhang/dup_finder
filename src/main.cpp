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

    cout << "List of files:\n";
    for(string filePath: fileList) {
        cout << filePath << endl;
    }


    return 0;
}