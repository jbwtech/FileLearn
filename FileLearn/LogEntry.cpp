//
//  LogEntry.cpp
//  FileLearn
//
//  Created by jbwtech on 6/5/22.
//

#include "LogEntry.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
LogEntry::LogEntry () {
    puts("ctor");
}

LogEntry::LogEntry(string text) {

    size_t currentPosition = 0, found = 0;

    logentry = text;
    cout << "CTOR Log Entry: " << logentry << endl;

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        ipAddress = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
        cout << "CTOR IP Address: " << ipAddress << endl;
    }

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        string dash = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
        cout << "CTOR Literal dash: " << dash << endl;
    }

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        loggedInUser = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
        cout << "CTOR LoggedInUser: " << loggedInUser << endl;
    }

    size_t strBegin = 0, strEnd = 0;
    strBegin = text.find("[", currentPosition);
    strEnd = text.find("]", currentPosition);

    if( strBegin > 0 && strEnd > 0 ) {
        dateTime = text.substr(strBegin, strEnd - strBegin + 1);
        currentPosition = strEnd + 1;
        cout << "CTOR DateTime: " << dateTime << endl;
    }

    string full_request = "";

    strBegin = text.find("\"", currentPosition);
    if( strBegin > currentPosition) {
        currentPosition = strBegin;
        strEnd = text.find("\"", currentPosition + 1);
        full_request = text.substr(strBegin + 1, strEnd - strBegin - 1);
        currentPosition += full_request.size() + 3;
    }

    if( full_request.size() > 0 ) {
        cout << "CTOR Full Request: " << full_request << endl;
    } else {
        status = 0;
        bodyBytesSent = 0;
        userAgent = "";
        referrer = "";
        xForwardedFor = "";
        return;
    }

    found = full_request.find(" ", 0);
  
    if( found != 0 ) {
        method = full_request.substr(0, found);
        full_request.replace(0, method.size() + 1, "");
        cout << "CTOR Method: " << method << endl;
    }

    found = full_request.find(" ", 0);
  
    if( found != 0 ) {
        request = full_request.substr(0, found);
        full_request.replace(0, request.size() + 1, "");
        cout << "CTOR Request: " << request << endl;
    }

    if(full_request.size() > 0) {
        serverProtocol = full_request;
        cout << "CTOR Server Protocol: " << serverProtocol << endl;
    }

    string tempstr = "";
    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        tempstr = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
        status = stoi(tempstr);
    cout <<  "Substring at " << currentPosition << ": " << text.substr(currentPosition,1) << endl;
        cout << "CTOR Status: " << status << endl;
        cout << "CTOR Status Size: " << tempstr.size() << endl;
        cout << "CTOR Current Position: " << currentPosition << endl;
    }

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        tempstr = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + tempstr.size();
        bodyBytesSent = stoi(tempstr);
        cout << "CTOR Body Bytes Sent: " << bodyBytesSent << endl;
    }

    cout <<  "Substring at " << currentPosition << ": " << text.substr(currentPosition,1) << endl;

    string referrer = "";
    
    strEnd = text.find("\"", strBegin);

    cout << "CTOR strBegin: " << strBegin << endl;

    strBegin = text.find("\"", currentPosition);
    if( strBegin > currentPosition) {
        currentPosition = strBegin;
        strEnd = text.find("\"", currentPosition + 1);
        referrer = text.substr(strBegin + 1, strEnd - strBegin - 1);
        currentPosition += referrer.size() + 2;
    }
    cout << "CTOR Referrer: " << referrer << endl;
    cout << "CTOR Current Position: " << currentPosition << endl;

}

LogEntry::~LogEntry() {
    return;
}

string LogEntry::getEntry() {
    return logentry;
}

string LogEntry::getIP() {
    return ipAddress;
}

string LogEntry::getLoggedInUser() {
    return loggedInUser;
}

string LogEntry::getRequest() {
    return request;
}
