/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** my_realloc.c
*/

#include <stdlib.h>
#include "lib.h"

char *my_strcat(char *dest, char *src)
{
	char *ret;
	int i = 0;
	int j = 0;

	ret = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);
	while (dest[i] != '\0') {
		ret[i] = dest[i];
		i++;
	}
	while (src[j] != '\0') {
		ret[i] = src[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
