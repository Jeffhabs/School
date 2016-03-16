//
//  ExponentNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/15/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include <math.h>


ExponentNode::ExponentNode(ExpressionNode *lhs, ExpressionNode *rhs)
: BinaryOperatorNode(lhs, rhs) {
    MSG("ExponentNode constructor");
}

int ExponentNode::Evaluate() {
    return pow(mLhs->Evaluate(),mRhs->Evaluate());
}

/*
void ExponentNode::CodeEvaluate(InstructionsClass &machineCode)
{
    //empty
}
 */

