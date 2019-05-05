/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** get_next_line.c
*/

#include "get_next_line.h"
#include "lib.h"

static char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static char *my_realloc_gnl(char *str, char c)
{
	char *stk;
	int str_size = my_strlen(str);

	stk = malloc(sizeof(char) * (str_size + 1));
	if (!stk)
		return (NULL);
	stk = my_strcpy(stk, str);
	stk[str_size] = '\0';
	str = malloc(sizeof(char) * (str_size + 2));
	if (!str)
		return (NULL);
	str = my_strcpy(str, stk);
	str[str_size] = c;
	str[str_size + 1] = '\0';
	free(stk);
	return (str);
}

char *get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char));
	char *str = malloc(sizeof(char));
	int i = 0;

	if (!buffer || !str)
		exit (84);
	str[0] = '\0';
	buffer[0] = '\0';
	while (buffer[0] != '\n') {
		read(fd, buffer, 1);
		if (!buffer[0])
			return (NULL);
		else if (buffer[0] != '\n')
			str = my_realloc_gnl(str, buffer[0]);
		if (buffer[0] == '\0')
			return (str);
		i++;
	}
	return (str);
}
