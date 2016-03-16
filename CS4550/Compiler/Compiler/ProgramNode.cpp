//
//  ProgramNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/1/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

ProgramNode::ProgramNode(BlockNode *blockNode)
:mBlockNode(blockNode) {
    MSG("ProgramNode Constructor");
}

ProgramNode::~ProgramNode() {
    MSG("ProgramNode Destructor");
    delete mBlockNode;
}

void ProgramNode::Interpret() {
    mBlockNode->Interpret();
}

/*
void ProgramNode::Code(InstructionsClass &machineCode) {
    mBlockNode->Code(machineCode);
}
*/