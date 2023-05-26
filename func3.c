#include"shell.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted, input by user
 *
 * Return: The converted integer,
 * or -1 on conversion error.
 */
int _atoi(char *s)
{
	unsigned int n, i;
	char positive;

	i = 0;
	n = 0;

	/* Iterate through each character of the string */
	while (s[i] != '\0')
	{
		/* Check if the character is a non-digit */
		if (!((s[i] >= '0') && (s[i] <= '9')))
		{
			return (-1);
		}

		/* Check if the character is a digit */
		if (((s[i] >= '0') && (s[i] <= '9')))
		{
			n = (n * 10) + (s[i] - '0');
		}
		else if (s[i] == '+')
		{
			positive++;
		}

		i++;
	}

	/* Return the converted integer */
	return (n);
}

/**
 * _getenv - a fUnction to get enviroment variabe
 * @name: name of enviroment variable to get the value of
 * Return: the value of the enviroment varable
*/

char *_getenv(const char *name)
{
	int i;
	char *variable_name;
	char *variable_value;
	char *value = NULL;

	
	for (i = 0; environ[i] != NULL; i++)
	{
		
		variable_name = strtok(environ[i], "=");
		
		variable_value = strtok(NULL, "=");


		if (strcmp(variable_name, name) == 0)
		{
		
			value = variable_value;
			break;
		}
	}

	return (value);
}

/**
 * _strtok - .
 * @str:.
 * @delimiters:.
 * Return:.
 *
*/
char *_strtok(char *str, const char *delimiters)
{
	return (strtok(str, delimiters));
}
