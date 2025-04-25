#include "shell.h"


void parse_line(char *line,char** args){
    char *token;
    int i = 0;
    token = strtok(line, " \t\n\r");
    
    while(token && i < MAX_LINE/2){
        args[i] = token;
        token = strtok(NULL, " \t\n\r");
        i++;
    }
    
    args[i] = NULL;
}

