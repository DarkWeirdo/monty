#include "monty.h"

/**
* Error - Prints error messages indexed by error code.
* @ErrorCode: Error codes are the following cases:
* (1) --> user doesn't give any file or more than one file to the program.
* (2) --> File can't be opened or read.
* (3) --> File contains an invalid instruction.
* (4) --> Program is unable to malloc more memory.
* (5) --> Parameter passed to the instruction "push" is not an int.
* (6) --> Stack is empty for pint.
* (7) --> Stack is empty for pop.
* (8) --> Stack is too short for operation.
*/
void Error(int ErrorCode, ...)
{
va_list AG;
char *op;
int l_num;
va_start(AG, ErrorCode);
switch (ErrorCode)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(AG, char *));
break;
case 3:
l_num = va_arg(AG, int);
op = va_arg(AG, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usAGe: push integer\n", va_arg(AG, int));
break;
default:
break;
}
FreeNodes();
exit(EXIT_FAILURE);
}

/**
* MoreError - handles more errors.
* @ErrorCode: Error codes are the following cases:
* (6) --> Stack is empty for pint.
* (7) --> Stack is empty for pop.
* (8) --> Stack is too short for operation.
* (9) --> Divided by zero.
*/
void MoreError(int ErrorCode, ...)
{
va_list AG;
char *op;
int l_num;
va_start(AG, ErrorCode);
switch (ErrorCode)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n",
va_arg(AG, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n",
va_arg(AG, int));
break;
case 8:
l_num = va_arg(AG, unsigned int);
op = va_arg(AG, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n",
va_arg(AG, unsigned int));
break;
default:
break;
}
FreeNodes();
exit(EXIT_FAILURE);
}

/**
* StringError - for handling string errors.
* @ErrorCode: Error codes for the following cases:
* (10) --> Number inside the node is outside ASCII bounds.
* (11) --> Stack is empty.
*/
void StringError(int ErrorCode, ...)
{
va_list AG;
int l_num;
va_start(AG, ErrorCode);
l_num = va_arg(AG, int);
switch (ErrorCode)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
break;
default:
break;
}
FreeNodes();
exit(EXIT_FAILURE);
}
