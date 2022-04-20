#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void printSum(int);

double sum = 0;

int main() {
    signal(SIGFPE, printSum);
    signal(SIGUSR1, printSum);
    signal(SIGUSR2, printSum);

    printf("Program started with pid %d.\n", getpid());
    printf("Enter a list of doubles to sum,\n");
    printf("and to end the program,\n");
    printf("run one of the following Unix commands:\n");
    printf("  kill -8 %d\n  kill -10 %d\n  kill -12 %d\n", getpid(), getpid(), getpid());

    while (1) {
        double add;
        scanf("%lf", &add);
        sum += add;
    }
}

void printSum(int signum) {
    printf("The sum is %lf.\n", sum);
    printf("The program handled signal from kill -%d %d.\n", signum, getpid());
    exit(signum);
}
