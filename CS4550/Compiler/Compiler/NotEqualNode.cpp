//
//  NotEqualNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

NotEqualNode::NotEqualNode(ExpressionNode *left, ExpressionNode *right)
:BinaryOperatorNode(left, right) {
    MSG("NotEqualNode constructor");
}

int NotEqualNode::Evaluate() {
    MSG("NotEqualNode Evaluate");
    if(mLhs->Evaluate() != mRhs->Evaluate()) {
        return 1;
    }
    return 0;
}
