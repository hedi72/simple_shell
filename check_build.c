#include "shell.h"

/**
 * check_access - Checks the access for a given command in the command line.
 * @command: Line from user entered by getline and path list.
 * @current: Current path turned into linked lists.
 *
 * Return: Full path of the command if it is found and accessible,
 *         NULL if it fails.
 */

char *check_acces(char *command, list_paths *current)
{
	char *full_path;
	int found_path, length, command_length, current_path_legnth;

	if (current == NULL)
		return (NULL);
	while (current)
	{
		current_path_legnth = _strlen(current->path);
		command_length = _strlen(command);
		length = (current_path_legnth + command_length + 2);
	
		full_path = (char *)malloc(length * sizeof(char));
		_strcpy(full_path, current->path);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		found_path = 0;
		if (access(full_path, X_OK) == 0)
		{
			found_path = 1;
			break;
		}
		else
			free(full_path);
		current = current->next;
	}
	if (found_path)
		return (full_path);

	else
		return (NULL);
}
/**
* check_input_f - checks if a file exists and is readable.
* @file: name of file to check
* This function checks if the file specified by
* @file exists and is readable.
*Return: pointer to @file if it exists
*/
char *check_input_f(char *file)
{
char *command;
command = _strdup(file);

	return (command);
}

/**
 * check_mod - a function that checks the mode of my terminal
 *
 * @argc: arguments count
 *
 * Return: 1 in case of interactive mode
 * 0 in case of non interactive mode
 * -1 in case of error
*/
int check_mod(int argc)
{
	struct stat stdin_stat;

	fstat(STDIN_FILENO, &stdin_stat);
	if (argc == 1 && isatty(STDIN_FILENO))
		return (INTERACTIVE_MODE);
	if ((!isatty(STDIN_FILENO) && argc == 1))
		return (NON_INTERACTIVE_PIPE);
	if ((argc >= 1))
		return (NON_INTERACTIVE_MODE);
	return (ERROR);
}
#include"shell.h"
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
		print_err(argument_vector[0], count, command_array[0], PERMISSION_DENIED);
		*status = PERMISSION_DENIED;
		free_all(command_line_before, command_array);
		return (0);
	}
}
return (-1);
}
