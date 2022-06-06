//
//  filelearn.hpp
//  FileLearn
//
//  Created by jbwtech on 6/5/22.
//

#ifndef filelearn_hpp
#define filelearn_hpp

#include <stdio.h>

#endif /* filelearn_hpp */
#include <iostream>
#include <fstream>

using namespace std;

string getit(string filename);
void putit(string filename, string message);
void putit(string filename, string message, bool append);
