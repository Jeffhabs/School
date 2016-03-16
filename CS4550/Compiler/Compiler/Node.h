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

class IfStatementNode;
class WhileStatementNode;
class RepeatStatementNode;
class DoWhileNode;


class Node {
public:
    virtual ~Node();
    virtual void Interpret() = 0;
    //virtual void Code(InstructionsClass &machineCode) = 0;
};

class StartNode: public Node {
public:
    StartNode(ProgramNode *programNode);
    ~StartNode();
    void Interpret();
   // void Code(InstructionsClass &machineCode);
    
private:
    ProgramNode *mProgramNode;
};

class ProgramNode: public Node {
public:
    ProgramNode(BlockNode *blockNode);
    ~ProgramNode();
    void Interpret();
    //void Code(InstructionsClass &machineCode);
    
private:
    BlockNode *mBlockNode;
};

class StatementGroupNode: public Node {
public:
    StatementGroupNode();
    ~StatementGroupNode();
    void AddStatement(StatementNode *statementNode);
    void Interpret();
    //void Code(InstructionsClass &machineCode);
    
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
    void Interpret();
    //void Code(InstructionsClass &machineCode);
    
private:
    StatementGroupNode *mStatementGroupNode;
};

class DeclarationStatementNode: public StatementNode {
public:
    DeclarationStatementNode(IdentifierNode *identifierNode);
    ~DeclarationStatementNode();
    void Interpret();
    //void Code(InstructionsClass &machineCode);

private:
    IdentifierNode *mIdentifierNode;
};

class AssignmentStatementNode: public StatementNode {
public:
    AssignmentStatementNode(IdentifierNode *identifierNode, ExpressionNode *expressionNode);
    ~AssignmentStatementNode();
    void Interpret();
    //void Code(InstructionsClass &machineCode);
    
protected:
    IdentifierNode *mIdentifierNode;
    ExpressionNode *mExpressionNode;
};

class CoutStatementNode: public StatementNode {
public:
    CoutStatementNode();
    ~CoutStatementNode();
    void Interpret();
    //void Code(InstructionsClass &machineCode);
    void AddExpression(ExpressionNode *en);
    
private:
    vector<ExpressionNode*> mExpressionNodes;
    EndLNode *mEndLNode;
};

class ExpressionNode {
public:
    virtual ~ExpressionNode();
    virtual int Evaluate() = 0;
    //virtual void CodeEvaluate(InstructionsClass &machineCode) = 0;
    
private:
};

class EndLNode {
public:
    EndLNode();
    ~EndLNode();
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class IfStatementNode: public StatementNode {
public:
    IfStatementNode(ExpressionNode *en, StatementNode *sn, StatementNode *elseStatement);
    ~IfStatementNode();
    void Interpret();
    //void Code(InstructionsClass &machineCode);
private:
    ExpressionNode *mExpressionNode;
    StatementNode *mStatementNode;
    StatementNode *mElseStatementNode;
};

class DoWhileNode: public StatementNode {
public:
    DoWhileNode(ExpressionNode *en, StatementNode *sn, StatementGroupNode *statementGroupNode);
    ~DoWhileNode();
    void Interpret();
    //void Code(InstructionsClass &machineCode);
private:
    ExpressionNode *mExpressionNode;
    StatementNode *mStatementNode;
    StatementGroupNode *mStatementGroupNode;
};

class WhileStatementNode: public StatementNode {
public:
    WhileStatementNode(ExpressionNode *en, StatementNode *sn);
    ~WhileStatementNode();
    void Interpret();
    //void Code(InstructionsClass &machineCode);
private:
    ExpressionNode *mExpressionNode;
    StatementNode *mStatementNode;
};

class RepeatStatementNode: public StatementNode {
public:
    RepeatStatementNode(ExpressionNode *en, StatementNode *sn);
    ~RepeatStatementNode();
    void Interpret();
private:
    ExpressionNode *mExpressionNode;
    StatementNode *mStatementNode;
};

class IntegerNode: public ExpressionNode {
public:
    IntegerNode(int integer);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
    
private:
    int mInteger;
};

class NotNode: public ExpressionNode {
public:
    NotNode(ExpressionNode *en);
    ~NotNode();
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);

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
    //void CodeEvaluate(InstructionsClass &machineCode);
    
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
    //void CodeEvaluate(InstructionsClass &machineCode);
private:
};

class MinusNode: public BinaryOperatorNode {
public:
    MinusNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
    
private:
};

class TimesNode: public BinaryOperatorNode {
public:
    TimesNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class DivideNode: public BinaryOperatorNode {
public:
    DivideNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class ExponentNode: public BinaryOperatorNode {
public:
    ExponentNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class LessNode: public BinaryOperatorNode {
public:
    LessNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class LessEqualNode: public BinaryOperatorNode {
public:
    LessEqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class GreaterNode: public BinaryOperatorNode {
public:
    GreaterNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class GreaterEqualNode: public BinaryOperatorNode {
public:
    GreaterEqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class EqualNode: public BinaryOperatorNode {
public:
    EqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class NotEqualNode: public BinaryOperatorNode {
public:
    NotEqualNode(ExpressionNode *lhs, ExpressionNode *rhs);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
};

class OrNode: public BinaryOperatorNode {
public:
    OrNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
private:
};

class AndNode: public BinaryOperatorNode {
public:
    AndNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
    //void CodeEvaluate(InstructionsClass &machineCode);
private:
};

class PlusEqualNode: public AssignmentStatementNode {
public:
    PlusEqualNode(IdentifierNode *identifierNode, ExpressionNode *expressionNode);
    ~PlusEqualNode();
    void Interpret();
    //void Code(InstructionClass &machineCode);
private:
};

class MinusEqualNode: public AssignmentStatementNode {
public:
    MinusEqualNode(IdentifierNode *identifierNode, ExpressionNode *expressionNode);
    ~MinusEqualNode();
    void Interpret();
    //void Code(InstructionClass &machineCode);
    
private:
};



#endif /* Node_h */
