#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_LINE 1024
/* Parser */
int parse_line(char *line,char** args, char** piped_args);
int parse_command(char* line, char** args);

/* Executer */
int is_builtin(char* cmd);
void execute_builtin(char** args);
void execute_command(char** args);
void execute_pipeline(char** args1, char** args2);

/* Signal Handler */
void setup_signal_handlers();

/* Job Controller */
void add_job(pid_t pid, char *cmd, int foreground);
void check_jobs();

/* Redirection Handler */
void handle_redirection(char** args);

#endif