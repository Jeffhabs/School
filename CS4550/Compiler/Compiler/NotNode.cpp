//
//  NotNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

NotNode::NotNode(ExpressionNode *en)
:mExpressionNode(en) {
    MSG("NotNode constructor");
}

NotNode::~NotNode() {
    MSG("NotNode destructor");
}

int NotNode::Evaluate() {
    return !mExpressionNode->Evaluate();
}