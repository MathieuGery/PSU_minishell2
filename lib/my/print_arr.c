/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** print_arr
*/

#include <unistd.h>
#include "lib.h"

void print_arr(char **arr)
{
	int x = 0;
	int y = 0;

	while (arr[x] != NULL) {
		my_putstr(arr[x]);
		my_putchar('\n');
		x++;
	}
}
