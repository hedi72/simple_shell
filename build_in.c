#include "shell.h"

/**
 * cur_env - print the current environment
 * @arv: array of arg
 */
void cur_env(char **arv __attribute__((unused)))
{
int i = 0;
while (environ[i] != NULL)
{
_puts(environ[i++]);
_puts("\n");
}
while (environ[i] != NULL)
{
_puts(environ[i++]);
_puts("\n");
}
}

/**
 * _atoi - convert string into an integer
 * @s: pointer to a string
 * Return: integer
 */
int _atoi(char *s)
{
int i = 0;
int in = 0;
int sig = 1;

if (s[i] == '-')
{
sig = -1;
i++;
}
while (s[i] >= '0' && s[i] <= '9')
{
in = (in * 10) + (s[i] - '0');
i++;
}
return (sig *in);
}


/**
 * _unsetenv - remove an envir variable
 * @arv: array of words
 */
void _unsetenv(char **arv)
{
int i, j;
if (!arv[1])
{
perror(get_env("_"));
return;
}
for (i = 0; environ[i]; i++)
{
j = 0;
if (arv[1][j] == environ[i][j])
{
while (arv[1][j])
{
if (arv[1][j] != environ[i][j])
break;
j++;
}
if (arv[1][j] == '\0')
{
free(environ[i]);
environ[i] = environ[i + 1];
while (environ[i])
{
environ[i] = environ[i + 1];
i++;
}
return;
}
}
}
}

/**
 * exiit - exit the shell
 * @arv: array of words
 */
void exiit(char **arv)
{
int i, n;
if (arv[1] != NULL)
{
n = _atoi(arv[1]);
n = (n <= -1) ? 2 : n;
free_arv(arv);
exit(n);
}
for (i = 0; arv[i] != NULL; i++)
{
free(arv[i]);
}
free(arv);
exit(0);
}
