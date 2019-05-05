/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** exit.c
*/

#include "mysh.h"
#include "lib.h"

int exit_error(char *str)
{
	if (str[0] >= 48 && str[0] <= 57 && my_strlen(str) >= 2)
		if (str[1] < 48 || str[1] > 57)
			return (2);
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < 48 || str[i] > 57)
			return (1);
	return (0);
}

int exec_exit(char **arr, shell_t *shell)
{
	if (arr_size(arr) <= 1) {
		shell->output = 0;
		return (1);
	}
	if (exit_error(arr[1]) == 1 || arr_size(arr) >= 3) {
		my_putstr("exit: Expression Syntax.\n");
		return (0);
	}
	if (exit_error(arr[1]) == 2) {
		my_putstr("exit: Badly formed number.\n");
		return (0);
	}
	else
		shell->output = my_getnbr(arr[1]);
	return (1);
}