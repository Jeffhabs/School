//
//  CoutStatementNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

CoutStatementNode::CoutStatementNode() {
    MSG("CoutStatementNode Constructor");
    mEndLNode = new EndLNode();
}

CoutStatementNode::~CoutStatementNode() {
    MSG("CoutStatementNode deconstructor");
    for (int i=0; i<mExpressionNodes.size(); i++) {
        delete mExpressionNodes.back();
        mExpressionNodes.pop_back();
    }
    delete mEndLNode;
}

void CoutStatementNode::AddExpression(ExpressionNode *en) {
    mExpressionNodes.push_back(en);
}

// EndlNode

EndLNode::EndLNode() {}

EndLNode::~EndLNode() {}

int EndLNode::Evaluate(){
    cout << endl;
    return 0;
}