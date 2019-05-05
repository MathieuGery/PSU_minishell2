/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** check_str.c
*/

#include "mysh.h"

int check_str(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
