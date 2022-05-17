#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/*
* This function is the function that will print
* when a kill signal of type 8,10, or 12 is sent to the 
* process. It will print out the sum and the kill command
* that was sent to terminate the program and then exit.
*/
void finishPrint(int signal);

/* 
* A global variable that will be used 
* to keep track of the running sum as input 
* is entered into the program.
*/
double sum = 0;

/*
* Main entrace into the rpogram. Prints out an
* opening prompt and the commands to kill the process.
* Also takes in user input validates that they are numeric
* and adds it to a running sum. If input comes from a file,
* fgets() will read the EOF character and will exit the loop
* and wait for 60 seconds for a kill signal or will execute the function
* finishPrint().
*/
int main(int argc, char * argv[]) {
    int pid = getpid();
    printf("Program stated with pid = %d.\n", pid);
    printf("Enter a list of doubles to sum,\nand to end the program,\nrun one of the following Unix commands:\n");
    printf("  kill -8 %d\n  kill -10 %d\n  kill -12 %d\n", pid, pid, pid);
    signal(SIGFPE, finishPrint);
    signal(SIGUSR1, finishPrint);
    signal(SIGUSR2, finishPrint);
    char line[1024];
    double add = 0;
    int returnVal = 0;
    int run = 1;
    while (run) {
        char * check = NULL;
        check = fgets(line, sizeof line, stdin);
        if (check == NULL) {
            run = 0;
        } else {
            returnVal = sscanf(line, "%lf", &add);
            if (returnVal) {
                sum += add;
            } else {
                printf("Error: please input a numeric value.\n");
            }
        }
    }
    sleep(60);
    finishPrint(0);
}

void finishPrint(int signal) {
    printf("The sum is %lf.\n", sum);
    if (signal == 0) {
        printf("Program ended after sleeping for 60 seconds.\n");
    } else {
        printf("Program ended by handling the signal from kill -%d %d.\n", signal, getpid());
    }
    exit(signal);
}


