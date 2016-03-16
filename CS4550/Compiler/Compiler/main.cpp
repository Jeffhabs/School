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
#include "Node.h"
#include "Parser.h"

using namespace std;

void testScanner() {
    ScannerClass scanner("test.txt");
    TokenClass token;
    
    do {
        token = scanner.GetNextToken();
        cout << token << " " << scanner.GetLineNumber() << endl;
    } while (token.GetTokenType() != EOF_TOKEN);
}

void testSymbolTable() {
    
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
    
    //table.SetValue("fail", 2); //variable does not exist
    table.GetValue("test");
    //table.AddEntry("test"); //already exists
    table.GetValue("fail");
}

void testParser() {
    SymbolTableClass symbolTable;
    ScannerClass scanner("/Users/jeffreyhaberle/School/CS4550/Compiler/Compiler/test.txt");
    ParserClass parser(&scanner, &symbolTable);
    StartNode *root = parser.Start();
    root->Interpret();
    
}

int main()
{
    testParser();

}



