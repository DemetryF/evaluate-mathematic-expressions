#include <stdlib.h>
#include <stdio.h>

#include "../headers/lexer_types.h"
#include "../headers/parser_types.h"

Node_s *new_node(Token_s **tokens, size_t length, Node_s *left, Node_s *right, char operator_sign, size_t divider_pos)
{
    Node_s *result = (Node_s *)malloc(sizeof(Node_s));

    if (result == NULL)
    {
        printf("allocate memory error.\n");
        exit(1);
    }

    result->tokens = tokens;
    result->length = length;
    result->left = left;
    result->right = right;
    result->operator_sign = operator_sign;
    result->divider_pos = divider_pos;

    return result;
}