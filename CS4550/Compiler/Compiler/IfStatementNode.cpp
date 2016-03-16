//
//  IfStatementNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/15/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

IfStatementNode::IfStatementNode(ExpressionNode *en, StatementNode *sn, StatementNode *elseStatementNode)
: mExpressionNode(en), mStatementNode(sn), mElseStatementNode(elseStatementNode) {
    MSG("IfStatementNode init");
}

IfStatementNode::~IfStatementNode() {
    MSG("IfStatementNode deconstructor");
    delete mExpressionNode;
    delete mStatementNode;
    delete mElseStatementNode;
}

void IfStatementNode::Interpret() {
    if (mExpressionNode->Evaluate()) {
        MSG("IfStatementNode evaluated the if");
        mStatementNode->Interpret();
    }
    else {
        if (mElseStatementNode) {
            MSG("IfStatementNode evaluated the else");
            mElseStatementNode->Interpret();
        }
    }
}
/*
void IfStatementNode::Code(InstructionsClass &machineCode)
{
    if (mElseStatementNode != NULL) {
        mExpressionNode->CodeEvaluate(machineCode);
        unsigned char * offset1 = machineCode.SkipIfZeroStack();
        unsigned char * address1 = machineCode.GetAddress();
        mStatementNode->Code(machineCode);
        unsigned char * address2 = machineCode.GetAddress();
        unsigned char * offset2 = machineCode.Jump();
        mElseStatementNode->Code(machineCode);
        unsigned char * address3 = machineCode.GetAddress();
        machineCode.SetOffset(offset1, (int) (address2 - address1));
        machineCode.SetOffset(offset2, (int) (address3 - address2));
    }
    else {
        mExpressionNode->CodeEvaluate(machineCode);
        unsigned char *InsertAddress = machineCode.SkipIfZeroStack();
        unsigned char *address1 = machineCode.GetAddress();
        mStatementNode->Code(machineCode);
        unsigned char *address2 = machineCode.GetAddress();
        machineCode.SetOffset(InsertAddress, (int)(address2-address1));
    }
}
*/