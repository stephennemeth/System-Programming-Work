#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
* Main entrance into the program.
* Takes in an integer as a command line argument, forks and the child proces
* calls the ps command. Once the child process is done, the parent process
* calls ./countdown.out with the command line argument and conuts down from
* the integer passed in down to 1.
*/
int main(int argc, char * argv[]) {
    int waitstatus = 1;
    printf("The parent's pid is %d\n", getpid());
    printf("The parent is now forking\n");
    int i = fork();
    if (i < 0) {
        printf("The call to fork failed\n");
        exit(1);
    }
    if (i == 0) {
        printf("The childs pid is %d\n", getpid());
        printf("The child is executing ps\n");
        char * arguments[] = {"ps", NULL, NULL};
        execvp("ps", arguments);
    } else {
        wait(&waitstatus);
        printf("The parent is waiting for the child to complete\n");
        printf("The parent is executing ./coutdown.out %d.\n", atoi(argv[1]));
        char * arguments[] = {"./countdown.out", argv[1], NULL};
        execvp("./countdown.out", arguments);
    }
    return 0;
}