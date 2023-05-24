#include "shell.h"
/**
 * _setenv - intialize a new env variable or modify an existing
 * @arv: array of xords
 */
void _setenv(char **arv)
{
int i, j, k;
if (!arv[1] || !arv[2])
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
k = 0;
while (arv[2][k])
{
environ[i][j + 1 + k] = arv[2][k];
k++;
}
environ[i][j + 1 + k] = '\0';
return;
}}}
if (!environ[i])
{
environ[i] = concat_all(arv[1], "=", arv[2]);
environ[i + 1] = '\0';
}
}
