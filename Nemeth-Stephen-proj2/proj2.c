#include <stdio.h>
#include <stdlib.h>

void printPrompt();
void getInput();
double * increaseSize(double *);
void endPrompt(double *);
double getAverage(double *);

//used to count the number of grade that have been entered
int numGrade = 0;
//Used to count the number of times space had to be created in the heap
int numAlloc = 0;
//Used to count the number of times space was freed back to the heap
int numFree = 0;
//Used to count the number of bytes that need to be allocated in the heap
int numBytes = 0;
//Used to count the total number of bytes that have been allocated in the heap
int totalBytes = 0;

/*
 * Main entry point into the program, simply calls the printPrompt() function
 * which delegates to other functions to get grade input and print all necessary
 * messages as space is allocated in the heap. Takes in no arguments and finishes
 * with an exit status of 0 as its return value.
 */
int main() {
    printPrompt();
    return 0;
}

/*
 * Prints the beginning prompt of the program telling the user how the program works.
 * Then calls the getInput() function to get grade input and also delegates to other functions
 * for the ending messages. Takes in no arguments and has not return type.
 */
void printPrompt() {
    printf("Enter a list of grades below where each grade is separated by a newline character.\n");
    printf("After the last grade is entered, enter a negative value to the end of the list.\n");
    getInput();
}

/*
 * This is the main function that is used for getting grade input from the user. Uses a do-while
 * loop and checks if the grade that is entered is >= 0, if not the loop is terminated and the
 * ending prompts are called. The main form of data storage is a pointer to a double called pointer.
 * If the number of grades entered is divisible by 5 or is equal to 1, an extra 5 spaces in the
 * heap is allocated for pointer to house more grades. pointer is initially set to null, because
 * space may not be needed for it yet, but when valid input is entered for the first time, five
 * doubles are allocated in the heap for pointer to store. After five grades are entered, the space
 * in the heap is full and if the user enters another grade, more space is allocated from the heap,
 * grades are copied over to the new space and the old space is freed back to the system. This
 * process repeates until the user enters a negative value where the end messages are displayed.
 * This function takes in no values and has no return type.
 */
void getInput() {
    double grade;
    double * pointer = NULL; //set to null intially because space may not need to be allocated.
    do {
        scanf("%lf", &grade);
        if (grade >= 0) {
            numGrade++; //increase the number of grades
            if (numGrade % 5 == 0 || numGrade == 1) {
                if (numGrade >= 5) { // if the number of grades is big enough that means the space allocated needs to be increased
                    *(pointer + (numGrade - 1)) = grade;
                    printf("Stored %lf in the heap at %p.\n", grade, (void *) (pointer + (numGrade - 1)));
                    printf("Stored %d grades (%d bytes) to the heap at %p.\n", numGrade, numBytes, (void *) pointer);
                    printf("Heap at %p is full.\n", (void *) pointer);
                }
                pointer = increaseSize(pointer); //pointer now points to a larger block of memory in the heap
                if (numGrade == 1) {
                    *(pointer + (numGrade - 1)) = grade;
                    printf("Stored %lf in the heap at %p.\n", grade, (void *) (pointer + (numGrade - 1)));
                }
            } else {
                *(pointer + (numGrade - 1)) = grade;
                printf("Stored %lf in the heap at %p.\n", grade, (void *) (pointer + (numGrade - 1)));
            }
        }
    } while (grade >= 0);
    endPrompt(pointer);
}

/*
 * This function prints the ending messages of the program. It takes in
 * a pointer to a double which is being used as the array of grades that the user entered.
 * Calls the function getAverage() to find the average of the grades and prints out each grade
 * indicating whether it is >= or < the average. Then prints then finally frees up the space
 * in the heap pointer has allocated. Then prints a summary of the heap usages with the number
 * of allocations, number of frees, and total number of bytes allocated. This function has no
 * return type.
 */
void endPrompt(double * pointer) {
    double average = 0;
    average = getAverage(pointer);
    printf("The average of %d grades is %lf\n", numGrade, average);
    if (numGrade > 0) {
        for (unsigned int i = 0; i < numGrade; i++) {
            if (*(pointer + i) >= average) {
                printf("%d. The grade of %lf is >= the average.\n", i + 1, *(pointer + i));
            } else {
                printf("%d. The grade of %lf is < the average.\n", i + 1, *(pointer + i));
            }
        }
        printf("Freed %d bytes from the heap at %p.\n", numBytes, (void *) pointer);
        free(pointer);
        numFree++;
    }
    printf("total heap usage: %d allocs, %d frees, %d bytes allocated\n", numAlloc, numFree, totalBytes);
}

/*
 * This function finds the average of the grades pointer is pointing to
 * in the heap. It takes in a pointer to a double that acts as an array of
 * doubles. It returns a double represting the average. If the number of
 * grades the user entered is zero, this function returns zero.
 */
double getAverage(double * pointer) {
    if (numGrade == 0) {
        return 0;
    }
    double sum = 0;
    for (unsigned int i = 0; i < numGrade; i++) {
        sum += *(pointer + i);
    }
    return sum / numGrade;
}

/*
 * This is the function that is used to increase the size of the pointer
 * used to house all the grade items. If there is only 1 grade entered, 5
 * spaces for doubles are allocated in the heap in a temporary pointer and
 * is then returned, which pointer then equals. If greater than or equal to 5
 * grades have been entered, the same space plus 5 extra double spaces are made
 * available in the heap for a temporary pointer. Everything from the original
 * pointer is then copied over, messages are then displayed, the space from
 * the original pointer is freed and the temp pointer is returned, which pointer
 * in the getInput() function is then assigned to. This fucntion takes in a pointer
 * to a double and returns a pointer to a double.
 */
double * increaseSize(double * pointer) {
    double a = 0;
    int doubleSize = sizeof a; // used to keep track of the size of a double in the system
    numBytes = numGrade == 1 ? doubleSize * 5 : doubleSize * (numGrade + 5);
    totalBytes += numBytes;
    double * temp = malloc(numBytes);
    numAlloc++;
    printf("Allocated %d bytes to the heap at %p.\n", numBytes, (void *) temp);
    if (numGrade >= 5) {
        for (unsigned int i = 0; i < numGrade; i++) {
            *(temp + i) = *(pointer + i); // everything in the original pointer is copied to the new on
        }
        printf("Copied %d grades from %p to %p.\n", numGrade, (void *) pointer, (void *) temp);
        printf("Freed %d bytes from the heap at %p.\n", (40 * (numGrade / 5)), (void *) pointer);
        free(pointer); // the space from the original pointer is freed to avoid a memory leak
        numFree++;
    }
    return temp; // this returns the pointer which is then pointer in getInput() is then assgined
    //to making that pointer have all the same grades and a bigger size than it did originally
}
