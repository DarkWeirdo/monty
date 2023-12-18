#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_function)(stack_t **, unsigned int);
extern stack_t *head;
void open(char *FileName);
void read(FILE *);
int length_chars(FILE *);
void FindFunct(char *, char *, int, int);
int ParseLine(char *buffer, int LineNumber, int format);
void FreeNodes(void);
stack_t *CreateNode(int n);
void PrintStack(stack_t **, unsigned int);
void Add2Stack(stack_t **, unsigned int);
void Add2Queue(stack_t **, unsigned int);
void PopTop(stack_t **, unsigned int);
void PrintTop(stack_t **, unsigned int);
void SwapNodes(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void CallFunc(op_function, char *, char *, int, int);
void AddNodes(stack_t **, unsigned int);
void SubNodes(stack_t **, unsigned int);
void DivNodes(stack_t **, unsigned int);
void MulNodes(stack_t **, unsigned int);
void ModNodes(stack_t **, unsigned int);
void PrintChar(stack_t **, unsigned int);
void PrintStr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void Error(int ErrorCode, ...);
void MoreError(int ErrorCode, ...);
void StringError(int ErrorCode, ...);
void rotr(stack_t **, unsigned int);
#endif
