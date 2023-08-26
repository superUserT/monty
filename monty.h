#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global_functions - global and its funcs
 * @fd: File descriptor
 * @line: Line to getline
 * Description: To handle the file and getline
 */

typedef struct file_t
{
	FILE *fd;
	char *line;
} file_t;

extern file_t global;
extern int value;

void handle_command(char *argv);
int f_get_opcode(stack_t **stack, char *arg, char *item, int count);
void f_pushitem(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_swapitem(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void f_addint(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void f_nopvoid(stack_t **stack, unsigned int line_number);
void f_cleanStack(stack_t **stack);
void free_dlistint(stack_t *stack);
int _isdigit(char *c);
stack_t *newNode(int n);
void f_push_error(FILE *fd, char *line, stack_t *stack, int count);
void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item);


#endif
