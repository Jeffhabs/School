//
//  WhileStatementNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/15/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

WhileStatementNode::WhileStatementNode(ExpressionNode *en, StatementNode *sn)
: mExpressionNode(en), mStatementNode(sn) {
    MSG("WhileStatementNode init");
}

WhileStatementNode::~WhileStatementNode() {
    delete mExpressionNode;
    delete mStatementNode;
}

void WhileStatementNode::Interpret() {
    while (mExpressionNode->Evaluate()) {
        mStatementNode->Interpret();
    }
}

/*
void WhileStatementNode::Code(InstructionsClass &machineCode)
{
    unsigned char * address0 = machineCode.GetAddress();
    mExpressionNode->CodeEvaluate(machineCode);
    unsigned char * offset1 = machineCode.SkipIfZeroStack();
    unsigned char * address1 = machineCode.GetAddress();
    mStatementNode->Code(machineCode);
    unsigned char * offset2 = machineCode.Jump();
    unsigned char * address2 = machineCode.GetAddress();
    machineCode.SetOffset(offset1, (int) (address2 - address1));
    machineCode.SetOffset(offset2, (int) (address0 - address2)); //offSet
    
}
*/