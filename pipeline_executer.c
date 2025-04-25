#include "shell.h"

void execute_pipeline(char** args1, char** args2){
    int pipefd[2];
    pid_t pid1, pid2;
    
    if(pipe(pipefd) < 0){
        perror("pipe failed");
        return;
    }
    
    pid1 = fork();
    if(pid1 < 0){
        perror("fork failed");
    }
    else if(pid1 == 0){
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        
        if(execvp(args1[0],args1)){
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    }
    
    pid2 = fork();
    if(pid2 < 0){
        perror("fork failed");
    }
    else if(pid2 == 0){
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        
        if(execvp(args2[0],args2)){
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    }
    
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}