//
//  DoWhileNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/15/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

DoWhileNode::DoWhileNode(ExpressionNode *en, StatementNode *sn, StatementGroupNode *sgn)
: mExpressionNode(en), mStatementNode(sn), mStatementGroupNode(sgn){
    MSG("DoWhileNode init");
}

DoWhileNode::~DoWhileNode() {
    delete mExpressionNode;
    delete mStatementNode;
    delete mStatementGroupNode;
}

void DoWhileNode::Interpret() {
    while (mExpressionNode->Evaluate()) {
        if (mStatementGroupNode == NULL) {
            mStatementNode->Interpret();
        }
        else {
            mStatementGroupNode->Interpret();
        }
    }
}

/*
void DoWhileNode::Code(InstructionsClass &machineCode)
{
    unsigned char * address0 = machineCode.GetAddress();
    mExpressionNode->CodeEvaluate(machineCode);
    unsigned char * offset1 = machineCode.SkipIfZeroStack();
    unsigned char * address1 = machineCode.GetAddress();
    if (mStatementGroupNode == NULL) {
        mStatementNode->Code(machineCode);
    }
    else {
        mStatementGroupNode->Code(machineCode);
    }
    unsigned char * offset2 = machineCode.Jump();
    unsigned char * address2 = machineCode.GetAddress();
    machineCode.SetOffset(offset1, (int) (address2 - address1));
    machineCode.SetOffset(offset2, (int) (address0 - address2)); //offSet
 
}
*/