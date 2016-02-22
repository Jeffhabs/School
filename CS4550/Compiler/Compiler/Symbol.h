//
//  Symbol.h
//  Compiler
//
//  Created by Jeffrey Haberle on 2/21/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#ifndef Symbol_h
#define Symbol_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include "debug.h"

using namespace std;

class SymbolTableClass {
    
    struct Variable {
        string mLabel;
        int mValue;
    };
    
public:
    SymbolTableClass();
    bool Exists(string s);
    void AddEntry(string s);
    int GetValue(string s);
    void SetValue(string s, int v);
    int GetIndex(string s);
    int GetCount();
private:
    vector<Variable> mVariables;
};

#endif /* Symbol_h */
