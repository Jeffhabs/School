//
//  RepeatStatementNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/15/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

RepeatStatementNode::RepeatStatementNode(ExpressionNode *en, StatementNode *sn)
: mExpressionNode(en), mStatementNode(sn) {
    MSG("RepeatStatementNode init");
}

RepeatStatementNode::~RepeatStatementNode() {
    MSG("RepeatStatementNode deconstructor");
    delete mExpressionNode;
    delete mStatementNode;
}

void RepeatStatementNode::Interpret() {
    MSG("RepeatStatementNode interpret");
    int j = mExpressionNode->Evaluate();
    for(int i = 0;i < j; i++){
        mStatementNode->Interpret();
    }
}