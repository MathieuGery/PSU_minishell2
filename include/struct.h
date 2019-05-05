/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** struct.h
*/

typedef struct
{
	int output;
} shell_t;

typedef struct
{
	int input;
	int output;
	int first;
	int nb_command;
	char **env;
} pipe_t;
