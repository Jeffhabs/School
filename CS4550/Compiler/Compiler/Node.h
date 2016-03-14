//
//  Node.h
//  Compiler
//
//  Created by Jeffrey Haberle on 3/1/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Symbol.h"

using namespace std;

class Node;
class StartNode;
class ProgramNode;
class BlockNode;
class StatementGroupNode;
class StatementNode;
class DeclarationStatementNode;
class IdentifierNode;
class AssignmentStatementNode;
class ExpressionNode;
class CoutStatementNode;
class IntegerNode;
class BinaryOperatorNode;
class PlusNode;
class MinusNode;
class TimesNode;
class DivideNode;
class LessNode;
class LessEqualNode;
class GreaterNode;
class GreaterEqualNode;
class EqualNode;
class NotEqualNode;
class EndLNode;
class OrNode;
class AndNode;
class ExponentNode;

class Node {
public:
    virtual ~Node();
    //add some more stuff eventuall
};

class StartNode: public Node {
public:
    StartNode(ProgramNode *programNode);
    ~StartNode();
    
private:
    ProgramNode *mProgramNode;
};

class ProgramNode: public Node {
public:
    ProgramNode(BlockNode *blockNode);
    ~ProgramNode();
    
private:
    BlockNode *mBlockNode;
};

class StatementGroupNode: public Node {
public:
    StatementGroupNode();
    ~StatementGroupNode();
    void AddStatement(StatementNode *statementNode);
    
private:
    vector<StatementNode*> mStatementNodes;
};

class StatementNode: public Node {
public:
    StatementNode();
    ~StatementNode();

private:
};

class BlockNode: public StatementNode {
public:
    BlockNode(StatementGroupNode *statementGroupNode);
    ~BlockNode();
    
private:
    StatementGroupNode *mStatementGroupNode;
};

class DeclarationStatementNode: public StatementNode {
public:
    DeclarationStatementNode(IdentifierNode *identifierNode);
    ~DeclarationStatementNode();

private:
    IdentifierNode *mIdentifierNode;
};

class AssignmentStatementNode: public StatementNode {
public:
    AssignmentStatementNode(IdentifierNode *identifierNode, ExpressionNode *expressionNode);
    ~AssignmentStatementNode();
    
private:
    IdentifierNode *mIdentifierNode;
    ExpressionNode *mExpressionNode;
};

class CoutStatementNode: public StatementNode {
public:
    CoutStatementNode();
    ~CoutStatementNode();
    void AddExpression(ExpressionNode *en);
    
private:
    vector<ExpressionNode*> mExpressionNodes;
    EndLNode *mEndLNode;
};

class ExpressionNode {
public:
    virtual int Evaluate();
    virtual ~ExpressionNode();
    
private:
};

class EndLNode {
public:
    EndLNode();
    ~EndLNode();
    int Evaluate();
};

class IntegerNode: public ExpressionNode {
public:
    IntegerNode(int integer);
    int Evaluate();
    
private:
    int mInteger;
};

class NotNode: public ExpressionNode {
public:
    NotNode(ExpressionNode *en);
    ~NotNode();
    int Evaluate();

private:
    ExpressionNode *mExpressionNode;
};



class IdentifierNode: public ExpressionNode {
public:
    IdentifierNode(string label, SymbolTableClass *symbolTableClass);
    ~IdentifierNode();
    int Evaluate();
    void DeclareVariable();
    void SetValue(int value);
    int GetIndex();
    
private:
    string mLabel;
    SymbolTableClass *mSymbolTableClass;
};

class BinaryOperatorNode: public ExpressionNode {
public:
    BinaryOperatorNode(ExpressionNode *lhs, ExpressionNode *rhs);
    ~BinaryOperatorNode();
private:
protected:
    ExpressionNode *mLhs;
    ExpressionNode *mRhs;
};

class PlusNode: public BinaryOperatorNode {
public:
    PlusNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    
private:
};

class MinusNode: public BinaryOperatorNode {
public:
    MinusNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    
private:
};

class TimesNode: public BinaryOperatorNode {
public:
    TimesNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
};

class DivideNode: public BinaryOperatorNode {
public:
    DivideNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
};

class LessNode: public BinaryOperatorNode {
public:
    LessNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();   
};

class LessEqualNode: public BinaryOperatorNode {
public:
    LessEqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
};

class GreaterNode: public BinaryOperatorNode {
public:
    GreaterNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
};

class GreaterEqualNode: public BinaryOperatorNode {
public:
    GreaterEqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
};

class EqualNode: public BinaryOperatorNode {
public:
    EqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
};

class NotEqualNode: public BinaryOperatorNode {
public:
    NotEqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
};

class OrNode: public BinaryOperatorNode {
public:
    OrNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
private:
};

class AndNode: public BinaryOperatorNode {
public:
    AndNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
private:
};



#endif /* Node_h */
