#include "../include/shell.h"

int parse_line(char *line, char** args, char** piped_args) {
    char* pipe_pos = strchr(line, '|');
    if(pipe_pos){
        *pipe_pos = '\0';
        parse_command(line, args);
        parse_command(pipe_pos+1, piped_args);
        return 1;
    }
    return 0;
}


int parse_command(char* cmd, char** args){
    char *token;
    int i = 0;
    token = strtok(cmd, " \t\n\r");
    
    if(token == NULL){
        return 0;
    }
    
    while(token && i < MAX_LINE/2){
        args[i] = token;
        token = strtok(NULL, " \t\n\r");
        i++;
    }
    args[i] = NULL;
    return 1;
}

