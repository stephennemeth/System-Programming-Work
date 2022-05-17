#include <stdio.h>
#include <stdlib.h> //srand(), rand()
#include <time.h> //time()
#include <sys/time.h> //clock_gettime()

// Number of rows
const int numRows = 10000;

// Number of columns
const int numCols = 10000;

/*
 * Print the 2D array of ints pointed by
 * x, where r is the number of rows
 * and c is the number of columns.
 */
void printArray(int ** x, int r, int c){
  printf("numRows = %d\nnumCols = %d\n", r, c);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", x[i][j]);
    }
    printf("\n");
  }
}

/*
 * Pseudorandomly initialize the 2D array 
 * of ints pointed by x, 
 * where r is the number of rows
 * and c is the number of columns.
 */
void initialize(int ** x, int r, int c){
  //Seed rand() with timestamp
  //srand(time(0));
  //Seed rand() with 7
  srand(7);
  for(int i = 0; i < numRows; i++){
    x[i] = (int *) malloc(numCols * sizeof(int));
  }  
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      //Initialize to pseudorandom
      //  value between 0 and 9 (inclusive)
      x[i][j] = rand() % 10;
    }
  }
}

/*
 * Sum all of the integers in x.
 */
long sumAll(int ** x, int r, int c){
  long sum = 0;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      sum += x[i][j];
    }
  }
  return sum;
}

/*
 * Free up heap space.
 * Precondition: x was allocated
 * space on the heap for r rows 
 * of a 2D array of ints.
 */
void freeHeap(int ** x, int r){
  for(int i = 0; i < r; i++){
    free(x[i]);
  }
  free(x);
}

/*
 * Uses a single thread of execution
 * to sum up the values in a 2D array.
 */
int main(int argc, char * argv[]){  
  int ** a = (int **) malloc(numRows * sizeof(int *));
  initialize(a, numRows, numCols);
  //printArray(a, numRows, numCols);
  struct timeval start, end;	// start and end time
  unsigned long e_usec;	// elapsed microseconds
  gettimeofday(&start, 0); //mark the start time
  long sum = sumAll(a, numRows, numCols);
  gettimeofday(&end, 0); //mark the end time
  printf("All values sum: %ld\n", sum);
  e_usec = ((end.tv_sec * 1000000) + end.tv_usec) -
    ((start.tv_sec * 1000000) + start.tv_usec);
  printf("elapsed time: %lu microseconds\n", e_usec);
  freeHeap(a, numRows);
  return 0;
}


