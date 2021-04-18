#include <iostream>
#include <folder.hpp>

using namespace std;

int main()
{
    cout << "project init!\n";
    Folder a;

    a.setSize(100);

    cout << a.getSize() << endl;

    return 0;
}