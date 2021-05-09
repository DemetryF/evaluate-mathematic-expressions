#include <stdio.h>
#pragma once

typedef enum Status_code
{
    sc_ok,
    sc_unexped_token,
    sc_brackets_error,
    sc_is_not_defined,
    sc_is_not_a_function
} Status_code_e;

typedef struct Status
{
    Status_code_e code;
    size_t data1;
    char *data2;
    char data3;
} Status_s;