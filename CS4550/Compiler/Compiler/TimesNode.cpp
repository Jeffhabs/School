//
//  TimesNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

TimesNode::TimesNode(ExpressionNode *left, ExpressionNode *right)
: BinaryOperatorNode(left, right) {
    MSG("TimesNode Constructor")
}

int TimesNode::Evaluate() {
    MSG("TimesNode Evaluate");
    return mLhs->Evaluate() * mRhs->Evaluate();
}

/*
void TimesNode::CodeEvaluate(InstructionsClass &machineCode)
{
    mLhs->CodeEvaluate(machineCode);
    mRhs->CodeEvaluate(machineCode);
    machineCode.PopPopMulPush();
}
*/