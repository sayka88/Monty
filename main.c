#include "main.h"

void execute_instruction(char *instruction, int arg, stack_t **stack)
{
    if (strcmp(instruction, "push") == 0)
    {
        push(stack, arg);
    }
    else if (strcmp(instruction, "pall") == 0)
    {
        pall(*stack);
    }
    else if (strcmp(instruction, "pint") == 0)
    {
        pint(*stack);
    }
    else if (strcmp(instruction, "pop") == 0)
    {
        pop(stack);
    }
    else if (strcmp(instruction, "swap") == 0)
    {
        swap(stack);
    }
    else if (strcmp(instruction, "add") == 0)
    {
        add(stack);
    }
    else
    {
        printf("Error: Unknown instruction %s\n", instruction);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
            char *instruction = strtok(line, " \t\n");
        char *arg_str = strtok(NULL, " \t\n");
        int arg = arg_str ? atoi(arg_str) : 0;

        execute_instruction(instruction, arg, &stack);
    }

    free(line);
    fclose(file);

    return 0;
}
