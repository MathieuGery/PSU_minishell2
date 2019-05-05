/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** setenv
*/

#include "mysh.h"
#include "lib.h"

int index_path(char *str, char **env)
{
	char *tmp;
	int i = 0;
	int x = 0;

	while (env[x]) {
		while (env[x][i] != '=')
			i++;
		tmp = malloc(sizeof(char) * (i + 1));
		tmp = my_strncpy(tmp, env[x], i);
		if (str_cmp(str, tmp) == 0)
			break;
		x++;
		i = 0;
		free(tmp);
	}
	return (x);
}

int errors_setenv(char **arr, char **env)
{
	if (arr_size(arr) > 3) {
		my_putstr("setenv: Too many arguments.\n");
		return (1);
	}
	if (arr_size(arr) == 1) {
		print_arr(env);
		return (1);
	}
	if (arr[1][0] >= 48 && arr[1][0] <= 57) {
		my_putstr("setenv: Variable name must begin with a letter.\n");
		return (1);
	}
	return (0);
}

int set_env(char **arr, char **env)
{
	int x;
	char *s;
	int stat = 0;

	if (errors_setenv(arr, env) != 0)
		return (1);
	printf("%s\n", arr[1]);
	x = index_path(arr[1], env);
	s = my_strcat(arr[1], "=");
	if (arr[2])
		s = my_strcat(s, arr[2]);
	if (!env[x])
		stat = 1;
	env[x] = s;
	if (stat == 1)
		env[x + 1] = NULL;
	return (0);
}