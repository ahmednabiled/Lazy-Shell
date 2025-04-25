#include "../include/shell.h"

typedef struct {
    pid_t pid;
    char* cmd;
    int job_id;
    int status;
} Job;

Job jobs[100];
int next_job_id = 1;

void check_jobs(){
    int i;
    int status;
    pid_t pid;
    
    while((pid = waitpid(-1, &status, WNOHANG)) > 0){
        for(i=0; i < 100; i++){
            if(jobs[i].pid == pid){
                if(WIFEXITED(status) || WIFSIGNALED(status)){
                    printf("[%d] Done %s\n", jobs[i].job_id,  jobs[i].cmd);
                    free(jobs[i].cmd);
                    jobs[i].pid = 0;
                }
                else if(WIFSTOPPED(status)){
                    printf("[%d] Stopped %s\n", jobs[i].job_id,  jobs[i].cmd);
                }
                break;
            }
        }
    }
}



void add_job(pid_t pid, char *cmd, int is_background) {
    for(int i = 0; i < 100; i++) {
        if(jobs[i].pid == 0) {
            jobs[i].pid = pid;
            jobs[i].cmd = strdup(cmd);
            if (!jobs[i].cmd) {
                perror("strdup failed");
                return;
            }
            jobs[i].job_id = next_job_id++;
            jobs[i].status = is_background ? 0 : 1; 
            
            if(is_background) {
                printf("[%d] %d %s\n", jobs[i].job_id, pid, cmd);
            }
            return;
        }
    }
    fprintf(stderr, "Maximum jobs limit reached\n");
}

