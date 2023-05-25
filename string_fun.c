#include "shell.h"
0;276;0c
/**
* _strlen - returns the length of a string
* @s: a pointer to the string
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
* _strdup - Returns a pointer to allocated space.
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
* @s1: Pointer to the first string.
* @s2: Pointer to the second string.
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
 * Return: pointer to destinatio
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

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted, input by user
 *
 * Return: The converted integer,
 * or -1 on conversion error.
 */
int _atoi(char *s)
{
	unsigned int m, i;
	char pos;

	i = 0;
	m = 0;
	while (s[i] != '\0')
	{
		if (!((s[i] >= '0') && (s[i] <= '9')))
		{
			return (-1);
		}

		if (((s[i] >= '0') && (s[i] <= '9')))
		{
			m = (m * 10) + (s[i] - '0');
		}
		else if (s[i] == '+')
		{
			pos++;
		}

		i++;
	}
	return (m);
}

/**
 * text_to_array - converts text to an array of strings
 *
 * @text_read: the text
 *
 * Return: a pointer to a char array containing the converted text
 */
char **text_to_array(char *text_read)
{
	char *tok, *cmd;
	char **command_lines;
	int i;
	unsigned int characters_count;

	characters_count = 0;
	command_lines = NULL;
	i = 0;
	characters_count = piped_characters_count(text_read, '\n');
	command_lines = (char **)malloc((characters_count + 1) * sizeof(char *));
	tok = strtok(text_read, "\n");
	cmd = _strdup(tok);
	command_lines[i++] = cmd;
	while (tok != NULL)
	{
		tok = _strtok(NULL, "\n");
		if (tok != NULL)
		{
			cmd = _strdup(token);
			command_lines[i++] = cmd;
		}
	}
	free(text_read);
	command_lines[i] = NULL;
	return (command_lines);
}
/**
 * number_to_character - Converts an integer to a string.
 * @number: The integer to be converted.
 *
 * Return: The string representation of the integer,
 * or NULL on failure.
 */

char *number_to_character(int number)
{
	int count = 0, temprory = number;
	char *copied_number;

	if (number == 0)
		count = 1;
	else
	{
		while (temprory != 0)
		{
			temprory = temprory / 10;
			count++;
		}
	}

	copied_number = malloc(sizeof(char) * (count + 1));
	if (!copied_number)
	{
		perror("malloc error");
		return (NULL);
	}

	copied_number[count] = '\0';

	while (count != 0)
	{
		count--;
		copied_number[count] = '0' + number % 10;
		number = (number / 10);
	}

        return (copied_number);
}
