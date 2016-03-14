//
//  Parser.h
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#ifndef Parser_h
#define Parser_h
#include <stdio.h>
#include "Token.h"

class ScannerClass;
class SymbolTableClass;
class StartNode;
class ProgramNode;
class TokenClass;
class StatementGroupNode;
class BlockNode;
class StatementNode;
class DeclarationStatementNode;
class AssignmentStatementNode;
class CoutStatementNode;
class IdentifierNode;
class ExpressionNode;
class IntegerNode;
class NotNode;

class ParserClass {
public:
    ParserClass(ScannerClass *scanner, SymbolTableClass *symbolTableClass);
    StartNode * Start();
    
private:
    ScannerClass *mScanner;
    SymbolTableClass *mSymbolTable;
    ProgramNode * Program();
    TokenClass Match(TokenType expectedType);
    BlockNode * Block();
    StatementGroupNode * StatementGroup();
    StatementNode * Statement();
    DeclarationStatementNode * DeclarationStatement();
    AssignmentStatementNode * AssignmentStatement();
    CoutStatementNode * CoutStatement();
    IdentifierNode * Identifier();
    ExpressionNode * Expression();
    ExpressionNode * Relational();
    ExpressionNode * Side();
    ExpressionNode * Term();
    ExpressionNode * Factor();
    IntegerNode * Integer();
    
    ExpressionNode * Exponent();
    ExpressionNode * Or();
    ExpressionNode * And();
    NotNode * Not();
};

#endif /* Parser_h */
