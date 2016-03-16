//
//  IntegerNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

IntegerNode::IntegerNode(int integer)
:mInteger(integer) {
    MSG("IntegerNode Constructor");
}

int IntegerNode::Evaluate() {
    MSG("IntegerNode Evaluate");
    return mInteger;
}

/*
void IntegerNode::CodeEvaluate(InstructionsClass &machineCode) {
    MSG("IntegerNode CodeEvaluate");
    machineCode.PushValue(this->mValue);
}
*/