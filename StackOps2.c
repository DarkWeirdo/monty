#include "monty.h"

/**
* SubNodes - Adds the top two elements of the stack.
* @stack: Pointing to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void SubNodes(stack_t **stack, unsigned int LineNumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
MoreError(8, LineNumber, "sub");
(*stack) = (*stack)->next;
sum = (*stack)->n - (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
* AddNodes - Adds the top two elements of the stack.
* @stack: Pointing to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void AddNodes(stack_t **stack, unsigned int LineNumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
MoreError(8, LineNumber, "add");
(*stack) = (*stack)->next;
sum = (*stack)->n + (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
* SwapNodes - Swaps the top two elements of the stack.
* @stack: Pointing to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void SwapNodes(stack_t **stack, unsigned int LineNumber)
{
stack_t *temp;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
MoreError(8, LineNumber, "swap");
temp = (*stack)->next;
(*stack)->next = temp->next;
if (temp->next != NULL)
temp->next->prev = *stack;
temp->next = *stack;
(*stack)->prev = temp;
temp->prev = NULL;
*stack = temp;
}

/**
* nop - No actual use.
* @stack: Pointing to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void nop(stack_t **stack, unsigned int LineNumber)
{
(void)stack;
(void)LineNumber;
}
