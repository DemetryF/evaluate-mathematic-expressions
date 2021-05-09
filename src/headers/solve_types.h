#pragma once
#define OPERATORS_COUNT 7
#define isf(name) strcmp(fname, name) == 0 
#define status_ret if (status->code != sc_ok) return -1;

typedef double(* operator_action_t)(double left, double right);
typedef struct Constant
{
    char *name;
    double value;
} Constant_s;

typedef struct Operator
{
    char sign;
    unsigned short priority;
    operator_action_t action;
} Operator_s;