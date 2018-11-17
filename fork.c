#include <stdio.h>
#include <unistd.h>   //for fork, sleep
#include <sys/wait.h> //for wait, waitpid
#include <stdlib.h>   //for rand, srand

int main() {
    printf("\nGranddaddy of them all: %i\n", getppid() );

    printf("\n========== FORKED ==========\n");

    srand(getpid());
    int time = rand() % 16 + 5; // get seconds [5, 20]
    
  
    int f = fork();  //parent and child

    if (f == -1) {
        printf("Errno: %d. Exiting.\n", f);
        // to return 0;
    }

    // CHILD PROCESS
    else if (!f) {  // if f=0 : no child
        printf( "\n=== CHILD  PROCESS ===\n" );
        printf( "[CHILD]: I am a child! My pid is %i.\n", getpid() );
        sleep(time);
        printf( "[CHILD]: Child process finished.\n\n" );
    }

    else {  // if has child (f is not 0, is child pid)
        printf( "\n=== PARENT PROCESS ===\n" );
        int *status;
        waitpid(f, status, 0);
        printf( "[PARENT]: Child finished, pid: %i\tSleep time: %i\n", f, time);
        printf( "[PARENT]: Parent is done. Ending program.\n\n" );
        // to return 0;
    }

    return 0;
}
