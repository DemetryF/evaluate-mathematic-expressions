#include <stdio.h>
#include <stdlib.h>

#include "../headers/parser_types.h"
#include "../headers/lexer_types.h"

short check_brackets(Node_s *node)
{
    size_t brackets = 0;
    if (node->tokens[0]->type != t_brackets || node->tokens[node->length - 1]->type != t_brackets) return 0;

    for (size_t i = 0; i < node->length; i++)
    {
        Token_s *current = node->tokens[i];

        if (current->type != t_brackets) continue;

        if (current->value == '(') brackets++;
        else if (current->value == ')') brackets--;

        if (brackets == 0 && i != node->length - 1) return 0;
    }

    return 1;
}

void remove_brackets(Node_s *node)
{
    while (check_brackets(node))
    {
        node->tokens++;
        node->length -= 2;
    }
}