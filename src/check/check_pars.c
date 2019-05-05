/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** check_pars.c
*/

#include "mysh.h"

int check_char(char *str, char c)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return (0);
	return (1);
}
