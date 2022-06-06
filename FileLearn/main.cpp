//
//  main.cpp
//  FileLearn
//
//  Created by jbwtech on 6/5/22.
//

#include <iostream>
#include <fstream>
#include "filelearn.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string filename = argv[1];
    if( filename == "" )
        filename = "example.txt";
//    cout << filename << endl;
//    putit(filename, "Hello World!\n");
//    putit(filename, "This is a line that is appended.\n", true);
//    getit(filename);
    
    filename = "access.log-20220605";
    getit(filename);
    return 0;
}
