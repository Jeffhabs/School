//
//  Token.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 2/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Token.h"
using namespace std;

TokenClass::TokenClass() {}

TokenClass::TokenClass(TokenType type, const string &lexeme) {
    mType = type;
    mLexeme = lexeme;
    //CheckReserved();
}

void TokenClass::CheckReserved() {
    const char *lexeme = mLexeme.c_str();
    
    if(strcmp(lexeme, "void") ==0) {
        mType = VOID_TOKEN;
    }
    else if(strcmp(lexeme, "main") == 0) {
        mType = MAIN_TOKEN;
    }
    else if(strcmp(lexeme, "int") == 0) {
        mType = INT_TOKEN;
    }
    else if(strcmp(lexeme, "cout")== 0) {
        mType = COUT_TOKEN;
    }
}

ostream & operator<<(ostream & out, const TokenClass &tc) {
    cout << tc.GetTokenTypeName() << " " << tc.GetLexeme();
    return out;
}
