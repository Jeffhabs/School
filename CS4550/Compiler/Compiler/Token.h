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
    VOID_TOKEN, MAIN_TOKEN, INT_TOKEN, COUT_TOKEN, FOR_TOKEN, IF_TOKEN, ELSE_TOKEN,
    WHILE_TOKEN, DO_TOKEN, REPEAT_TOKEN, ENDL_TOKEN,
    
    // Relational Operators:
    ASSIGNMENT_TOKEN, PLUS_TOKEN, MINUS_TOKEN, TIMES_TOKEN, DIVIDE_TOKEN,
    PLUS_EQUAL_TOKEN, MINUS_EQUAL_TOKEN,
    INSERTION_TOKEN, LESS_TOKEN, LESS_EQUAL_TOKEN, GREATER_TOKEN, GREATER_EQUAL_TOKEN,
    EQUAL_TOKEN, NOT_EQUAL_TOKEN, OR_TOKEN, AND_TOKEN, NOT_TOKEN, EXPONENT_TOKEN,
    
    // Other Characters:
    LPAREN_TOKEN, RPAREN_TOKEN, LCURLY_TOKEN, RCURLY_TOKEN, SEMICOLON_TOKEN,
    // Other Token Types:
    IDENTIFIER_TOKEN, INTEGER_TOKEN,
    BAD_TOKEN, EOF_TOKEN
};

const string gTokenTypeNames[] = {
    //reserved
    "VOID", "MAIN", "INT", "COUT", "FOR", "IF", "ELSE",
    "WHILE", "DO", "REPEAT", "ENDL",
    
    
    //relational
    "ASSIGNMENT", "PLUS", "MINUS", "TIMES", "DIVIDE",
    "PLUS_EQUAL", "MINUS_EQUAL",
    "INSERTION", "LESS", "LESS_EQUAL", "GREATER", "GREATER_EQUAL",
    "EQUAL", "NOT_EQUAL", "OR", "AND", "NOT", "EXPONENT",
    
    //other
    "LPAREN", "RPAREN", "LCURLY", "RCURLY", "SEMICOLON",
    
    //other
    "IDENTIFIER", "INTEGER", "BAD", "EOF"
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
