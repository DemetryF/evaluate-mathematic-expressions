#include <stdio.h>
#include <stdlib.h>

#include "headers/eval.h"

void free_tree(Node_s *node)
{
    if (node->left != NULL) free_tree(node->left);
    if (node->right != NULL) free_tree (node->right);

    free(node);
}

void eval_free(Operator_s **operators, Token_s **tokens, size_t tokens_count, Node_s *head)
{
    if (operators != NULL)
    {
        for (size_t i = 0; i < OPERATORS_COUNT; i++) free(operators[i]);
        free(operators);
    }

    if (tokens != NULL)
    {
        for (size_t i = 0; i < tokens_count; i++) free(tokens[i]);
        free(tokens);
    }

    if (head != NULL) free_tree(head);
}