#include "shell.h"

/**
 * execute_command - executes a command
 * @argv: array of arguments(argument vector)
 * Return: Nada
 */
void execute_command(char **argv)
{
int status;
pid_t child_pid;
if (!argv || !argv[0])
return;
child_pid = fork();
if (child_pid == -1)
{
perror(get_env("_"));
return;
}
if (child_pid == 0)
{
if (execvp(argv[0], argv) == -1)
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
}
waitpid(child_pid, &status, 0);
}

/**
 * split_string - splits a string and make it an array
 * @str: string to be split
 * @delim: delimiter
 * Return: array of pointers
 */

char **split_string(char *str, const char *delim)
{
int i = 0;
int w = 2;
char *token;
char **array = malloc(sizeof(char *) * w);

if (array == NULL)
{
perror(get_env("_"));
return (NULL);
}
token = strtok(str, delim);
while (token != NULL)
{
array[i] = strdup(token);
if (array[i] == NULL)
{
perror(get_env("_"));
free(array);
return (NULL);
}
i++;
w++;
array = realloc(array, sizeof(char *) * w);
if (array == NULL)
{
perror(get_env("_"));
return (NULL);
}
token = strtok(NULL, delim);
}
array[i] = NULL;
return (array);
}

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size of our current pointer
 * Return: new and resized pointer
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *old_ptr;
unsigned int i = 0;
char *new_ptr;
if (ptr == NULL)
return (malloc(new_size));
if (new_size == old_size)
return (ptr);
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);

if (new_ptr == NULL)
return (NULL);

old_ptr = ptr;

if (new_size > old_size)
{
for ( ; i < old_size; i++)
new_ptr[i] = old_ptr[i];
free(ptr);
for ( ; i < new_size; i++)
new_ptr[i] = '\0';
}
else if (new_size < old_size)
{
for (i = 0; i < new_size; i++)
new_ptr[i] = old_ptr[i];
free(ptr);
}
return (new_ptr);
}

/**
 * free_arv - frees the array of pointers arv
 * @arv: array of pointers
 * Return: Nada
*/
void free_arv(char **arv)
{
int i = 0;
if (arv == NULL)
return;
while (arv[i] != NULL)
{
free(arv[i]);
i++;
}
free(arv);
}
