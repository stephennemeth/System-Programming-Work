#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> //srand(), rand()
#include <time.h> //time()
#include <sys/time.h> //clock_gettime()

//Number of rows
const int numRows = 10000;

//Number of columns
const int numCols = 10000;

/*
 * struct for passing multiple arguments
 * to the pthread_create system call
 */
struct pthread_create_args {
  int ** x;
  long sum;
};

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
  for(int i = 0; i < r; i+=1){
    for(int j = 0; j < c; j++){
      //Initialize to pseudorandom
      //  value between 0 and 9 (inclusive)
      x[i][j] = rand() % 10;
    }
  }
}

/*
 * If evenRows is 1, return the sum 
 * of the even indexed rows in x;
 * otherwise, return the sum 
 * of the odd indexed rows in x.
 */
long sum(int ** x, int r, int c, int evenRows){
  long sum = 0;
  if(evenRows == 1){ //sum even indexed rows
    for(int i = 0; i < r; i+=2){
      for(int j = 0; j < c; j++){
	sum += x[i][j];
      }
    }
  }
  else{  //sum odd indexed rows
    for(int i = 1; i < r; i+=2){
      for(int j = 0; j < c; j++){
	sum += x[i][j];
      }
    }
  }
  return sum;
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
 * This function is called by the second thread 
 * to sum the even indexed rows
 */
void * thread2_work(void * args){
  struct pthread_create_args * pArgs = (struct pthread_create_args *) args;
  pArgs->sum = sum(pArgs->x, numRows, numCols, 1);
  unsigned long threadId = (unsigned long) pthread_self();
  printf("second thread, thread id = %lu, finished summing the even rows\n", threadId);
  return NULL;
}

/*
 * Create a second thread of execution using pthread_create
 * and pthread_join to split the task of summing up the
 * values in a 2D array.
 */
int main(int argc, char * argv[]){  
  int ** a = (int **) malloc(numRows * sizeof(int *));
  initialize(a, numRows, numCols); 

  struct timeval start, end;	// start and end time
  unsigned long e_usec;	// elapsed microseconds
  gettimeofday(&start, 0); // mark the start time 

  long evenRowSum = 0, oddRowSum = 0;
  //printf("evenRowSum: %ld, oddRowSum: %ld\n", evenRowSum, oddRowSum);
  struct pthread_create_args pArgs;
  pArgs.x = a;
  pArgs.sum = evenRowSum;

  //pthread2 is a reference to the second thread
  pthread_t pthread2;

  //create a second thread which executes thread2_work(&pArgs) 
  if(pthread_create(&pthread2, NULL, thread2_work, &pArgs) != 0) {
    fprintf(stderr, "Error creating thread\n");
    return 1;
  }
  oddRowSum = sum(a, numRows, numCols, 0);
  unsigned long threadId = (unsigned long) pthread_self();
  printf("first thread,  thread id = %lu, finished summing the odd rows\n", threadId);

  //wait for the second thread to finish
  if(pthread_join(pthread2, NULL) != 0) {
    fprintf(stderr, "Error joining thread2 with the first thread\n");
    return 2;
  }
  evenRowSum = pArgs.sum;

  long allRowSum = evenRowSum + oddRowSum;
  gettimeofday(&end, 0);	/* mark the end time */
  printf("evenRowSum: %ld, oddRowSum: %ld\n", evenRowSum, oddRowSum);
  printf("All values sum: %ld\n", allRowSum);
  e_usec = ((end.tv_sec * 1000000) + end.tv_usec) -
    ((start.tv_sec * 1000000) + start.tv_usec);
  printf("elapsed time: %lu microseconds\n", e_usec);
  freeHeap(a, numRows);
  return 0;
}


