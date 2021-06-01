#include <stdio.h>
#include <unistd.h>

int main(){
    int child_id = fork();
    if(child_id == 0){
        printf("child process id: %d, parent id: %d; from fork id: %d\n", getpid(), getppid(), child_id);
    } else{
        printf("main process id: %d, parent of main process id: %d, id: %d\n", getpid(), getppid(), child_id);
    }
    return 0;

}