#include "shell.h"

void handle_redirection(char** args){
    int i;
    int in_fd = -1, out_fd = -1;
    char* input_file = NULL, *output_file = NULL;
    
    for(i = 0; args[i] != NULL; i++){
        if(strcmp(args[i], "<") == 0){
            input_file = args[i+1];
            args[i] = NULL;
            i++;
        }
        else if(strcmp(args[i], ">") == 0){
            output_file = args[i+1];
            args[i] = NULL;
            i++;
        }
    }
    
    if(input_file){
        in_fd = open(input_file, O_RDONLY);
        if(in_fd < 0){
            perror("open input file");
            exit(EXIT_FAILURE);
        }
        dup2(in_fd, STDIN_FILENO);
        close(in_fd);
    }
    
    if(output_file){
        out_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(out_fd < 0){
            perror("open output file");
            exit(EXIT_FAILURE);
        }
        dup2(out_fd, STDOUT_FILENO);
        close(out_fd);
    }
    
    
}
