/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *str, char const *str2, int i)
{
	int x = 0;
	int y = 0;

	while (x != i) {
		str[y] = str2[y];
		y++;
		x++;
	}
	str[y] = '\0';
	return (str);
}