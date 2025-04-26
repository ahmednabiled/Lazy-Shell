#include "../include/shell.h"

void setup_signal_handlers() {
    struct sigaction sa = {0};
    sa.sa_handler = SIG_IGN;  
    sa.sa_flags   = SA_RESTART;    


    if (sigaction(SIGINT,  &sa, NULL) == -1) {
        perror("sigaction(SIGINT)");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGTSTP, &sa, NULL) == -1) {
        perror("sigaction(SIGTSTP)");
        exit(EXIT_FAILURE);
    }
}
