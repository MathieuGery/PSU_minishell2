/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** str_to_word_array2.c
*/

#include <unistd.h>
#include <stdlib.h>

static int nb_words(char *str, char c)
{
	int ret = 0;
	int i = 0;

	if (str[0] != c && str[0] != '\0')
		ret++;
	while (str[i] != '\0') {
		while (str[i] == c) {
			i++;
			((str[i] != c && str[i] != '\0') ? ret++ : ret == ret);
		}
		i++;
	}
	return (ret);
}

static int word_len(char *str, int i, char sepa)
{
	int a = 0;

	while (str[i] != sepa && str[i] != '\0') {
		a++;
		i++;
	}
	return (a);
}

char **str_to_word_array2(char *str, char c)
{
	int x = 0;
	int y = 0;
	int n = 0;
	char **arr = malloc(sizeof(char *) * (nb_words(str, c) + 1));

	for (x = 0; x != nb_words(str, c); x++, n++) {
		while (str[n] == c)
			n++;
		if (str[n] == '\0' || x == nb_words(str, c)) {
			arr[x + 1] = NULL;
			return (arr);
		}
		arr[x] = malloc(sizeof(char) * (word_len(str, n, c) + 1));
		while (str[n] != c && str[n] != '\0')
			arr[x][y++] = str[n++];
		arr[x][y] = '\0';
		y = 0;
	}
	arr[x] = NULL;
	return (arr);
}
