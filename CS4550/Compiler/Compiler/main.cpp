//
//  main.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 2/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <iostream>
#include "Token.h"
#include "Scanner.h"
using namespace std;

int main()
{
//    TokenType tt = VOID_TOKEN;
//    string lexeme = "void";
//    TokenClass tok1(tt, lexeme);
//    cout << tok1 << endl;
    
    
    ScannerClass scanner("test.txt");
    TokenClass token;
    
    do {
        token = scanner.GetNextToken();
        cerr << token << endl;
    } while (token.GetTokenType() != END_FILE_TOKEN);
}



