//
//  Scanner.h
//  Compiler
//
//  Created by Jeffrey Haberle on 2/3/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#ifndef Scanner_h
#define Scanner_h

#include <iostream>
#include <fstream>
#include "Token.h"
using namespace std;

class ScannerClass {
public:
    ScannerClass(const char *fileName);
    TokenClass GetNextToken();
    int GetLineNumber();
    
private:
    ifstream  mFin;
    int mLineNumber;
};


#endif /* Scanner_h */
