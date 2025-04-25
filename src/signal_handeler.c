#include "../include/shell.h"

volatile sig_atomic_t foreground_only = 0;

void sigint_handler(int sig) {
    (void)sig;
    printf("\n"); 
}

void setup_signal_handlers() {
    struct sigaction sa;
    
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGINT, &sa, NULL)) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    
    
    sa.sa_handler = SIG_IGN;
    if (sigaction(SIGTSTP, &sa, NULL)) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
}