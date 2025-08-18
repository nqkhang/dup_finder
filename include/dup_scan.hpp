#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

namespace duplib {

bool check_exists(const fs::path &p, fs::file_status s = fs::file_status{})
{
    // std::cout << p;
    if (fs::status_known(s) ? fs::exists(s) : fs::exists(p))
    {
        return true;
    }
    return false;
}

// fs::path convertToFsPath(const string iPath)
// {
//     fs::path a = fs::u8path( u8(iPath));
//     return a;
// }

void getFileList(const string iScanPath, vector<string> &oFileList)
{
    if (iScanPath == "")
    {
        return;
    }

    fs::path current_path(iScanPath);
    if (check_exists(current_path))
    {
        for (const auto &entry : fs::directory_iterator(current_path))
        {
            const auto filenameStr = entry.path().filename().string();
            // cout << "entry: " << filenameStr << endl;

            if (entry.is_directory())
            {
                // std::cout << "dir:  " << filenameStr << '\n';
                getFileList(entry.path().string(), oFileList);
            }
            else if (entry.is_regular_file())
            {
                // std::cout << "file: " << filenameStr << '\n';

                oFileList.push_back(entry.path().string());
            }
            // else
            //     std::cout << "??    " << filenameStr << '\n';
        }
    }
    else
    {
        cout << "Path does not exists!\n"
             << iScanPath << "\n";
    }
}


} // namespace duplib

