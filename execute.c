#include "shell.h"
/**
 * execute_command- Executes commands given.
 *
 * @path: The path of the command .
 * @av: array of strings .
 * @env: array of strings.
 * @status: A pointer to an integer .
 *
 * Returns: NOTHI.
 */
void execute_command(char *path, char **av, char **env, int *status)
{
	pid_t parent_id;

	parent_id = fork();
	if (parent_id < 0)
	{
		perror("fork has failed");
		exit(EXIT_FAILURE);
	}
	if (parent_id == 0)
	{
		execve(path, av, env);
		perror("execve has failed");
		exit(EXIT_FAILURE);
	}
	else if (parent_id > 0)
	{
		waitpid(parent_id, status, WUNTRACED);
		*status  = WEXITSTATUS(*status);
	}
}
