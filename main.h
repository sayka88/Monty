#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

stack_t *newNode(int data);

void push(stack_t **top, int data);
void pall(stack_t *top);
void pint(stack_t *top);
void pop(stack_t **top);
void add(stack_t **top);
void swap(stack_t **top);
void execute_instruction(char *instruction, int arg, stack_t **stack);

#endif
