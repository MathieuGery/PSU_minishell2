/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** my_cd.c
*/

#include "mysh.h"
#include "lib.h"

int change_old_pwd(char **env)
{
	char *cwd[256] = {"setenv", "OLDPWD", NULL, NULL};
	char pwd[256];

	if (getcwd(pwd, sizeof(pwd)) == NULL)
		return (-1);
	cwd[2] = pwd;
	set_env(cwd, env);
	return (0);
}

int change_pwd(char **env)
{
	char *cwd[256] = {"setenv", "PWD", NULL, NULL};
	char pwd[256];

	if (getcwd(pwd, sizeof(pwd)) == NULL)
		return (-1);
	cwd[2] = pwd;
	set_env(cwd, env);
	return (0);
}

void change_dir(char **arr, char **env)
{
	int y;
	int i;
	int x = index_path("OLDPWD", env);
	char *str = malloc(sizeof(char) * (my_strlen(env[x])));

	for (y = 0; env[x][y] != '='; y++);
	y++;
	for (i = 0; env[x][y] != '\0'; i++, y++)
		str[i] = env[x][y];
	str[i] = '\0';
	if (str_cmp(arr[1], "-") != 0) {
		change_old_pwd(env);
		if (chdir(arr[1]) == -1)
			my_error(arr[1]);
	} else {
		if (chdir(str) == -1)
			my_error(arr[1]);
	}
	free(str);
}

int cd_command(char **arr, char **env)
{
	int x = 0;
	char *home = find_home(env);

	home += 5;
	while (arr[x] != NULL)
		x++;
	if (x > 2)
		cd_error_args("cd");
	if (x == 1) {
		if (chdir(home) == -1)
			perror("");
	} else if (x == 2) {
		change_dir(arr, env);
		change_pwd(env);
	}
	return (0);
}

char *find_home(char **env)
{
	int x = 0;

	while (env[x] != NULL) {
		if (env[x][0] == 'H' && env[x][1] == 'O' && env[x][2] == 'M' &&
		env[x][3] == 'E')
			return (env[x]);
		x++;
	}
	return (NULL);
}
