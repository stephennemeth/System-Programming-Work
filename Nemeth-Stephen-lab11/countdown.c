#include <stdlib.h>
#include <stdio.h>

/*
* Main entrance into the program, takes in an integer as a 
* command line argument and counts down from it until 1.
*/
int main(int argc, char * argv[]) {
    for (int i = atoi(argv[1]); i > 0; i--) {
        printf("%d\n", i);
    }
    printf("Countdown is finished.\n");
    return 0;
}

