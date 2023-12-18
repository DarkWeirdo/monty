#include "monty.h"

/**
* MulNodes - Adds the top two elements of the stack.
* @stack: Points to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void MulNodes(stack_t **stack, unsigned int LineNumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
MoreError(8, LineNumber, "mul");
(*stack) = (*stack)->next;
sum = (*stack)->n * (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
* ModNodes - Adds the top two elements of the stack.
* @stack: Points to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void ModNodes(stack_t **stack, unsigned int LineNumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
MoreError(8, LineNumber, "mod");

if ((*stack)->n == 0)
MoreError(9, LineNumber);
(*stack) = (*stack)->next;
sum = (*stack)->n % (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
* DivNodes - Adds the top two elements of the stack.
* @stack: Points to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void DivNodes(stack_t **stack, unsigned int LineNumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
MoreError(8, LineNumber, "div");
if ((*stack)->n == 0)
MoreError(9, LineNumber);
(*stack) = (*stack)->next;
sum = (*stack)->n / (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
