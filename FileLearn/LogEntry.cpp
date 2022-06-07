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

    this->logentry = text;
//    cout << "CTOR Log Entry: " << this->logentry << endl;

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        this->ipAddress = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
//        cout << "CTOR IP Address: " << this->ipAddress << endl;
    }

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        string dash = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
//        cout << "CTOR Literal dash: " << dash << endl;
    }

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        this->loggedInUser = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
//        cout << "CTOR LoggedInUser: " << this->loggedInUser << endl;
    }

    size_t strBegin = 0, strEnd = 0;
    strBegin = text.find("[", currentPosition);
    strEnd = text.find("]", currentPosition);

    if( strBegin > 0 && strEnd > 0 ) {
        this->dateTime = text.substr(strBegin, strEnd - strBegin + 1);
        currentPosition = strEnd + 1;
//        cout << "CTOR DateTime: " << this->dateTime << endl;
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
//        cout << "CTOR Full Request: " << full_request << endl;
    } else {
        this->status = 0;
        this->bodyBytesSent = 0;
        this->userAgent = "";
        this->referrer = "";
        this->xForwardedFor = "";
        return;
    }

    found = full_request.find(" ", 0);
  
    if( found != 0 ) {
        this->method = full_request.substr(0, found);
        full_request.replace(0, method.size() + 1, "");
//        cout << "CTOR Method: " << this->method << endl;
    }

    found = full_request.find(" ", 0);
  
    if( found != 0 ) {
        this->request = full_request.substr(0, found);
        full_request.replace(0, request.size() + 1, "");
//        cout << "CTOR Request: " << this->request << endl;
    }

    if(full_request.size() > 0) {
        this->serverProtocol = full_request;
//        cout << "CTOR Server Protocol: " << this->serverProtocol << endl;
    }

    string tempstr = "";
    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        tempstr = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
        this->status = stoi(tempstr);
//        cout << "CTOR Status: " << this->status << endl;
    }

    found = text.find(" ", currentPosition);

    if( found > currentPosition ) {
        tempstr = text.substr(currentPosition, found - currentPosition);
        currentPosition = found + 1;
        this->bodyBytesSent = stoi(tempstr);
//        cout << "CTOR Body Bytes Sent: " << this->bodyBytesSent << endl;
    }

    strBegin = text.find("\"", currentPosition);
    strEnd = text.find("\"", strBegin + 1);

    if( strBegin >= currentPosition) {
        currentPosition = strBegin;
        strEnd = text.find("\"", currentPosition + 1);
        this->referrer = text.substr(strBegin + 1, strEnd - strBegin - 1);
        currentPosition += this->referrer.size() + 3;
    }
//    cout << "CTOR Referrer: " << this->referrer << endl;

    strBegin = text.find("\"", currentPosition);
    strEnd = text.find("\"", strBegin + 1);

    if( strBegin >= currentPosition) {
        currentPosition = strBegin;
        strEnd = text.find("\"", currentPosition + 1);
        this->userAgent = text.substr(strBegin + 1, strEnd - strBegin - 1);
        currentPosition += this->userAgent.size() + 3;
    }
//    cout << "CTOR User Agent: " << this->userAgent << endl;

    strBegin = text.find("\"", currentPosition);
    strEnd = text.find("\"", strBegin + 1);

    if( strBegin >= currentPosition) {
        currentPosition = strBegin;
        strEnd = text.find("\"", currentPosition + 1);
        this->xForwardedFor = text.substr(strBegin + 1, strEnd - strBegin - 1);
        currentPosition += this->xForwardedFor.size() + 3;
    }
//    cout << "CTOR X-Forwarded-For: " << this->xForwardedFor << endl;
}

LogEntry::~LogEntry() {
    return;
}

string LogEntry::getEntry() {
    return this->logentry;
}

string LogEntry::getIP() {
    return this->ipAddress;
}

string LogEntry::getLoggedInUser() {
    return this->loggedInUser;
}

string LogEntry::getRequest() {
    return this->request;
}

string LogEntry::getRequestHost() {
    size_t slash_pos = this->request.find("/", 0);
    if( int(slash_pos) != 0 )
        return this->request.substr(0, slash_pos);
    else
        return "";
}

string LogEntry::getRequestURI() {
    size_t slash_pos = this->request.find("/", 0);
    switch( int(slash_pos) ) {
        case -1:
        case  0:
            return this->request;
            break;
        default:
            return this->request.substr(slash_pos, this->request.size() - slash_pos);
    }
}

string LogEntry::getRequestProtocol() {
    return this->serverProtocol;
}

int LogEntry::getStatus() {
    return this->status;
}

int LogEntry::getBodyBytesSent() {
    return this->bodyBytesSent;
}

string LogEntry::getReferrer() {
    return this->referrer;
}

string LogEntry::getUserAgent() {
    return this->userAgent;
}

string LogEntry::getXForwardedFor() {
    return this->xForwardedFor;
}

