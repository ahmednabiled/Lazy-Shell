#include "../include/shell.h"

int is_builtin(char* cmd){
    return strcmp(cmd, "cd") == 0 ||
           strcmp(cmd, "help") == 0 ||
           strcmp(cmd , "exit") == 0;
}

void execute_builtin(char** args){
    if(strcmp(args[0], "cd") == 0){
        if(args[1] == NULL){
            fprintf(stderr, "cd: missing argument");
        }
        else{
            if(chdir(args[1]) != 0){
                perror("cd failed");
            }
        }
    }
    
    else if(strcmp(args[0], "help") == 0){
        printf("LazySell - A simple Unix shell\n");
        printf("Built-in commands:\n");
        printf("  cd <dir>    - Change directory\n");
        printf("  help        - Show this help\n");
        printf("  exit        - Exit the shell\n");
    }
}

void execute_command(char** args){
    int foreground = 1;
    int i;
    pid_t pid;

    for(i = 0; args[i] != NULL;i++);
    if(i > 0 && strcmp(args[i-1], "&") == 0){
        foreground = 0;
        args[i-1] = NULL;
    }

    pid = fork();
    
    if(pid == -1){
        perror("fork failed");
        return;
    }
    else if( pid == 0){
        handle_redirection(args);
        if(execvp(args[0], args)){
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    }
    else{
        add_job(pid, args[0], foreground);
    }
}
