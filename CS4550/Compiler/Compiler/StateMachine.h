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
    START_STATE, IDENTIFIER_STATE, INTEGER_STATE, CANTMOVE_STATE,
    LESS_STATE, LESS_EQUAL_STATE, GREATER_STATE, GREATER_EQUAL_STATE,
    EQUAL_STATE, NOTEQUAL_STATE, INSERTION_STATE, ASSIGNMENT_STATE,
    PLUS_STATE, MINUS_STATE, TIMES_STATE, DIVIDE_STATE, SEMICOLON_STATE,
    PLUS_EQUAL_STATE, MINUS_EQUAL_STATE, AND_STATE, EXPONENT_STATE,
    LINE_COMMENT_STATE, BLOCK_COMMENT1_STATE, BLOCK_COMMENT2_STATE, PIPE_STATE, OR_STATE,
    LPAREN_STATE, RPAREN_STATE, LCURLY_STATE, RCURLY_STATE, BAD_STATE, END_OF_FILE_STATE, LAST_STATE
};

enum CharacterType {
    LETTER_CHAR, DIGIT_CHAR, WHITE_SPACE_CHAR, PLUS_CHAR, BAD_CHAR,
    LPAREN_CHAR, RPAREN_CHAR, LCURLY_CHAR, RCURLY_CHAR, SEMICOLON_CHAR,
    LESS_CHAR, GREATER_CHAR, EQUAL_CHAR, MINUS_CHAR, DIVIDE_CHAR, TIMES_CHAR,
    PIPE_CHAR, EXPONENT_CHAR, NEW_LINE_CHAR, END_OF_FILE_CHAR, LAST_CHAR
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
