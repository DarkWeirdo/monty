#include "monty.h"

stack_t *head = NULL;

/**
* main - main function of interperter
* @argc: no. of arguments
* @argv: array list of arguments
* Return: 0 when sucessful
*/

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
open(argv[1]);
FreeNodes();
return (0);
}

/**
* CreateNode - Creates a node.
* @n: Number data to go inside the node.
* Return: returns a pointer to the node at sucess. NULL at failure.
*/
stack_t *CreateNode(int n)
{
stack_t *node;
node = malloc(sizeof(stack_t));
if (node == NULL)
err(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}

/**
* FreeNodes - Frees nodes from the stack.
*/
void FreeNodes(void)
{
stack_t *temp;
if (head == NULL)
return;
while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
}


/**
* Add2Queue - Adds node to the queue.
* @NewNode: Pointer to new node.
* @LineNo: line number of the opcode.
*/
void Add2Queue(stack_t **NewNode, __attribute__((unused))unsigned int LineNo)
{
stack_t *temp;
if (NewNode == NULL || *NewNode == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *NewNode;
return;
}
temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = *NewNode;
(*NewNode)->prev = temp;
}
