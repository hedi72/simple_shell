#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/stat.h>
#define MAX_PATH_LENGTH 256

int _putchar.c(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);

char **split_string(char *str, const char *delim);
void execute_command(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;

/**
 * struct list_path - linked list contatining PATH directories
 * @dir: directory in path
 * @p: pointer to the next node
*/
typedef struct list_path
{
char *dir;
struct list_path *p;
} list_path;

char *get_env(const char *name);
list_path *add_node(list_path **head, char *str);
list_path *linkpath(char *path);
char *find_path(char *filename, list_path *head);

/**
 * struct build - pointer to function with correlating buildin command
 * @name: buildin command
 * @func: executes the buildin command
*/
typedef struct build
{
char *name;
void (*func)(char **);
} mybuild;

void free_arv(char **arv);
void free_list(list_path *head);
void(*check_build(char **arv))(char **arv);
int _atoi(char *s);
void exiit(char **arv);
void cur_env(char **arv);
void _setenv(char **arv);
void __unsetenv(char **arv);

#endif /**SHELL_H*/
