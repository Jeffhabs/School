//
//  LessNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

LessNode::LessNode(ExpressionNode *left, ExpressionNode *right)
:BinaryOperatorNode(left, right) {
    MSG("LessNode Constructor");
}

int LessNode::Evaluate() {
    MSG("LessNode Evaluate");
    if(mLhs->Evaluate() < mRhs->Evaluate()) {
        return 1;
    }
    return 0;
}