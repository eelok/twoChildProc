#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(){
    int parent_id = 0;
    int firstChild_id = 0, secondChild_id = 0;

    int forkFistChild = fork();
    parent_id = getpid();

    if (forkFistChild == 0) { //Frist Child
        firstChild_id = getpid();
        parent_id = getppid();
        while (1) {                        
            printf("First Child ID %d; its parent: %d\n", firstChild_id, parent_id);
            sleep(1);
        }
    } else { //Parent Process
        int forkSecondChild = fork();
        if(forkSecondChild == 0){ //Second Child
            secondChild_id = getpid();
            for (int i = 0; i < 6; i++) {
                sleep(1);
                printf("Second Child ID %d; its parent: %d>>i=%d\n", secondChild_id, getppid(), i);
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