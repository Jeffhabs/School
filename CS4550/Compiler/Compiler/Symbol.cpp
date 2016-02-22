//
//  Symbol.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 2/21/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Symbol.h"

SymbolTableClass::SymbolTableClass() {}


bool SymbolTableClass::Exists(string s) {
    for (int i = 0; i < mVariables.size(); i++) {
        if (mVariables[i].mLabel == s) {
            return true;
        }
    }
    
    return false;
}

void SymbolTableClass::AddEntry(string s) {
    if(Exists(s)) {
        cout << "Variable " << s << " exists" << endl;
        exit(1);
    }
    
    Variable newVariable;
    newVariable.mValue = 0;
    newVariable.mLabel = s;
    mVariables.push_back(newVariable);
}

int SymbolTableClass::GetValue(string s) {
    if(!Exists(s)) {
        cout << "Variable " << s << " does not exists." << endl;
        exit(1);
    }
    return mVariables[GetIndex(s)].mValue;
}

void SymbolTableClass::SetValue(string s, int v) {
    if(!Exists(s)) {
        cout << "Variable " << s << " does not exists." << endl;
        exit(1);
    }
    
    mVariables[GetIndex(s)].mValue = v;
}

int SymbolTableClass::GetIndex(string s) {
    for (int i = 0; i <mVariables.size(); i++ ) {
        if(mVariables[i].mLabel == s) {
            return i;
        }
    }
    
    return -1;
}

int SymbolTableClass::GetCount() {
    return (int)mVariables.size();
}