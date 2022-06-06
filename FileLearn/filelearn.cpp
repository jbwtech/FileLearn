//
//  filelearn.cpp
//  FileLearn
//
//  Created by jbwtech on 6/5/22.
//
#include <iostream>
#include <fstream>
#include "filelearn.hpp"
#include "LogEntry.hpp"

using namespace std;

string getit(string filename) {
    ifstream myfile;
    string text, temp;
    myfile.open(filename);
    
    for( int i = 0; i < 2; i++) {
        getline( myfile, temp );
        LogEntry myLogEntry(temp);
        cout << myLogEntry.getIP() << endl;
        cout << myLogEntry.getLoggedInUser() << endl;
        cout << myLogEntry.getRequestHost() << endl;
        cout << myLogEntry.getRequestURI() << endl;
    }
    myfile.close();
    return "\n";
}

void putit(string filename, string text) {
    ofstream myfile;
    myfile.open(filename);
    myfile << text;
    myfile.close();
}

void putit(string filename, string text, bool append) {
    ofstream myfile;
    
    if(append)
        myfile.open(filename, ios::app);
    else
        myfile.open(filename);
    myfile << text;
    myfile.close();
}


