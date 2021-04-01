#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MISC 1
#include <math.h>

#include "../eval/headers/eval.h"

#define BUFF_SIZE 100
#define VERSION "3.0.0"

int main(size_t argc, char *argv[])
{
    printf("Welcome to Evaluate Mathematic Expression v%s\nType \".exit\" to exit, \".help\" to more information.\n", VERSION);

    char *input = calloc(BUFF_SIZE, sizeof(char));
    Constant_s **constants = (Constant_s **)malloc((argc + 2) * sizeof(Constant_s *));
    Status_s *status = (Status_s *)malloc(sizeof(Status_s));
    size_t constant_count = 0;

    if (constants == NULL || input == NULL)
    {
        printf("allocate memory error.\n");
        exit(1);
    }

    constants[constant_count++] = new_constant("e", M_E);
    constants[constant_count++] = new_constant("pi", M_PI);

    for (size_t i = 1; i < argc; i++)
    {
        char *current = argv[i];

        if (current[0] == '-')
        {
            switch (current[1])
            {
            case 'd':
            {
                char *copy = malloc(strlen(argv[i] + 2) * sizeof(char));

                if (copy == NULL)
                {
                    printf("allocate memory error.\n");
                    exit(1);
                }

                strcpy(copy, argv[i] + 2);

                char *name = strtok(copy, "=");

                if (name == NULL)
                {
                    printf("invalid -d flag use.\n");
                    return 1;
                }
                
                double value = atof(strtok(NULL, "="));

                constants[constant_count] = new_constant(name, value);

                constants[constant_count]->name = name;
                constants[constant_count]->value = value;

                constant_count++;
            } break;
            }
        }
    }

    constants[constant_count] = new_constant("", 0);

    while (1)
    {
        memset(input, 0, BUFF_SIZE);
        memset(status, 0, sizeof(Status_s));
        status->code = sc_ok;

        printf("> ");
        fgets(input, BUFF_SIZE, stdin);     

        if (strcmp(input, "\n") == 0)
            continue;

        if (input[0] == '.')
        {
            if (strcmp(input + 1, "exit\n") == 0) break;
            if (strcmp(input + 1, "help\n") == 0) printf("Git repository: https://github.com/DemetryF/evaluate-mathematic-expressions\n\n7 operators: +, -, /, *, %%, \\, ^.\nBrackets: \"()\"\nDouble numbers: 2.1\n");

            continue;
        }

        double result = eval(input, status, constants);
        if (status->code != sc_ok) 
        {
            switch (status->code)
            {
            case sc_unexped_token:
                printf("Unexped token '%c' at %ld\n", status->data3, status->data1 + 1);
            break;
            
            case sc_brackets_error:
                printf("Brackets error\n");
            break;

            case sc_is_not_defined:
                printf("'%s' is not defined\n", status->data2);
            break;

            case sc_is_not_a_function:
                printf("'%s' is not a function\n", status->data2);
            break;
            }
            continue;
        }

        printf("%g\n", result);
    }

    free(input);
    return 0;
}