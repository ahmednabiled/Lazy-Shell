#include "shell.h"


int main(){
    setup_signal_handlers();
    char line[MAX_LINE];
    char* args[MAX_LINE/2 + 1];
    int should_run = 1;

    printf("\n"
        "██╗      █████╗ ███████╗██╗   ██╗    ███████╗██╗  ██╗███████╗██╗     ██╗     \n"
        "██║     ██╔══██╗╚══███╔╝╚██╗ ██╔╝    ██╔════╝██║  ██║██╔════╝██║     ██║     \n"
        "██║     ███████║  ███╔╝  ╚████╔╝     ███████╗███████║█████╗  ██║     ██║     \n"
        "██║     ██╔══██║ ███╔╝    ╚██╔╝      ╚════██║██╔══██║██╔══╝  ██║     ██║     \n"
        "███████╗██║  ██║███████╗   ██║       ███████║██║  ██║███████╗███████╗███████╗\n"
        "╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝       ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"
        "\n");

    while (should_run)
    {
        printf("Lazy shell $ ");
        fflush(stdout);

        if(fgets(line, MAX_LINE, stdin) == NULL){
            break;
        }

        parse_line(line, args);
        
        if(args[0] == NULL){
            continue;
        }

        if(strcmp(args[0], "exit") == 0){
            should_run = 0;
        }
        else if(is_builtin(args[0])){
            execute_builtin(args);
        }
        else{
            execute_command(args);
        }

    }
    return 0;

}

