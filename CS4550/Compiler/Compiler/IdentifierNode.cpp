//
//  IdentifierNode.cpp
//  Compiler
//
//  Created by Jeffrey Haberle on 3/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

IdentifierNode::IdentifierNode(string label, SymbolTableClass *symbolTable)
:mLabel(label), mSymbolTableClass(symbolTable) {
    MSG("IdentifierMode Constructor");
}

IdentifierNode::~IdentifierNode() {
    MSG("IdentiferNode Destructor");
}

int IdentifierNode::Evaluate() {
    return mSymbolTableClass->GetValue(mLabel);
}

void IdentifierNode::DeclareVariable() {
    mSymbolTableClass->AddEntry(mLabel);
}

void IdentifierNode::SetValue(int value) {
    mSymbolTableClass->SetValue(mLabel, value);
}

int IdentifierNode::GetIndex() {
    return mSymbolTableClass->GetIndex(mLabel);
}
