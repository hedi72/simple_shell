#include "shell.h"

/**
 * add_node - add a new node at the end
 * @head: pointer to pointer
 * @str: pointer to string
 * Return: address of the new node
 */
list_path *add_node(list_path **head, char *str)
{
list_path *new;

if (!head || !str)
return (NULL);
new = malloc(sizeof(list_path));
if (!new)
return (NULL);
new->dir = str;
new->p = NULL;

if (!*head)
{
*head = new;
}
else
{
list_path *last = *head;
while (last->p)
{
last = last->p;
}
last->p = new;
}
return (*head);
}

/**
 * get_env - get the vlue of the variable
 * @name: name of the variable
 * Return: string of value
 */
char *get_env(const char *name)
{
size_t name_len;
const char *env_var;
if (!name)
return (NULL);

name_len = 0;
while ((env_var = environ[name_len]) != NULL)
{
size_t i = 0;
while (name[i] && name[i] == env_var[i])
i++;
if (name[i] == '\0' && env_var[i] == '=')
return ((char *)(env_var + i + 1));
name_len++;
}
return (NULL);
}


/**
* linkpath - create a linked listfor path
* @path: string of path
* Return: pointer to the created link
*/
list_path *linkpath(char *path)
{
list_path *head = '\0';
char *token;
char *cpath = _strdup(path);
token = strtok(cpath, ":");
while (token)
{
head = add_node(&head, token);
token = strtok(NULL, ":");
}
return (head);
}

/**
* find_path - finds the pathname of a file
* @filename: name of file
* @head: head of linked list
* Return: pathname of filename
*/
char *find_path(char *filename, list_path *head)
{
struct stat st;
char path[MAX_PATH_LENGTH];
list_path *tmp = head;
while (tmp)
{
snprintf(path, sizeof(path), "%s/%s", tmp->dir, filename);
if (stat(path, &st) == 0)
{
return (strdup(path));
}
tmp = tmp->p;
}
return (NULL);
}

/**
 * free_list - free a list_
 * @head: pointer to our linked list
*/
void free_list(list_path *head)
{
list_path *next;
while (head)
{
next = head->p;
free(head->dir);
free(head);
head = next;
}
}
