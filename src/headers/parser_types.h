#pragma once
#include "lexer_types.h"
typedef struct Node
{
    struct Node *left;
    struct Node *right;
    Token_s **tokens;
    char operator_sign;
    size_t divider_pos;
    size_t length;
} Node_s;