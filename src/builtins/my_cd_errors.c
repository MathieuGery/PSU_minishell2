/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** my_cd_errors.c
*/

#include "mysh.h"
#include "lib.h"

void my_error(char *str)
{
	char *ermsg;

	if (str != NULL) {
		my_putstr_error(str);
		my_putstr_error(": ");
		ermsg = strerror(errno);
		my_putstr_error(ermsg);
		my_putstr_error(".\n");
	}
}

void my_putstr_error(char *str)
{
	int i;

	i = my_strlen(str);
	write(2, str, i);
}

void cd_error_args(char *str)
{
	my_putstr_error(str);
	my_putstr_error(": Too many arguments.\n");
}
