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