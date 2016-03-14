//
//  EqualNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

EqualNode::EqualNode(ExpressionNode *left, ExpressionNode *right)
:BinaryOperatorNode(left, right) {
    MSG("EqualNode constructor");
}

int EqualNode::Evaluate() {
    MSG("EqualNode Evaluate");
    if(mLhs->Evaluate() == mRhs->Evaluate()) {
        return 1;
    }
    return 0;
}