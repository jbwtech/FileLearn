//
//  LogEntry.cpp
//  FileLearn
//
//  Created by jbwtech on 6/5/22.
//

#include "LogEntry.hpp"
#include <string>
#include <iostream>

using namespace std;

LogEntry::LogEntry(string text) {
    request = text;
}

LogEntry::~LogEntry() {
    return;
}

string LogEntry::getRequest() {
    return request;
}
