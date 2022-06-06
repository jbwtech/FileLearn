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
    
    for( int i = 0; i < 10000; i++) {
        getline( myfile, temp );
        LogEntry myLogEntry(temp);
        cout << "IP Address    : " << myLogEntry.getIP() << endl;
        cout << "Logged In User: " << myLogEntry.getLoggedInUser() << endl;
        cout << "Request Host  : " << myLogEntry.getRequestHost() << endl;
        cout << "Request URI   : " << myLogEntry.getRequestURI() << endl;
        cout << "i: " << i << endl;
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


