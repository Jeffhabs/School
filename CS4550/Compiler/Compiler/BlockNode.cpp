//
//  BlockNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/1/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

BlockNode::BlockNode(StatementGroupNode *sgNode)
:mStatementGroupNode(sgNode) {
    MSG("BlockNode Constructor");
}

BlockNode::~BlockNode() {
    MSG("BlockNode Destructor")
    delete mStatementGroupNode;
}