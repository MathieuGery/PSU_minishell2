/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** pipe_redir.c
*/

#include "mysh.h"
#include "lib.h"

int pipe_redir(char *str, char **env, shell_t *shell)
{
	char **array = str_to_word_array2(str, '|');
	char **command;
	pipe_t pipe = init_pipe(pipe, env);
	int i = 0;

	if (check_cmd(array) == 1) {
		my_putstr_error("Invalid null command.\n");
		return (1);
	}
	for (i = 0; array[i + 1] != NULL; i++) {
		command = prepare_command(command, array[i], env);
		pipe.input = l_pip(command, &pipe, shell, 0);
		pipe.first = 0;
	}
	command = prepare_command(command, array[i], env);
	pipe.input = l_pip(command, &pipe, shell, 1);
	pipe.nb_command++;
	for (int i = 0; pipe.nb_command != i; i++)
		wait(NULL);
	return (0);
}

void close_condition(int p[], pipe_t *pip, int last)
{
	if (pip->input != 0)
		close(pip->input);
	close(p[1]);
	if (last == 1)
		close(p[0]);
}

void dup_pipe(int p[], pipe_t *pip, int last)
{
	if (pip->first == 1 && last == 0 && pip->input == 0)
		dup2(p[1], STDOUT_FILENO);
	else if (pip->first == 0 && last == 0 && pip->input != 0) {
		dup2(pip->input, STDIN_FILENO);
		dup2(p[1], STDOUT_FILENO);
	} else
		dup2(pip->input, STDIN_FILENO);
}

int l_pip(char **array, pipe_t *pip, shell_t *shell, int last)
{
	int p[2];
	pid_t pid;
	int werror;

	pipe(p);
	pid = fork();
	if (pid == 0) {
		dup_pipe(p, pip, last);
		if (execve(array[0], array, pip->env) == -1)
			exit(EXIT_FAILURE);
	}
	waitpid(pid, &werror, 0);
	if (WIFEXITED(werror))
		shell->output = WEXITSTATUS(werror);
	close_condition(p, pip, last);
	pipe_error(shell, array);
	pip->nb_command++;
	return (p[0]);
}
