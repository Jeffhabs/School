//
//  BinaryOperatorNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

BinaryOperatorNode::BinaryOperatorNode(ExpressionNode *lhs, ExpressionNode *rhs)
:mLhs(lhs), mRhs(rhs) {
    MSG("BinaryOperatorNode Constructor");
}

BinaryOperatorNode::~BinaryOperatorNode() {
    MSG("BinaryOperatorNode Destructor");
    delete mLhs;
    delete mRhs;
}

// LessNode

LessNode::LessNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("LessNode init");
}

int LessNode::Evaluate() {
    MSG("LessNode eval");
    return mLhs < mRhs;
}

/*
void LessNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopLessPush();
}
*/

// LessEqualNode

LessEqualNode::LessEqualNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("LessEqualNode init");
}

int LessEqualNode::Evaluate() {
    MSG("LessEqualNode eval");
    return mLhs->Evaluate() <= mRhs->Evaluate();
}
/*
void LessEqualNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopLessEqualPush();
}
*/

// GreaterNode

GreaterNode::GreaterNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("GreaterNode init");
}

int GreaterNode::Evaluate() {
    MSG("GreaterNode eval");
    return mLhs->Evaluate() > mRhs->Evaluate();
}

/*
void GreaterNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopGreaterPush();
}
*/

// GreaterEqualNode

GreaterEqualNode::GreaterEqualNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("GreaterEqualNode init");
}

int GreaterEqualNode::Evaluate() {
    MSG("GreaterEqualNode eval");
    return mLhs->Evaluate() >= mRhs->Evaluate();
}

/*
void GreaterEqualNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopGreaterEqualPush();
}
*/

// EqualNode

EqualNode::EqualNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("EqualNode init");
}

int EqualNode::Evaluate() {
    MSG("EqualNode eval");
    return mLhs->Evaluate() == mRhs->Evaluate();
}

/*
void EqualNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopEqualPush();
}
*/

// NotEqualNode

NotEqualNode::NotEqualNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("NotEqualNode init");
}

int NotEqualNode::Evaluate() {
    MSG("NotEqualNode eval");
    return mLhs->Evaluate() != mRhs->Evaluate();
}
/*
void NotEqualNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopNotEqualPush();
}
*/

// OrNode

OrNode::OrNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("OrNode init");
}

int OrNode::Evaluate() {
    MSG("OrNode eval");
    return mLhs->Evaluate() || mRhs->Evaluate();
}

/*
void OrNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopOrPush();
}
*/

// AndNode

AndNode::AndNode(ExpressionNode *l, ExpressionNode *r)
: BinaryOperatorNode(l, r) {
    MSG("AndNode init");
}

int AndNode::Evaluate() {
    MSG("AndNode eval");
    return mLhs->Evaluate() && mRhs->Evaluate();
}

/*
void AndNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopAndPush();
}
*/