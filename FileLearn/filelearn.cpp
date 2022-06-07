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
    int i = 0;

    while( getline( myfile, temp )) {
        LogEntry myLogEntry(temp);
        cout << "IP Address       : " << myLogEntry.getIP() << endl
         << "Logged In User   : " << myLogEntry.getLoggedInUser() << endl
         << "Request Host     : " << myLogEntry.getRequestHost() << endl
         << "Request URI      : " << myLogEntry.getRequestURI() << endl
         << "Request Protocol : " << myLogEntry.getRequestProtocol() << endl
         << "Status           : " << myLogEntry.getStatus() << endl
         << "Body Bytes Sent  : " << myLogEntry.getBodyBytesSent() << endl
         << "Referrer         : " << myLogEntry.getReferrer() << endl
         << "User Agent       : " << myLogEntry.getUserAgent() << endl
         << "X-Forwarded-For  : " << myLogEntry.getXForwardedFor() << endl
         << "i: " << ++i << endl;

        if( i == 50000 )
            break;
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


