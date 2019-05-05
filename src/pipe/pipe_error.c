/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** pipe_error.c
*/

#include "mysh.h"
#include "lib.h"

pipe_t init_pipe(pipe_t pipe, char **env)
{
	pipe.input = 0;
	pipe.first = 1;
	pipe.nb_command = 0;
	pipe.env = env;
	return (pipe);
}

char **prepare_command(char **command, char *str, char **env)
{
	command = str_to_word_array(str);
	command = proc(command, env);
	return (command);
}

int check_cmd(char **array)
{
	int ret = 0;

	if (arr_size(array) <= 1)
		return (1);
	for (int i = 0; array[i] != NULL; i++) {
		for (int n = 0; array[i][n] != '\0'; n++)
			if (array[i][n] == ' ' || array[i][n] == '\t')
				ret++;
		if (ret == my_strlen(array[i]))
			return (1);
		ret = 0;

	}
	return (0);
}

void pipe_error(shell_t *shell, char **array)
{
	if (shell->output == 1) {
		my_putstr(array[0]);
		my_putstr(": Command not found.\n");
	}
}
