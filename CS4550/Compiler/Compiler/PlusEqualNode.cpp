//
//  PlusEqualNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/15/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

PlusEqualNode::PlusEqualNode(IdentifierNode *in, ExpressionNode *en)
: AssignmentStatementNode(in, en) {
    MSG("PlusEqualNode init");
}

PlusEqualNode::~PlusEqualNode() {
    MSG("PlusEqualNode deconstructor");
    delete mIdentifierNode;
    delete mExpressionNode;
}

void PlusEqualNode::Interpret() {
    int exp_value = mExpressionNode->Evaluate();
    exp_value += mIdentifierNode->Evaluate();
    mIdentifierNode->SetValue(exp_value);
}

/*
void PlusEqualNode::Code(InstructionsClass &machineCode)
{
    machineCode.PushVariable(mIdentifierNode->GetIndex());
    mExpressionNode->CodeEvaluate(machineCode);
    machineCode.PopPopAddPush();
    machineCode.PopAndStore(mIdentifierNode->GetIndex());
}
*/