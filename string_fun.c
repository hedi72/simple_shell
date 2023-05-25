<<<<<<< HEAD
#include "shell.h"

/**
* _strlen - returns the length of a string
* @s: a pointer to the string
*
* This function takes a pointer to a
* string and counts the number of characters
* in the string using a loop. It returns the length of
* the string as an integer.
*
* Return: the length of the string as an integer.
*/
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
* _strdup - Returns a pointer to a newly allocated space in memory,
* which contains a copy of the string given as a parameter.
* @str: The string to duplicate
* Return: If str is NULL or if malloc() fails - NULL
*/
char *_strdup(char *str)
{
	int len;
	char *arr;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	arr = malloc((sizeof(char) * len) + 1);
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	while (len--)
		arr[len] = str[len];
	return (arr);
}

/**
* _strcmp - Compares two strings.
*
* @s1: Pointer to the first string to be compared.
* @s2: Pointer to the second string to be compared.
*
* Return: An integer less than, equal to, or greater than zero
*/
int _strcmp(char *s1, char *s2)
{
		while (*s1 && *s2 && *s1 == *s2)
		{
			if (*s1 != *s2)
			{
				return ((int)*s1 - (int)*s2);
			}
			s1++;
			s2++;
		}

	return ((int)*s1 - (int)*s2);
}
/**
 * _strcpy - copies a string
 *
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strcat - concats two arrays
 *
 * @dest: destination of concat
 * @src: source array to concat
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int len, i;

	len = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}   
=======
#include"shell.h"
/**
 * int_to_str - Converts an integer to a string.
 * @n: The integer to convert.
 * @str: The buffer to store the resulting string.
 * Return : nothing
 */
void int_to_str(int n, char *str)
{
	int tmp;
	int i = 0;

	if (n == 0)
	{
		str[i++] = '0';
	}
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++; 
	}
	tmp = n;
	while (i > 0)
	{
		str[--i] = tmp % 10 + '0'; 
		tmp /= 10; 

	}
	str[i] = '\0'; 

}
/**
 * line_count - Counts the number of lines in a given string.
 * @line: The input string.
 * Return: The number of lines in the string.
 */
int line_count(char *line)
{
	int i = 0;

	while (*line != '\0')
	{
		i++;
		line++;
	}
	return (i);
}

/**
 * line_to_vector - converts a string into an array of strings
 * @command: the string to convert
 * @status: an integer representing the status of the command
 * Return: a pointer to a char array.
 */
char **line_to_vector(char *command, int status)
{
	char *copied_line, *token, **argument_vector, *variable, *cmde;
	int i = 0, character_count;

	
	if (command[0] == '\0')
		return (NULL);
	copied_line = _strdup(command);
	if (copied_line == NULL)
		return (NULL); /*can't cpy*/
	character_count = char_count(copied_line, ' ');
	argument_vector = malloc((character_count + 1) * sizeof(char *));
	token = _strtok(copied_line, TOK_D);

	cmde = flags_handler(token, command, argument_vector, status);
	argument_vector[i++] = cmde;
	while (token != NULL)
	{
		token = _strtok(NULL, TOK_D);
		if (token != NULL)
		{
			if (_strcmp("$$", token) == 0)
				cmde = get_process_id();
			else if (_strcmp("$?", token) == 0)
				cmde = get_status(status);
			else if ((token[0] == '$') && (token[1]))
			{
				variable = _getenv(&token[1]);
				if (variable)
					cmde = _strdup(variable);
				else
					cmde = _strdup("");
			}
			else
				cmde = _strdup(token);
			argument_vector[i++] = cmde;
		}
	}
	argument_vector[i] = NULL;
	free(copied_line);
	return (argument_vector);
}
/**
 * flags_handler - .
 * @token:.
 * @command:.
 * @argument_vector:.
 * @status:.
 * Return:.
*/
char *flags_handler(char *token, char *command,
char **argument_vector, int status)
{
		char *variable, *cmde, *copied_line;

	copied_line = command;
		if (token == NULL)
	{
		free(argument_vector);
		free(copied_line);
		return (NULL);
	}
	if (_strcmp("$$", token) == 0)
		cmde = get_process_id();
	else if (_strcmp("$?", token) == 0)
		cmde = get_status(status);
	else if ((token[0] == '$') && (token[1]))
	{
		variable = _getenv(&token[1]);
		if (variable)
			cmde = _strdup(variable);
		else
			cmde = _strdup("");
	}
	else
		cmde = _strdup(token);

	return (cmde);
}
>>>>>>> 72ebb0a48b53991f483f4f764cefbdcff1836f5d
