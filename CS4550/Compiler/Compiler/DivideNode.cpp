//
//  DivideNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

DivideNode::DivideNode(ExpressionNode *left, ExpressionNode *right)
:BinaryOperatorNode(left, right) {
    MSG("DivideNode Constructor")
}

int DivideNode::Evaluate() {
    MSG("DivideNode Evaluate");
    return mLhs->Evaluate() / mRhs->Evaluate();
}
/*
void DivideNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopDivPush();
}
*/