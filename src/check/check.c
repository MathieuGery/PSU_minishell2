/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** check.c
*/

#include "mysh.h"
#include "lib.h"

int builds(char **arr, char **env, shell_t *shell)
{
	if (str_cmp(arr[0], "env") == 0)
		print_arr(env);
	if (str_cmp(arr[0], "exit") == 0)
		return (exec_exit(arr, shell));
	if (str_cmp_cd(arr[0], "cd") == 0)
		cd_command(arr, env);
	if (str_cmp(arr[0], "setenv") == 0)
		set_env(arr, env);
	if (str_cmp(arr[0], "unsetenv") == 0)
		my_unsetenv(arr, env);
	return (0);
}

int check_build(char **str)
{
	if (str_cmp(str[0], "env") == 0)
		return (0);
	if (str_cmp(str[0], "exit") == 0)
		return (0);
	if (str_cmp(str[0], "setenv") == 0)
		return (0);
	if (str_cmp(str[0], "unsetenv") == 0)
		return (0);
	if (str_cmp_cd(str[0], "cd") == 0)
		return (0);
	return (1);
}

int check(char **arr, char **env, shell_t *shell)
{
	if (check_build(arr) == 0) {
		if (builds(arr, env, shell) == 1) {
			(isatty(0) == 1 ?  my_putstr("exit\n") : 1 == 1);
			return (1);
		}
		return (2);
	}
	return (0);
}

int check_exit(char **s)
{
	if (check_build(s) != 0)
		return (0);
	else
		return (1);
}

int str_cmp_cd(char *str, char *str2)
{
	char **arr;

	if (str[0] != ' ' && str[0] != '\t' && str[0] != '\0')
		arr = str_to_word_array(str);
	else
		return (1);

	if (str_cmp(arr[0], str2) == 0) {
		free(arr);
		return (0);
	} else
		return (1);
}
