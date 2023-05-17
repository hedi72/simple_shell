# simple_shell
project c - simple shell with @Zainab Jimoh

Table of contents:
 -What is the shell ?
 -About this project ?
 -Essential functionalities of the simple shell
 -List of allowed functions and system calls:

 
------------------------------------------------
* what is the shell ?
The "shell" typically refers to a command-line interface (CLI) program in operating systems such as Unix, Linux, and macOS.
It allows users to interact with the computer by entering commands. 

* About this project:
This project is a simple version of the linux shell made by alx-holberton school taking part of the low level programming with c.

* Essential functionalities of the simple shell

-Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
handle commands with arguments
Handle command lines with arguments
Handle the PATH
fork must not be called if the command doesn’t exist

List of allowed functions and system calls:
-access (man 2 access)
-chdir (man 2 chdir)
-close (man 2 close)
-closedir (man 3 closedir)
-execve (man 2 execve)
-exit (man 3 exit)
-_exit (man 2 _exit)
-fflush (man 3 fflush)
-fork (man 2 fork)
-free (man 3 free)
-getcwd (man 3 getcwd)
-getline (man 3 getline)
-getpid (man 2 getpid)
-isatty (man 3 isatty)
-kill (man 2 kill)
-malloc (man 3 malloc)
-open (man 2 open)
-opendir (man 3 opendir)
-perror (man 3 perror)
-read (man 2 read)
-readdir (man 3 readdir)
-signal (man 2 signal)
-stat (__xstat) (man 2 stat)
-lstat (__lxstat) (man 2 lstat)
-fstat (__fxstat) (man 2 fstat)
-strtok (man 3 strtok)
-wait (man 2 wait)
-waitpid (man 2 waitpid)
-wait3 (man 2 wait3)
-wait4 (man 2 wait4)
-write (man 2 write)

