#include <iostream>
#include <folder.hpp>
#include <filesystem>
#include <dup_scan.hpp>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, const char**argv)
{
    // cout << "project init!\n";
    // Folder a;

    // a.setSize(100);

    // cout << a.getSize() << endl;
    // const fs::path pathToShow{ argc >= 2 ? argv[1] : fs::current_path() };

    // cout << "current path: " << fs::current_path().string() << endl ;

    // for (const auto& entry : fs::directory_iterator(pathToShow)) {
    //     const auto filenameStr = entry.path().filename().string();
    //     // cout << "entry: " << filenameStr << endl;

    //     if (entry.is_directory()) {
    //         std::cout << "dir:  " << filenameStr << '\n';
    //     }
    //     else if (entry.is_regular_file()) {
    //         std::cout << "file: " << filenameStr << '\n';
    //     }
    //     else
    //         std::cout << "??    " << filenameStr << '\n';
    // }

    // cout << check_exists("yhvgt") << endl;
    vector<string> fileList;
    duplib::getFileList(fs::current_path().string(), fileList);

    for(string file: fileList)
    {
        cout << "File: " << file << endl;
    }


    return 0;
}