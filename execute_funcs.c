#include "main.h"

stack_t *newNode(int data)
{
    stack_t *node = (stack_t*)malloc(sizeof(stack_t));
    node->n = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void push(stack_t **top, int data)
{
    stack_t *node = newNode(data);
    node->next = *top;
    if (*top != NULL)
        (*top)->prev = node;
    *top = node;
    printf("element pushed: \n");
}

void pall(stack_t *top)
{
        if (top == NULL)
        {
                printf("Error: can't pint, stack empty\n");
                exit(EXIT_FAILURE);
        }
    printf("all elements of stack: \n");

    while (top != NULL)
    {
        printf("%d\n", top->n);
        top = top->next;
    }
}

void pint(stack_t *top)
{
    if (top == NULL)
        {
            printf("Error: can't pint, stack empty\n");
            exit(EXIT_FAILURE);
        }
    
    if (top != NULL)
        printf("top element of stack: %d\n", top->n);
}

void pop(stack_t **top)
{
        if (*top == NULL)
        {
        printf("Error: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
        }

    if (*top != NULL)
    {
        stack_t *temp = *top;
        *top = (*top)->next;
        if (*top != NULL)
            (*top)->prev = NULL;
        free(temp);
        printf("top elemnt popped\n");
    }
}

void swap(stack_t **top)
{
         if (*top == NULL || (*top)->next == NULL)
    {
        printf("Error: can't swap, stack too short\n");
        exit(EXIT_FAILURE);
    }

    if (*top != NULL && (*top)->next != NULL)
    {
        stack_t *temp = *top;
        *top = (*top)->next;
        (*top)->prev = temp->prev;
        temp->prev = *top;
        temp->next = (*top)->next;
        if ((*top)->next != NULL)
            (*top)->next->prev = temp;
        (*top)->next = temp;
        printf("top two elemnts swapped\n");
    }
}

void add(stack_t **top)
{
        if (*top == NULL || (*top)->next == NULL)
    {
        printf("Error: can't add, stack too short\n");
        exit(EXIT_FAILURE);
    }

    if (*top != NULL && (*top)->next != NULL)
    {
        (*top)->next->n += (*top)->n;
        pop(top);
        printf("top two elements added: \n");
    }
    
}
