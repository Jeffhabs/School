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
    CheckReserved();
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
    else if (strcmp(lexeme, "for") == 0) {
        mType = FOR_TOKEN;
    }
    else if (strcmp(lexeme, "if") == 0) {
        mType = IF_TOKEN;
    }
    else if (strcmp(lexeme, "else") == 0) {
        mType = ELSE_TOKEN;
    }
    else if (strcmp(lexeme, "while") == 0) {
        mType = WHILE_TOKEN;
    }
    else if (strcmp(lexeme, "do") == 0) {
        mType = DO_TOKEN;
    }
    else if (strcmp(lexeme, "repeat") == 0) {
        mType = REPEAT_TOKEN;
    }
    else if (strcmp(lexeme, "endl") == 0) {
        mType = ENDL_TOKEN;
    }
    else if (strcmp(lexeme, "else") == 0) {
        mType = ELSE_TOKEN;
    }
}

ostream & operator<<(ostream & out, const TokenClass &tc) {
    cout << tc.GetTokenTypeName() << " " << tc.GetLexeme();
    return out;
}
