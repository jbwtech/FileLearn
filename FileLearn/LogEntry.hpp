//
//  LogEntry.hpp
//  FileLearn
//
//  Created by jbwtech on 6/5/22.
//

#ifndef LogEntry_hpp
#define LogEntry_hpp

#include <stdio.h>

#endif /* LogEntry_hpp */
#include <iostream>
#include <string>

using namespace std;

class LogEntry {
private:
    /*
     '$remote_addr - $remote_user [$time_local] '
     '"$request_method $host$request_uri $server_protocol" '
     '$status $body_bytes_sent "$http_referer" '
     '"$http_user_agent" "$http_x_forwarded_for"'
     */
    string ipAddress;
    string loggedInUser;
    string dateTime;
    string method;
    string request;
    string serverProtocol;
    int status;
    int bodyBytesSent;
    string referrer;
    string userAgent;
    string xForwardedFor;
public:
    LogEntry();
    LogEntry(string text);
    ~LogEntry();
     string getRequest();
};
