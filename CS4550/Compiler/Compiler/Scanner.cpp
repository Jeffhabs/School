//
//  Scanner.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 2/3/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Scanner.h"
#include "StateMachine.h"

using namespace std;

ScannerClass::ScannerClass(const char *fileIn) {
    mFin.open(fileIn);
    mLineNumber = 1;
}

TokenClass ScannerClass::GetNextToken() {
    
    StateMachineClass stateMachine;
    TokenType correspondingTokenType;
    MachineState currentState = stateMachine.GetCurrentState();
    string lexeme;
    
    do {
        char c = mFin.get();
        lexeme += c;
        if (c == '\n') {
            mLineNumber++;
        }
        currentState = stateMachine.UpdateState(c, correspondingTokenType);
        if (currentState == START_STATE || currentState == EOF_STATE) lexeme = "";
    } while (currentState != CANTMOVE_STATE);
    
    if (correspondingTokenType == BAD_TOKEN) {
        cerr << "Did not recognize character: " << lexeme << endl;
        exit(1);
    }
    
    if (lexeme.back() == '\n') {
        mLineNumber--;
    }
    
    mFin.unget();
    lexeme.pop_back();
    TokenClass token(correspondingTokenType, lexeme);
    token.CheckReserved();
    return token;
}

TokenClass ScannerClass::PeekNextToken() {
    long position = mFin.tellg();
    int line = mLineNumber;
    TokenClass tc = GetNextToken();
    if(!mFin) {
        mFin.clear();
    }
    mFin.seekg(position);
    mLineNumber = line;
    
    return tc;
}


int ScannerClass::GetLineNumber() {
    return mLineNumber;
}










