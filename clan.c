#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    int parent_id, firstChild_id, secondChild_id;
    int child_From_firstChild_id, child_From_secondChild_id;
    int secondChild_from_firstChild_id;

    parent_id = getpid();

    if( (firstChild_id = fork()) == 0){ //First child
        firstChild_id = getpid();
        for(int i = 0; i < 3; i++){
            printf("First child ID: %d; its Parent ID: %d\n", firstChild_id, parent_id);
            sleep(1);
        }
        if((child_From_firstChild_id = fork()) == 0){ //Child from First child
            child_From_firstChild_id = getpid();
            for(int i = 0; i < 3; i++){
                printf("Child from FIRST CHILD: ID %d; its Parent ID: %d\n", child_From_firstChild_id, getppid());
                sleep(1);
            }
        } else{//First child
            for(int i = 0; i < 3; i++){
                printf("Frist Child ID: %d; its Parent ID %d\n", getpid(), getppid());
                sleep(1);
            }
            if((secondChild_from_firstChild_id = fork()) == 0){//Second Child From First Child
                for(int i = 0; i < 3; i++){
                    printf("Second Child from First Child ID: %d, its Parent ID%d, \n",getpid(), getppid());
                    sleep(1);
                }
            }else{//First child
                printf("Frist Child ID: %d, Its Parent ID: %d, \n", getpid(), getppid());
                sleep(1);
            }

        }
    } else if((firstChild_id = fork()) > 0){ //Parent
        if((secondChild_id = fork()) == 0){ //Second Child
            secondChild_id = getpid();
            for(int i = 0; i < 3; i++) {
                printf("Second child ID: %d; its Parent ID: %d\n", getpid(), parent_id);
                sleep(1);
            }
            if((child_From_secondChild_id = fork()) == 0){ //first child from second child
                child_From_secondChild_id = getpid();
                for(int i = 0; i < 3; i++){
                    printf("Child from Second Child ID: %d, its Parent ID: %d,\n",child_From_secondChild_id, getppid());
                    sleep(1);               
                }
            }
        } else{///Parent
            for(int i = 0; i < 3; i++){
                printf("Parent ID: %d\n", getpid());
                sleep(1); 
            }
        }
    }
    exit(0);
}

