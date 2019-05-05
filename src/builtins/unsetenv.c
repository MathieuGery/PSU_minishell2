/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** unsetenv.c
*/

#include "mysh.h"
#include "lib.h"

static int errors_unsetenv(char **arr)
{
	if (arr_size(arr) <= 1) {
		my_putstr("unsetenv: Too few arguments.\n");
		return (1);
	}
	return (0);
}

int my_unsetenv(char **arr, char **env)
{
	int x;

	if (errors_unsetenv(arr) != 0)
		return (1);
	x = index_path(arr[1], env);
	for (int i = 0; i != arr_size(arr); i++) {
		x = index_path(arr[i], env);
		for (x = x; env[x] != NULL; x++)
			env[x] = env[x + 1];
	}
	return (0);
}