#include "shell.h"

/**
 * process_token - Processes a token and returns the corresponding string.
 * @token: The input token to process.
 * @status: An integer representing the status of the command.
 * Return: A dynamically allocated string representing the processed token.
 */
char *process_token(char *token, int status)
{
char *cmde, *variable;

cmde = NULL;
variable = NULL;

if (_strcmp("$$", token) == 0)
cmde = get_processid();
else if (_strcmp("$?", token) == 0)
cmde = get__status(status);
else if (token[0] == '$' && token[1] != '\0')
{
variable = _getenvi(&token[1]);
cmde = (variable != NULL) ? _strdup(variable) : _strdup("");
}
else
cmde = _strdup(token);
return (cmde);
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
		cmde = get_processid();
	else if (_strcmp("$?", token) == 0)
		cmde = get__status(status);
	else if ((token[0] == '$') && (token[1]))
	{
		variable = _getenvi(&token[1]);
		if (variable)
			cmde = _strdup(variable);
		else
			cmde = _strdup("");
	}
	else
		cmde = _strdup(token);

	return (cmde);
}
