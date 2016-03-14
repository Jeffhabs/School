//
//  AssignmentStatementNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

AssignmentStatementNode::AssignmentStatementNode(IdentifierNode *idNode, ExpressionNode *expNode)
:mIdentifierNode(idNode), mExpressionNode(expNode) {
    MSG("AssignmentStatementNode Constructor");
}

AssignmentStatementNode::~AssignmentStatementNode() {
    MSG("AssignmentStatementNode Destructor");
    delete mIdentifierNode, mExpressionNode;
}