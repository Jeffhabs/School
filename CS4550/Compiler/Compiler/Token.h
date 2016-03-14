//
//  Token.h
//  Compiler
//
//  Created by Jeffrey Haberle on 2/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#ifndef Token_h
#define Token_h

#include <stdio.h>
#include <iostream>
using namespace std;

enum TokenType {
    // Reserved Words:
    VOID_TOKEN, MAIN_TOKEN, INT_TOKEN, COUT_TOKEN, ENDL_TOKEN,
    // Relational Operators:
    LESS_TOKEN, LESS_EQUAL_TOKEN, GREATER_TOKEN, GREATER_EQUAL_TOKEN, EQUAL_TOKEN, NOTEQUAL_TOKEN,
    // Other Operators:
    INSERTION_TOKEN, ASSIGNMENT_TOKEN, PLUS_TOKEN, MINUS_TOKEN, TIMES_TOKEN, DIVIDE_TOKEN,
    OR_TOKEN, AND_TOKEN, EXPONENT_TOKEN, NOT_TOKEN,
    // Other Characters:
    SEMICOLON_TOKEN, LPAREN_TOKEN, RPAREN_TOKEN, LCURLY_TOKEN, RCURLY_TOKEN,
    // Other Token Types:
    IDENTIFIER_TOKEN, INTEGER_TOKEN,
    BAD_TOKEN, END_FILE_TOKEN
};

const string gTokenTypeNames[] = {
    //reserved
    "VOID", "MAIN", "INT", "COUT", "ENDL"
    
    
    //relational
    "LESS", "LESSEQUAL", "GREATER", "GREATEREQUAL", "EQUAL", "NOTEQUAL",
    "INSERTION", "ASSIGNMENT", "PLUS", "MINUS", "TIMES", "DIVIDE",
    "OR", "AND", "EXPONENT", "NOT",
    
    //other
    "SEMICOLON", "LPAREN", "RPAREN", "LCURLY", "RCURLY",
    
    //other
    "IDENTIFIER", "INTEGER", "BAD", "ENDFILE"
};

class TokenClass
{
private:
    TokenType mType;
    string mLexeme;

public:
    TokenClass();
    TokenClass(TokenType type, const string & lexeme);
    TokenType GetTokenType() const { return mType; }
    const string & GetTokenTypeName() const { return gTokenTypeNames[mType]; }
    string GetLexeme() const { return mLexeme; }
    void CheckReserved();
};

ostream & operator<<(ostream & out, const TokenClass &tc);

#endif /* Token_h */
