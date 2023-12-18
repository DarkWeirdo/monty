#include "monty.h"

/**
* PrintStack - Adds a node to the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: line number of  the opcode.
*/
void PrintStack(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
(void) line_number;
if (stack == NULL)
exit(EXIT_FAILURE);
temp = *stack;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}

/**
* Add2Stack - Adds a node to the stack.
* @new_node: Pointer to the new node.
* @ln: Interger representing the line number of of the opcode.
*/
void Add2Stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *temp;
if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
temp = head;
head = *new_node;
head->next = temp;
temp->prev = head;
}


/**
* PopTop - Adds a node to the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void PopTop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (stack == NULL || *stack == NULL)
MoreError(7, line_number);
temp = *stack;
*stack = temp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}

/**
* PrintTop - Prints the top node of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void PrintTop(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL)
MoreError(6, line_number);
printf("%d\n", (*stack)->n);
}
