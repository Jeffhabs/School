//
//  PlusNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

PlusNode::PlusNode(ExpressionNode *left, ExpressionNode *right)
: BinaryOperatorNode(left, right) {
    MSG("PlusNode Constructor");
}

int PlusNode::Evaluate() {
    return mLhs->Evaluate() + mRhs->Evaluate();
}