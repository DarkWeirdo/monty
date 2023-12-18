#include "monty.h"

/**
* open - opens file
* @FileName: file namepath
* Return: none since void function
*/

void open(char *FileName)
{
FILE *fd = fopen(FileName, "r");

if (FileName == NULL || fd == NULL)
Error(2, FileName);

read(fd);
fclose(fd);
}


/**
* read - reads file
* @fd: points to file descriptor
* Return: none since void function
*/

void read(FILE *fd)
{
int LineNumber, format = 0;
char *buffer = NULL;
size_t len = 0;

for (LineNumber = 1; getline(&buffer, &len, fd) != -1; LineNumber++)
{
format = ParseLine(buffer, LineNumber, format);
}
free(buffer);
}


/**
* FindFunct - find the matching function for the opcode
* @opcode: opcode
* @value: argument of opcode
* @format:  storage format. If 0 Nodes will be entered as a stack.
* @LineNumber: line number
* if 1 nodes will be entered as a queue.
* Return: void
*/
void FindFunct(char *opcode, char *value, int LineNumber, int format)
{
int i;
int flag;

instruction_t func_list[] = {
{"push", add_to_stack},
{"pall", print_stack},
{"pint", print_top},
{"pop", pop_top},
{"nop", nop},
{"swap", swap_nodes},
{"add", add_nodes},
{"sub", sub_nodes},
{"div", div_nodes},
{"mul", mul_nodes},
{"mod", mod_nodes},
{"pchar", print_char},
{"pstr", print_str},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};

if (opcode[0] == '#')
return;

for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
CallFunc(func_list[i].f, opcode, value, LineNumber, format);
flag = 0;
}
}
if (flag == 1)
Error(3, LineNumber, opcode);
}


/**
* CallFunc - Calls the required function.
* @func: Pointer to the function that is about to be called.
* @op: string representing the opcode.
* @val: string representing a numeric value.
* @LineNumber: line numeber for the instruction.
* @format: Format specifier. If 0 Nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
*/
void CallFunc(op_func func, char *op, char *val, int LineNumber, int format)
{
stack_t *node;
int flag;
int i;

flag = 1;
if (strcmp(op, "push") == 0)
{
if (val != NULL && val[0] == '-')
{
val = val + 1;
flag = -1;
}
if (val == NULL)
Error(5, LineNumber);
for (i = 0; val[i] != '\0'; i++)
{
if (isdigit(val[i]) == 0)
Error(5, LineNumber);
}
node = create_node(atoi(val) * flag);
if (format == 0)
func(&node, LineNumber);
if (format == 1)
add_to_queue(&node, LineNumber);
}
else
func(&head, LineNumber);
}

/**
* ParseLine - Separates each line into tokens to determine
* which function to call
* @buffer: line from the file
* @LineNumber: line number
* @format:  storage format. If 0 Nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
* Return: Returns 0 if the opcode is stack. 1 if queue.
*/

int ParseLine(char *buffer, int LineNumber, int format)
{
char *opcode, *value;
const char *delim = "\n ";

if (buffer == NULL)
Error(4);

opcode = strtok(buffer, delim);
if (opcode == NULL)
return (format);
value = strtok(NULL, delim);

if (strcmp(opcode, "stack") == 0)
return (0);
if (strcmp(opcode, "queue") == 0)
return (1);

FindFunct(opcode, value, LineNumber, format);
return (format);
}
