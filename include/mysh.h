/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** my.h
*/

#ifndef MYSH_H
#define MYSH_H

#include "struct.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int l_pip(char **, pipe_t *, shell_t *, int);
void pipe_error(shell_t *, char **);
int process(char **, char **, shell_t *);
int pipe_redir(char *, char **, shell_t *);
int execc(char *, char **, shell_t *);
int check_char(char *, char);
int consol(char **);
void print_arr(char **);
int str_cmp(char *, char *);
int check(char **, char **, shell_t *);
int check_exit(char **);
int check_str(char *);
char **find_path(char **);
void free_arr(char **);
char **proc(char **, char **);
int cd_command(char **, char **);
int str_cmp_cd(char *, char *);
void cd_error(char *);
void cd_error_args(char *);
void my_error(char *);
void my_putstr_error(char *);
int set_env(char **, char **);
int my_unsetenv(char **arr, char **env);
int index_path(char *str, char **env);
int check_args_setenv(char **arr);
char *directory(char **);
int pointer_dep(char *);
char *find_home(char **);
int handle_sem(char *, char **, shell_t *);
pipe_t init_pipe(pipe_t, char **);
char **prepare_command(char **, char *, char **);
int check_cmd(char **);
int exec_exit(char **arr, shell_t *shell);

#endif
