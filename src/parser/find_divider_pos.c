#include <stdlib.h>

#include "../headers/lexer_types.h"
#include "../headers/solve_types.h"
#include "../headers/solve.h"

size_t find_divider_pos(Token_s **tokens, size_t tokens_count, Operator_s **operators)
{
    int position = -1, brackets = 0, priority = 5;
    for (int i = tokens_count - 1; i >= 0; i--)
    {
        Token_s *current = tokens[i];

        if (current->type == t_brackets) 
        {
            if (current->value == '(') brackets++;
            else if (current->value == ')') brackets--;

            if (brackets != 0) continue;

            if (i != 0 && priority > 4 && current->value == '(' && tokens[i - 1]->type == t_text)
            {
                priority = 4;
                position = i;
            }

            continue;
        }

        if (brackets != 0) continue;
        if (current->type != t_operators) continue;
        
        if (i != 0 && current->value == '-' && tokens[i - 1]->type == t_operators) continue;

        short current_priority = get_priority(current->value, operators);

        if (current_priority == 1) return i;

        if (current_priority < priority)
        {
            priority = current_priority;
            position = i;
        }
    }

    return position;
}