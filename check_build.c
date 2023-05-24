#include "shell.h"

/**
 * check_build - checks if the command is a buildin command
 * @arv: array of arguments (arguments vector)
 * Return: pointer to void function that takes arv as arguments
*/
void (*check_build(char **arv))(char **arv)
{
int i = 0, j = 0;
mybuild Tab[] = {
{"exit", exiit},
{"env", cur_env},
{"setenv", _setenv},
{"unsetenv", _unsetenv},
{NULL, NULL},
};
while (Tab[i].name != NULL)
{
while (Tab[i].name[j] != '\0' && arv[0][j] != '\0')
{
if (Tab[i].name[j] != arv[0][j])
break;
j++;
}
if (Tab[i].name[j] == '\0' && arv[0][j] == '\0')
return (Tab[i].func);
i++;
}
return (NULL);
}
