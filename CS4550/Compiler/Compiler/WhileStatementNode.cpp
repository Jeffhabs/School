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

