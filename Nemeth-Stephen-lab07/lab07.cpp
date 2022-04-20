#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//A pointer variable to an int
// initially set to null and not later modified
int * p;

/*
 * Return the sum of the n values in x starting at index 0.
 * Note:  x is a pointer to an array of ints.
 * If x is null, then return -1.
 * If n is 0 and x is not null, then return 0.
 */
int sum(int * x, int n);

/*
 * Main entry into the program, reads in
 * numbers from command line, allocates new space
 * for it in an array, and displays the sum along with
 * other information. Ends by freeing up the space
 * allocated by the array.
 */
int main(int argc, char * argv[]){
  int * x = new int[argc - 1];
  for(int i = 1; i < argc; i++){
    x[i - 1] = stoi(argv[i]);
  }

  cout << "*x is " << x[0] << endl;
  int y = sum(x, argc);
  cout << "y is " << y << endl;
  int z = sum(p, argc);
  cout << "z is " << z << endl;

  delete[] x;
  return EXIT_SUCCESS;
}

int sum(int * x, int n){
  if (x == NULL) {
    return -1;
  }
  if (n == 0 && x != NULL) {
    return 0;
  }
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += x[i];
  }
  return sum;
}
