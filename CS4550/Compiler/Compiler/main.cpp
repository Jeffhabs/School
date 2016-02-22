//
//  main.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 2/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "Token.h"
#include "Scanner.h"
#include "Symbol.h"
using namespace std;

int main()
{
//    TokenType tt = VOID_TOKEN;
//    string lexeme = "void";
//    TokenClass tok1(tt, lexeme);
//    cout << tok1 << endl;
    
/*
    ScannerClass scanner("test.txt");
    TokenClass token;
    
    do {
        token = scanner.GetNextToken();
        cout << token << " " << scanner.GetLineNumber() << endl;
    } while (token.GetTokenType() != END_FILE_TOKEN);
*/
    SymbolTableClass table;
    
    assert(table.GetCount()== 0);
    assert(!table.Exists("test"));
    table.AddEntry("test");
    assert(table.Exists("test"));
    assert(table.GetCount() == 1);
    
    assert(table.GetIndex("test")==0);
    
    assert(table.GetValue("test")==0);
    
    table.SetValue("test", 2);
    assert(table.GetValue("test")==2);
    
   //table.SetValue("fail", 2);
    table.AddEntry("test"); //already exists
    table.GetValue("fail");

    
    

}



