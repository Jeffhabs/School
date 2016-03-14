//
//  StatementGroupNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/1/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

StatementGroupNode::StatementGroupNode() {
    MSG("StatementGroupNode Constructor");
}

StatementGroupNode::~StatementGroupNode() {
    
    for(int i = 0; i < mStatementNodes.size(); i++) {
        delete mStatementNodes[i];
    }
}

void StatementGroupNode::AddStatement(StatementNode *statementNode) {
    mStatementNodes.push_back(statementNode);
}