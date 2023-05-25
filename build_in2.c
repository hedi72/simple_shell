#include"shell.h"
<<<<<<< HEAD


/**
 * _getenvi - Retrieves the value of an environment variable
 * @name: Name of the environment variable to retrieve the value of
 *
 * Return: The value of the environment variable
 */
char *_getenvi(const char *name)
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
 * _strtok - Breaks a string into a sequence of tokens
 * @str: String to be tokenized
 * @delimiters: Delimiters used to determine the boundaries of the tokens
 *
 * Return: Pointer to the next token or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delimiters)
{
	return (strtok(str, delimiters));
}

#include "shell.h"
/**
 * piped_characters_count - counts the occurrences of a character in a string
 *
 * @string: the string to search for the character
 * @c: the character to search for
 * Return: the number of occurrences of @c in @string
 */
unsigned int piped_characters_count(char *string, char c)
{
	unsigned int counter = 0;

	while (*string != '\0')
	{
		if (*string == c)
			counter++;
		string++;
	}
	return (counter + 1);
}
/*BETTY OKAY*/

=======
>>>>>>> 72ebb0a48b53991f483f4f764cefbdcff1836f5d
/**
* directory_check - checks if a directory exists and is accessible
* @command: the name of the directory to check
* @argument_vector:.
* @count:.
* @command_array:.
* @status:.
* @command_line_before:.
* Return: 1 if the directory exists and is accessible, else 0
*/
int dir_check(char *command, char **argument_vector, int count,
char **command_array, int *status, char *command_line_before)
{
	struct stat st;

if (stat(command, &st) == 0)
{
	if (S_ISDIR(st.st_mode))
	{
		print_error(argument_vector[0], count, command_array[0], PERMISSION_DENIED);
		*status = PERMISSION_DENIED;
		free_all(command_line_before, command_array);
		return (0);
	}
}
<<<<<<< HEAD



=======
return (-1);
}
>>>>>>> 72ebb0a48b53991f483f4f764cefbdcff1836f5d
