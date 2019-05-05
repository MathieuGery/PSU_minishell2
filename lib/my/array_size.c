/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** array_size.c
*/

#include <unistd.h>

int arr_size(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++);
	return (i);
}