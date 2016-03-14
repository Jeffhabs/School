//
//  DeclarationStatementNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

DeclarationStatementNode::DeclarationStatementNode(IdentifierNode *idNode)
:mIdentifierNode(idNode) {
    MSG("DeclarationStatementNode Constructor");
}

DeclarationStatementNode::~DeclarationStatementNode() {
    MSG("DeclarationStatementNode Destructor");
    delete mIdentifierNode;
}