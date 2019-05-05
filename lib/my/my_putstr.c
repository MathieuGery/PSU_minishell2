/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** afficher un string
*/

#include "lib.h"

int my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
