/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** minishell.c
*/

#include "get_next_line.h"
#include "mysh.h"
#include "lib.h"

void signal_handle(int __attribute__((unused)) error)
{
	my_putstr("\n[minishell2]$ ");
}

int main(int ac, char __attribute__((unused)) **av, char **env)
{
	signal(SIGINT, signal_handle);
	if (ac != 1)
		return (84);
	if (env != NULL && ac == 1)
		return (consol(env));
	return (0);
}
