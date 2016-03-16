//
//  StartNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/1/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

StartNode::StartNode(ProgramNode *programNode)
: mProgramNode(programNode) {
    MSG("StartNode Constructor");
}

StartNode::~StartNode() {
    MSG("StartNode Destructor")
    delete mProgramNode;
}

void StartNode::Interpret() {
    mProgramNode->Interpret();
}

/*
void StartNode::Code(InstructionsClass &machineCode) {
    mProgramNode->Code(machineCode);
}
*/
