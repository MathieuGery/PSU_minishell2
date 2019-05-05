/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** console.c
*/

#include "mysh.h"
#include "get_next_line.h"
#include "lib.h"

void process_error(int werror, shell_t *shell)
{
	if (WIFEXITED(werror))
		shell->output = WEXITSTATUS(werror);
	if (WTERMSIG(werror) == 11) {
		my_putstr("Segmentation fault\n");
		shell->output = 139;
	}
	if (WTERMSIG(werror) == 8) {
		my_putstr("Floating exception\n");
		shell->output = 136;
	}
}

int process(char **arr, char **env, shell_t *shell)
{
	pid_t pid;
	int werror;

	if (access(arr[0], X_OK) == -1) {
		my_putstr(arr[0]);
		my_putstr(": Command not found.\n");
		return (1);
	}
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0 && execve(arr[0], arr, env) == -1) {
		my_putstr(arr[0]);
		my_putstr(": Command not found.\n");
		exit(EXIT_FAILURE);
	} else
		waitpid(pid, &werror, 0);
	process_error(werror, shell);
	return (WEXITSTATUS(werror));
}

int consol(char **env)
{
	shell_t shell;
	char *str;

	shell.output = 0;
	(isatty(0) == 1 ?  my_putstr("[minishell2]$ ") : 1 == 1);
	for (str = get_next_line(0); str; str = get_next_line(0)) {
		if (check_char(str, ';') == 0)
			handle_sem(str, env, &shell);
		else if (check_char(str, '|') == 0)
			pipe_redir(str, env, &shell);
		else
			if (execc(str, env, &shell) == 1)
				break;
		free(str);
		(isatty(0) == 1 ?  my_putstr("[minishell2]$ ") : 1 == 1);
	}
	if (str == NULL) {
		(isatty(0) == 1 ?  my_putstr("exit\n") : 1 == 1);
		return (shell.output);
	}
	return (shell.output);
}
