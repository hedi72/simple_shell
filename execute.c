#include "shell.h"
/**
 * execute -execute a command
 * @argv: array of argu
 */
void execute_command(char** argv)
{
  if (!argv || !argv[0])
    return;
  pid_t child_pid = fork();
  if (child_pid == -1)
    {
      perror(get_env("_"));
      return;
    }
  if (child_pid == 0)
    {
      if (execvp(arg[0], argv) == -1)
	{
	  perror(argv[0]);
	  exit(EXIT_FAILURE);
	}
    }
  int status;
  waitpid(child_pid, &status, 0);
}

/**
 * split_string - splits a string and make it an array
 * @str: string to be split
 * @delim: delimiter
 * Return: array of pointers
 */

char** split_string(char* str, const char* delim)
{
  int i = 0;
  int w = 2;
  char** array = malloc(sizeof(char*) * w);
  if (array == NULL)
    {
      perror(get_env("_"));
      return (NULL);
    }
  char* token = strtok(str, delim);
  while (token != NULL)
    {
      array[i] = strdup(token);
      if (array[i] == NULL)
	{
	  perror(get_env("_"));
	  free(array);
	  return (NULL);
	}
      i++;
	w++;
	array = realloc(array, sizeof(char*) * w);
	if (array == NULL)
	  {
	    perror(get_env("_"));
	    return (NULL);
	  }
	token = strtok(NULL, delim);
    }
  array[i] = NULL;
  return (array);
}
