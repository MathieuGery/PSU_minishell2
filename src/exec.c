/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** exec.c
*/

#include "mysh.h"
#include "lib.h"

int execc(char *str, char **env, shell_t *shell)
{
	char **s;
	char **arr = str_to_word_array(str);

	if (check_str(str) == 0) {
		if (check(arr, env, shell) == 1)
			return (1);
		else if (check_exit(arr) == 0) {
			s = proc(arr, env);
			process(s, env, shell);
		}
	}
	return (0);
}
