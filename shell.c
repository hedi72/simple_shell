#include "shell.h"

/**
 * signal_handler - check if ctrl c is pressed
 * @ sig_num: int
 */
void signal_handler(int signal_num)
{
if (signal_num == SIGINT)
{
_puts("\n#cisfun$ ");
}
}

/**
 * _EOF - handle the end of the file
 * @len: value of the return getline
 * @buff: buffer
 */

void _EOF(int len, char *buff)
{
if (len == -1)
{
if (isatty(STDIN_FILENO))
{
_puts("\n");
free(buff);
}
exit(0);
}
}

/**
 * handle_in - reads user input and execute commands
 * @path: value of the path env variable
 */
void handle_in(char *path)
{
ssize_t len = 0;
char *buff = NULL, *pathname, **args;
size_t size = 0;
list_path *head = linkpath(path);
void (*f)(char **);
signal(SIGINT, signal_handler);
while (len != EOF)
{
_puts("#cisfun$ ");
len = getline(&buff, &size, stdin);
_EOF(len, buff);
args = split_string(buff, "\n");
if (args && args[0])
{
pathname = find_path(args[0], head);
f = check_build(args);
if (f)
{
f(args);
}
else if (!pathname)
{
execute_command(args);
}
else
{
free(args[0]);
args[0] = pathname;
execute_command(args);
}
}
free_arv(args);
}
free_list(head);
free(buff);
}

/**
 * main - principal function shell
 * return: 0 on success
 */
int main(void)
{
char *path = get_env("PATH");
handle_in(path);
free(path);
return (0);
}
