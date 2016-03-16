//
//  Parser.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Parser.h"
#include "Scanner.h"
#include "Symbol.h"
#include "Node.h"

using namespace std;

ParserClass::ParserClass(ScannerClass *scanner, SymbolTableClass *symbolT)
:mScanner(scanner), mSymbolTable(symbolT) {
    MSG("Parser constructor");
}

StartNode * ParserClass::Start() {
    ProgramNode *pn = Program();
    Match(EOF_TOKEN);
    StartNode *sn = new StartNode(pn);
    return sn;
}

TokenClass ParserClass::Match(TokenType expectedType) {
    TokenClass currToken = mScanner->GetNextToken();
    if (currToken.GetTokenType() != expectedType) {
        cerr << "Error in ParserClass::Match. " << endl;
        cerr << "Recieved token type " << currToken.GetTokenTypeName() << endl;
        exit(1);
    }
    MSG("Sucessfully matched Token Type: " <<
        currentToken.GetTokenTypeName() << ". Lexeme: \"" <<
        currentToken.GetLexeme() << "\"");
    
    return currToken;
}

ProgramNode * ParserClass::Program() {
    
    Match(VOID_TOKEN);
    Match(MAIN_TOKEN);
    Match(LPAREN_TOKEN);
    Match(RPAREN_TOKEN);
    BlockNode *bn = Block();
    ProgramNode *pn = new ProgramNode(bn);
    return pn;
}

BlockNode * ParserClass::Block() {
    Match(LCURLY_TOKEN);
    StatementGroupNode *sgn = StatementGroup();
    Match(RCURLY_TOKEN);
    BlockNode *bn = new BlockNode(sgn);
    return bn;
}

StatementGroupNode* ParserClass::StatementGroup() {
    StatementGroupNode *sgn = new StatementGroupNode();
    while (true) {
        StatementNode *statement = Statement();
        if (statement == NULL) {
            return sgn;
        } else {
            sgn->AddStatement(statement);
        }
    }
}

StatementNode * ParserClass::Statement() {
    TokenClass nextToken = mScanner->PeekNextToken();
    TokenType tt = nextToken.GetTokenType();
    if (tt == INT_TOKEN) {
        return DeclarationStatement();
    }
    else if (tt == IDENTIFIER_TOKEN) {
        return AssignmentStatement();
    }
    else if (tt == COUT_TOKEN) {
        return CoutStatement();
    }
    else if (tt == LCURLY_TOKEN) {
        return Block();
    }
    else if (tt == IF_TOKEN) {
        return IfStatement();
    }
    else if (tt == DO_TOKEN) {
        return DoWhile();
    }
    return NULL;
}

DeclarationStatementNode * ParserClass::DeclarationStatement() {
    Match(INT_TOKEN);
    IdentifierNode *identifier = Identifier();
    Match(SEMICOLON_TOKEN);
    DeclarationStatementNode* dsn = new DeclarationStatementNode(identifier);
    return dsn;
}

AssignmentStatementNode * ParserClass::AssignmentStatement() {
    IdentifierNode *identifier = Identifier();
    TokenType tt = mScanner->PeekNextToken().GetTokenType();
    AssignmentStatementNode *asn = NULL;
    if (tt == ASSIGNMENT_TOKEN) {
        Match(ASSIGNMENT_TOKEN);
        ExpressionNode *expression = Expression();
        asn = new AssignmentStatementNode(identifier, expression);
    }
    Match(SEMICOLON_TOKEN);
    return asn;
}

CoutStatementNode * ParserClass::CoutStatement() {
    Match(COUT_TOKEN);
    Match(INSERTION_TOKEN);
    CoutStatementNode *csn = new CoutStatementNode();
    ExpressionNode *expression = Expression();
    csn->AddExpression(expression);
    while (true) {
        TokenType tt = mScanner->PeekNextToken().GetTokenType();
        if (tt == INSERTION_TOKEN) {
            Match(INSERTION_TOKEN);
            TokenClass next = mScanner->PeekNextToken();
            if (next.GetTokenType() == ENDL_TOKEN) {
                Match(ENDL_TOKEN);
                csn->AddExpression(NULL);
            }
            else {
                ExpressionNode *nextExpression = Expression();
                csn->AddExpression(nextExpression);
            }
        }
        else {
            if (tt == ENDL_TOKEN) {
                Match(ENDL_TOKEN);
                csn->AddExpression(NULL);
            }
            Match(SEMICOLON_TOKEN);
            break;
        }
    }
    return csn;
}

IdentifierNode * ParserClass::Identifier() {
    TokenClass token = Match(IDENTIFIER_TOKEN);
    IdentifierNode *in = new IdentifierNode(token.GetLexeme(), mSymbolTable);
    return in;
}

ExpressionNode * ParserClass::Expression() {
    ExpressionNode *expNode = Or();
    return expNode;
}


ExpressionNode* ParserClass::Or() {
    ExpressionNode *current = And();
    while (true) {
        TokenType tt = mScanner->PeekNextToken().GetTokenType();
        if (tt == OR_TOKEN) {
            Match(tt);
            current = new OrNode(current, And());
        }
        else {
            break;
        }
    }
    return current;
}

