#pragma once
typedef enum Tokens
{
    t_none,
    t_number,
    t_operators,
    t_decimal_seporator,
    t_brackets,
    t_text
} Tokens_e;

typedef struct Token
{
    Tokens_e type;
    char value;
} Token_s;