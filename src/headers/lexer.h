#pragma once
#include <stdio.h>

#include "lexer_types.h"
#include "parser_types.h"
#include "solve_types.h"
#include "status.h"

Token_s *new_token(Tokens_e type, char value);
void lexer_unexped_token(char token, size_t position);
void lexer_log(Token_s *token);
char *tokens_to_text(Token_s **tokens, size_t length);
Token_s **lexer(char *expression, size_t *tokens_count_ptr, Status_s *status, Operator_s **operators);