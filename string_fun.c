
/**
 * concat_all - concats 3 strings into a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: third string
 * Return: pointer to the new concatenated string
*/
char *concat_all(char *name, char *sep, char *value)
{
char *result;
int l1, l2, l3, i, k;
l1 = _strlen(name);
l2 = _strlen(sep);
l3 = _strlen(value);

result = malloc(l1 + l2 + l3 + 1);
if (!result)
return ('\0');

for (i = 0; name[i]; i++)
result[i] = name[i];
k = i;
for (i = 0; sep[i]; i++)
result[k + i] = sep[i];
k += i;
for (i = 0; value[i]; i++)
result[k + i] = value[i];
k += i;
result[k] = '\0';
return (result);
}

/**
 * _strdup - returns a pointer to a space newly allocated in memory, containing
 * a copy of the parametered string.
 * @str: pointer to a string.
 * Return: pointer to the string.
*/
char *_strdup(char *str)
{
int i, l;
char *new;
if (!str)
return ('\0');
for (l = 0; str[l] != '\0';)
l++;
new = malloc(sizeof(char) * l + 1);
if (!new)
return ('\0');
for (i = 0; i < l; i++)
new[i] = str[i];
new[l] = str[l];
return (new);
}

/**
 * _strlen - returns the length of a string
 * @s: pointer to a string of characters
 * Return: length of the string upon success, else 0
*/
int _strlen(char *s)
{
int counter = 0;
while (s[counter] != '\0')
counter++;
return (counter);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a newline
 * @str: pointer to a string of chars
 * Return: Nothing
*/
void _puts(char *str)
{
int i = 0;
for ( ; str[i] != '\0'; i++)
_putchar(str[i]);
}

int main()
{
char str1[] = "Zainab", str2[] = "Ayomiposi", str3[] = "Jimoh";
char *src;
int j;
src = concat_all(str1, str2, str3);
printf("%s\n", src);
src = _strdup(str1);
printf("%s\n", src);
j = _strlen(str1);
printf("%d\n", j);
puts(str1);
return (0);
}