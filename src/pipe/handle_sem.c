/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** handle sem.c
*/

#include "mysh.h"
#include "lib.h"

int handle_sem(char *str, char **env, shell_t *shell)
{
	char **array = str_to_word_array2(str, ';');

	for (int i = 0; array[i] != NULL; i++) {
		if (check_char(array[i], '|') == 0)
			pipe_redir(array[i], env, shell);
		else
			execc(array[i], env, shell);
	}
	return (0);
}
