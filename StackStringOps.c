#include "monty.h"
/**
* PrintStr - Prints a string.
* @stack: Points to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void PrintStr(stack_t **stack, __attribute__((unused))unsigned int LineNumber)
{
int ascii;
stack_t *temp;
if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
temp = *stack;
while (temp != NULL)
{
ascii = temp->n;
if (ascii <= 0 || ascii > 127)
break;
printf("%c", ascii);
temp = temp->next;
}
printf("\n");
}

/**
* PrintChar - Prints ASCII value.
* @stack: Points to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void PrintChar(stack_t **stack, unsigned int LineNumber)
{
int ascii;
if (stack == NULL || *stack == NULL)
StringError(11, LineNumber);
ascii = (*stack)->n;
if (ascii < 0 || ascii > 127)
StringError(10, LineNumber);
printf("%c\n", ascii);
}

/**
* rotr - Rotates the last node of the stack to the top.
* @stack: Points to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void rotr(stack_t **stack, __attribute__((unused))unsigned int LineNumber)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
temp = *stack;
while (temp->next != NULL)
temp = temp->next;
temp->next = *stack;
temp->prev->next = NULL;
temp->prev = NULL;
(*stack)->prev = temp;
(*stack) = temp;
}

/**
* rotl - Rotates the first node of the stack to the bottom.
* @stack: Points to a pointer pointing to top node of the stack.
* @LineNumber: line number of of the opcode.
*/
void rotl(stack_t **stack, __attribute__((unused))unsigned int LineNumber)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
temp = *stack;
while (temp->next != NULL)
temp = temp->next;
temp->next = *stack;
(*stack)->prev = temp;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}
