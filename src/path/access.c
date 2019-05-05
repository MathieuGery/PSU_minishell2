/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** access.c
*/

#include "mysh.h"
#include "lib.h"

char **find_path(char **env)
{
	int x = 0;
	char **arr;

	while (env[x] != NULL) {
		if (env[x][0] == 'P' && env[x][1] == 'A' && env[x][2] == 'T' &&
		env[x][3] == 'H'){
			arr = str_to_word_array2(env[x] + 5, ':');
			return (arr);
		}
		x++;
	}
	return (NULL);
}

char **proc(char **arr, char **env)
{
	char **path;
	char *str;
	char *str2;

	path = find_path(env);
	if (path == NULL)
		return (arr);
	for (int x = 0; path[x] != NULL; x++) {
		if (arr[0][0] != '/' && arr[0][0] != '.') {
			str = my_strcat(path[x], "/");
			str2 = my_strcat(str, arr[0]);
			if (access(str2, X_OK) == 0) {
				arr[0] = str2;
				return (arr);
			}
		free(str);
		free(str2);
		}
	}
	return (arr);
}