ExpressionNode* ParserClass::And() {
    ExpressionNode *current = Relational();
    while (true) {
        TokenType tt = mScanner->PeekNextToken().GetTokenType();
        if (tt == AND_TOKEN) {
            Match(tt);
            current = new AndNode(current, Relational());
        }
        else {
            break;
        }
    }
    return current;
}

ExpressionNode* ParserClass::Relational() {
    ExpressionNode * current = Side();
    TokenType tt = mScanner->PeekNextToken().GetTokenType();
    if (tt == LESS_TOKEN || tt == LESS_EQUAL_TOKEN ||
        tt == GREATER_TOKEN || tt == GREATER_EQUAL_TOKEN ||
        tt == EQUAL_TOKEN || tt == NOT_EQUAL_TOKEN) {
        Match(tt);
        if (tt == LESS_TOKEN)
            current = new LessNode(current, Relational());
        else if(tt == LESS_EQUAL_TOKEN)
            current = new LessEqualNode(current, Relational());
        else if(tt == GREATER_TOKEN)
            current = new GreaterNode(current, Relational());
        else if(tt == GREATER_EQUAL_TOKEN)
            current = new GreaterEqualNode(current, Relational());
        else if(tt == EQUAL_TOKEN)
            current = new EqualNode(current, Relational());
        else if(tt == NOT_EQUAL_TOKEN)
            current = new NotEqualNode(current, Relational());
    }
    return current;
}

ExpressionNode* ParserClass::Side() {
    ExpressionNode *current = Term();
    while(true) {
        TokenType tt = mScanner->PeekNextToken().GetTokenType();
        if(tt == PLUS_TOKEN) {
            Match(tt);
            current = new PlusNode(current, Term());
        }
        else if(tt == MINUS_TOKEN) {
            Match(tt);
            current = new MinusNode(current, Term());
        }
        else {
            return current;
        }
    }
}

ExpressionNode* ParserClass::Term() {
    ExpressionNode *current = Exponent();
    while (true) {
        TokenType tt = mScanner->PeekNextToken().GetTokenType();
        if (tt == TIMES_TOKEN) {
            Match(tt);
            current = new TimesNode(current, Exponent());
        }
        else if(tt == DIVIDE_TOKEN) {
            Match(tt);
            current = new DivideNode(current, Exponent());
        }
        else {
            return current;
        }
    }
}

ExpressionNode* ParserClass::Exponent() {
    ExpressionNode *current = Factor();
    while (true) {
        TokenType tt = mScanner->PeekNextToken().GetTokenType();
        if (tt == EXPONENT_TOKEN) {
            Match(tt);
            current = new ExponentNode(current, Factor());
        }
        else {
            return current;
        }
    }
}

ExpressionNode* ParserClass::Factor() {
    ExpressionNode *current = NULL;
    TokenType tt = mScanner->PeekNextToken().GetTokenType();
    if (tt == IDENTIFIER_TOKEN) {
        current = Identifier();
    }
    else if (tt == INTEGER_TOKEN) {
        current = Integer();
    }
    else if (tt == NOT_TOKEN) {
        current = Not();
    }
    else {
        Match(LPAREN_TOKEN);
        current = Expression();
        Match(RPAREN_TOKEN);
    }
    return current;
}

NotNode * ParserClass::Not() {
    Match(NOT_TOKEN);
    ExpressionNode * curr = Factor();
    NotNode *e = new NotNode(curr);
    return e;
}

IntegerNode * ParserClass::Integer() {
    TokenClass tc = Match(INTEGER_TOKEN);
    string s = tc.GetLexeme();
    const char *c = s.c_str();
    IntegerNode *i = new IntegerNode(atoi(c));
    return i;
}

IfStatementNode* ParserClass::IfStatement() {
    StatementNode* S2 = NULL;
    Match(IF_TOKEN);
    Match(LPAREN_TOKEN);
    ExpressionNode * e = Expression();
    Match(RPAREN_TOKEN);
    StatementNode * S1 = Statement();
    TokenType tt = mScanner->PeekNextToken().GetTokenType();
    if (tt == ELSE_TOKEN) {
        Match(ELSE_TOKEN);
        S2 = Statement();
    }
    IfStatementNode* in = new IfStatementNode(e,S1,S2);
    return in;
}

WhileStatementNode* ParserClass::WhileStatement() {
    Match(WHILE_TOKEN);
    Match(LPAREN_TOKEN);
    ExpressionNode *e = Expression();
    Match(RPAREN_TOKEN);
    StatementNode *statement = Statement();
    WhileStatementNode *ws = new WhileStatementNode(e, statement);
    return ws;
}

DoWhileNode* ParserClass::DoWhile() {
    StatementNode *statement = NULL;
    StatementGroupNode *statementgroup = NULL;
    Match(DO_TOKEN);
    TokenType tt = mScanner->PeekNextToken().GetTokenType();
    if (tt == LCURLY_TOKEN) {
        Match(LCURLY_TOKEN);
        statementgroup = StatementGroup();
        Match(RCURLY_TOKEN);
    }
    else {
        statement = Statement();
    }
    Match(WHILE_TOKEN);
    Match(LPAREN_TOKEN);
    ExpressionNode *e = Expression();
    Match(RPAREN_TOKEN);
    Match(SEMICOLON_TOKEN);
    DoWhileNode *dw = new DoWhileNode(e, statement, statementgroup);
    return dw;
}













