#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../headers/solve_types.h"
#include "../headers/status.h"

double function(char *fname, double arg, Status_s *status)
{
    if (isf("sin")) return sin(arg);
    if (isf("cos")) return cos(arg);
    if (isf("abs")) return fabs(arg);
    if (isf("acos") 
     || isf("arccos")) return acos(arg);
    if (isf("asin")
     || isf("arcsin")) return asin(arg);
    if (isf("atan")
     || isf("arctan")
     || isf("atg")
     || isf("arctg")) return atan(arg);
    if (isf("ch") 
     || isf("cosh")) return cosh(arg);
    if (isf("sh") 
     || isf("sinh")) return sinh(arg);
    if (isf("exp")) return exp(arg);
    if (isf("ln")) return log(arg);
    if (isf("lg")) return log10(arg);
    if (isf("sqrt")) return sqrt(arg);
    if (isf("tan")
     || isf("tg")) return tan(arg);
    if (isf("tanh")
     || isf("tgh")) return tanh(arg);

    status->code = sc_is_not_a_function;
    status->data2 = (char *)malloc(strlen(fname) * sizeof(char));
    strcpy(status->data2, fname);

    return -1;
}