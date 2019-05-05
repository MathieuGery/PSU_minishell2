/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** console.c
*/

#include "my.h"
#include "get_next_line.h"

int process(char **arr, char **env)
{
	pid_t pid;
	int werror;

	pid = fork();

	if (pid == -1)
		perror("fork");
	else if (pid == 0 && execve(arr[0], arr, env) == -1) {
		my_putstr(arr[0]);
		my_putstr(": Command not found.\n");
		exit(EXIT_FAILURE);
	} else
		waitpid(pid, &werror, 0);
	if (WTERMSIG(werror) == 11)
		my_putstr("Segmentation fault\n");
	if (WTERMSIG(werror) == 8)
		my_putstr("Floating execption\n");
}

int consol(char **env)
{
	char *s;
	char **str;
	char **arr;

	directory(env);
	while (s = get_next_line(0)) {
		arr = str_to_word_array(s);
		if (check_str(s) == 0) {
			if (check(arr, env) == 1)
				break;
			else if (check_exit(arr, env) == 0) {
				str = proc(arr, env);
				if (str != NULL)
					process(str, env);
			}
		}
		free(s);
		free(arr);
		directory(env);
	}
	if (s == NULL)
		my_putstr("exit\n");
	return (0);
}

char *directory(char **env)
{
	char *str;
	char cwd[256];
	int i = 0;
	int x = 0;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("");
	i = pointer_dep(cwd);
	str = malloc(sizeof(char) * (my_strlen(cwd) + 1));
	while (cwd[i] != '\0') {
		str[x] = cwd[i];
		i++;
		x++;
	}
	str[x] = '\0';
	my_putstr(str);
	my_putstr("$> ");
	free(str);
	return (str);
}

int pointer_dep(char *cwd)
{
	int i = 0;

	while (cwd[i] != '\0')
		i++;
	i--;
	while (cwd[i] != '/')
		i--;
	return (i + 1);
}
