//
//  StateMachine.h
//  Compiler
//
//  Created by Jeffrey Haberle on 2/2/16.
//  Copyright © 2016 CS4550. All rights reserved.
//

#ifndef StateMachine_h
#define StateMachine_h

#include "Token.h"

enum MachineState {
    START_STATE, IDENTIFIER_STATE, ASSIGNMENT_STATE, INTEGER_STATE, CANTMOVE_STATE,
    LPAREN_STATE, RPAREN_STATE, LCURLY_STATE, RCURLY_STATE, SEMICOLON_STATE,
    LESS_STATE, GREATER_STATE, LESS_EQUAL_STATE, GREATER_EQUAL_STATE,
    PLUS_STATE, MINUS_STATE, DIVIDE_STATE, TIMES_STATE, EQUAL_STATE, ALMOST_NOTEQUAL_STATE, NOTEQUAL_STATE, PLUS_EQUAL_STATE, MINUS_EQUAL_STATE, INSERTION_STATE,
    LINE_COMMENT_STATE, BLOCK_COMMENT1_STATE, BLOCK_COMMENT2_STATE, PIPE1_STATE, OR_STATE,
    AMPERSAND1_STATE, EXPONENT_STATE, AND_STATE, EOF_STATE, LAST_STATE
};

enum CharacterType {
    LETTER_CHAR, WHITESPACE_CHAR, DIGIT_CHAR,
    LPAREN_CHAR, RPAREN_CHAR, LCURLY_CHAR, RCURLY_CHAR, SEMICOLON_CHAR,
    LESS_CHAR, GREATER_CHAR, EQUAL_CHAR, PLUS_CHAR, MINUS_CHAR, DIVIDE_CHAR, TIMES_CHAR,
    PIPE_CHAR, AMPERSAND_CHAR, EXPONENT_CHAR, NEW_LINE_CHAR, BANG_CHAR, EOF_CHAR, BAD_CHAR, LAST_CHAR
};

class StateMachineClass {
public:
    StateMachineClass();
    MachineState UpdateState(char currentCharacter, TokenType & correspondingTokenType);
    MachineState GetCurrentState();
private:
    MachineState mCurrentState;
    MachineState mLegalMoves[LAST_STATE][LAST_CHAR];
    TokenType mCorrespondingTokenTypes[LAST_STATE];
};
#endif /* StateMachine_h */
