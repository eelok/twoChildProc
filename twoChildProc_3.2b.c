#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(){
    int parent_id;
    int firstChild_id, secondChild_id;

    parent_id = getpid();

    if ((firstChild_id = fork()) == 0) { //First Child
        firstChild_id = getpid();
        
        while (1) {                        
            printf("First Child ID %d; its parent: %d\n", firstChild_id, parent_id);
            sleep(1);
        }
    } else { //Parent Process
        if((secondChild_id = fork())== 0){ //Second Child
            secondChild_id = getpid();
            for (int i = 0; i < 6; i++) {
                sleep(1);
                printf("Second Child ID %d; its parent: %d\n", secondChild_id, getppid());
            }
            printf("Kill PID: %d\n", firstChild_id);
            kill(firstChild_id, 15);
            printf("Exit PID: %d\n", secondChild_id); 
        } else {//Parent Process
            for (int i = 0; i < 10; i++){
                printf("Parent ID %d\n", getpid());
                sleep(1);
            }
        }
    }
    return 0;
}