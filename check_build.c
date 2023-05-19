#include "shell.h"

/**
 * check_build - checks if the command is a buildin command
 * @arv: array of arguments (arguments vector)
 * Return: pointer to void function that takes arv as arguments
*/
void (*check_build(char **arv))(char **arv)
{
int i, j;
mybuild T[] = {
{"exit", exiit},
{"env", cur_env},
{"setenv", _setenv},
{"unsetenv", __unsetenv},
{NULL, NULL},
};
for (i = 0; T[i].name; i++)
{
j = 0;
if (T[i].name[j] == arv[0][j])
{
for (j = 0; arv[0][j]; j++)
{
if (T[i].name[j] != arv[0][j])
break;
}
if (!arv[0][j])
return (T[i].func);
}
}
}
