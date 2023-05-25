#include "shell.h"

/**
 * builtin_handler - Handles built-in commands in the shell.
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the parsed command.
 * @current: A pointer to a list_paths struct representing the current path.
 * @shell_name: The name of the shell.
 * @count: The count of the commands entered in the shell.
 * @status: A pointer to an integer variable to set the status.
 * @env_list:.
 * @argv:.
 * @command_lines:.
 *
 * Return: The function returns 0 on successful execution of a built-in command
 * -1 if the command is not a built-in command,
 * or an error occurs.
 */
int builtin_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status,
list_paths *env_list, char **command_lines, char **argv)
{
	int i, n;
	char *built_in[] = {"env", "exit", "cd", "setenv"};

	n = -1;

	for (i = 0; i < 4; i++)
	{
		if (_strcmp(built_in[i], command_array[0]) == 0)
		{
			n = i;
			break;
		}
	}

	if (n == -1)
		return (n);

	switch (n)
	{
		case 0:
			print_env(status);
			break;
		case 1:
			exit_handler(command, command_array,
			current, shell_name, count, status, env_list, command_lines);
			break;
		case 2:
			custom_cd(command_array, argv);
			break;
		case 3:
			custom_setenv(command_array[1], command_array[2], current);
			break;
		default:
			return (-1);
	}
	return (0);
}

/**
* cant_open_handler - handles errors that occur when a file cannot be opened
* @program_name: the name of the program attempting to open the file
* @counter: a counter variable to keep track.
* @file_name: the name of the file that cannot be opened
*
* Return : void.
*/
void cant_open_handler(char *program_name, int counter, char *file_name)
{

	char *counter_s;

	counter_s = number_to_character(counter);
	write(STDERR_FILENO, program_name, _strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, counter_s, _strlen(counter_s));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Can't open ", 11);
	write(STDERR_FILENO, file_name, _strlen(file_name));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * char_count - Counts the occurrences of a specific character in a string.
 * @string: The input string.
 * @character: The character to count.
 * Return: The number of occurrences of the character in the string.
 */
unsigned int char_count(char *string, char character)
{
	unsigned int counter = 0;

	while (*string != '\0')
	{
		if (*string != character && *(string + 1) == character)
			counter++;
		string++;
	}
	return (counter + 1);
}
