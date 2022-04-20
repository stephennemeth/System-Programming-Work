/*
 *  The purpose of this file is to test out bubbleSort
 *  functions in lab06.h.
 */

#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include "lab06.h"

using std::vector;
using std::array;
using std::string;
using std::cout;
using std::endl;

/*
 *  Print the contents of a built-in array,
 *  a C++ array, or a vector x of size n,
 *  and print its name.
 */
template<typename T, size_t n>
void print(T &x, string name);

/*
 *  Return true if x < y; otherwise return false;
 */
template<typename T>
bool lessThan(T x, T y);

/*
 *  Return true if x > y; otherwise return false;
 */
template<typename T>
bool greaterThan(T x, T y);

/*
 *  Return false regardles of input.  This
 *  function is used to test that a sorting
 *  method should do nothing (no swapping).
 */
template<typename T>
bool doNothing(T x, T y);

//Test functions with a vector, C++ array, and built-in array of ints
void test1();

//Test functions with a vector, C++ array, and built-in array of chars
void test2();

//Test functions with a vector, C++ array, and built-in array of strings
void test3();

//Test functions with a vector, C++ array, and built in array of doubles
void test4();

//Test functions with a vector, C++ array, and built in array of floats
void test5();

//Test functions with a vector, C++ array, and a built in array of longs
void test6();

//Run a few tests
int main(){
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  return EXIT_SUCCESS;
}

template<typename T, size_t n>
void print(T &x, string name){
  int size = (int) n;
  cout << name << " = [";
  for(int i = 0; i < size - 1; i++){
    cout << x[i] << ", ";
  }
  cout << x[size - 1] << ']' << endl;
}

template<typename T>
bool lessThan(T x, T y){
  if(x < y){ return true; }
  else { return false; }
}

template<typename T>
bool greaterThan(T x, T y){
  if(x > y){ return true; }
  else { return false; }
}

template<typename T>
bool doNothing(T x, T y){
  return false;
}

void test1(){
  cout << "test1" << endl;
  vector<int> x = {-9, 28, 1, 17, 0, 17, 17, 28};
  array<int, 8> y = {-9, 28, 1, 17, 0, 17, 17, 28};
  int z [8] = {-9, 28, 1, 17, 0, 17, 17, 28};
  print<vector<int>, 8>(x, "x");
  print<array<int, 8>, 8>(y, "y");
  print<int[8], 8>(z, "z");
  bubbleSort(x, lessThan);
  bubbleSort(y, lessThan);
  bool (* less)(int, int) = &lessThan<int>;
  bubbleSort(z, less);
  print<vector<int>, 8>(x, "x");
  print<array<int, 8>, 8>(y, "y");
  print<int[8], 8>(z, "z");
}

void test2(){
  cout << "test2" << endl;
  vector<char> x = {'z', 'b', 'A', 'p', 'a', 'a', 'q', '0', 'o', 'O', '2'};
  array<char, 11> y = {'z', 'b', 'A', 'p', 'a', 'a', 'q', '0', 'o', 'O', '2'};
  char z [11] = {'z', 'b', 'A', 'p', 'a', 'a', 'q', '0', 'o', 'O', '2'};
  bool (* g)(char, char) = &greaterThan<char>;
  bubbleSort(x, g);
  bubbleSort(y, g);
  bubbleSort(z, g);
  print<vector<char>, 11>(x, "x");
  print<array<char, 11>, 11>(y, "y");
  print<char[11], 11>(z, "z");
  bool (* less)(char, char) = &lessThan<char>;
  bubbleSort(x, less);
  bubbleSort(y, less);
  bubbleSort(z, less);
  print<vector<char>, 11>(x, "x");
  print<array<char, 11>, 11>(y, "y");
  print<char[11], 11>(z, "z");
}

void test3(){
  cout << "test3" << endl;
  vector<string> x = {"Zoey", "Worf", "Data", "Picard", "Janeway", "Sisco", "Spock"};
  array<string, 7> y = {"Zoey", "Worf", "Data", "Picard", "Janeway", "Sisco", "Spock"};
  string z [7] = {"Zoey", "Worf", "Data", "Picard", "Janeway", "Sisco", "Spock"};
  bool (* noSwap)(string, string) = &doNothing<string>;
  bubbleSort(z, noSwap);
  print<string[7], 7>(z, "z");
  bool (* gt)(string, string) = &greaterThan<string>;
  bubbleSort(x, gt);
  bubbleSort(y, gt);
  bubbleSort(z, lessThan);
  print<vector<string>, 7>(x, "x");
  print<array<string, 7>, 7>(y, "y");
  print<string[7], 7>(z, "z");
}

void test4(){
  cout << "test4" << endl;
  vector<double> x = {2.9, 1.8, 16.7, -9.2, 5.0, 7.6, -19.3};
  array<double, 7> y = {2.9, 1.8, 16.7, -9.2, 5.0, 7.6, -19.3};
  double z [7] = {2.9, 1.8, 16.7, -9.2, 5.0, 7.6, -19.3};
  print<vector<double>, 7>(x, "x");
  print<array<double, 7>, 7>(y, "y");
  print<double[7], 7>(z, "z");
  bool (* lt)(double, double) = &lessThan<double>;
  bubbleSort(x, lt);
  bubbleSort(y, lt);
  bubbleSort(z, lt);
  print<vector<double>, 7>(x, "x");
  print<array<double, 7>, 7>(y, "y");
  print<double[7], 7>(z, "z");
  bool (* gt)(double, double) = &greaterThan<double>;
  bubbleSort(x, gt);
  bubbleSort(y, gt);
  bubbleSort(z, gt);
  print<vector<double>, 7>(x, "x");
  print<array<double, 7>, 7>(y, "y");
  print<double[7], 7>(z, "z");
}

void test5(){
  cout << "test5" << endl;
  vector<float> x = {-17.3, -9.2, .1, 3.7, 4.5, 6.6, 8.1};
  array<float, 7> y = {-17.3, -9.2, .1, 3.7, 4.5, 6.6, 8.1};
  float z [7] = {-17.3, -9.2, .1, 3.7, 4.5, 6.6, 8.1};
  print<vector<float>, 7>(x, "x");
  print<array<float, 7>, 7>(y, "y");
  print<float[7], 7>(z, "z");
  bool (* nothing)(float, float) = &doNothing<float>;
  bubbleSort(x, nothing);
  bubbleSort(y, nothing);
  bubbleSort(z, nothing);
  print<vector<float>, 7>(x, "x");
  print<array<float, 7>, 7>(y, "y");
  print<float[7], 7>(z, "z");
  bool (* lt)(float, float) = &lessThan<float>;
  bubbleSort(x, lt);
  bubbleSort(y, lt);
  bubbleSort(z, lt);
  print<vector<float>, 7>(x, "x");
  print<array<float, 7>, 7>(y, "y");
  print<float[7], 7>(z, "z");
}

void test6(){
  cout << "test6" << endl;
  vector<long> x = {502929292, -9891828291, 10019911, 81888111, -34534222, 99193583, 462734627};
  array<long, 7> y = {502929292, -9891828291, 10019911, 81888111, -34534222, 99193583, 462734627};
  long z [7] = {502929292, -9891828291, 10019911, 81888111, -34534222, 99193583, 462734627};
  print<vector<long>, 7>(x, "x");
  print<array<long, 7>, 7>(y, "y");
  print<long[7], 7>(z, "z");
  bool (* gt)(long, long) = &greaterThan<long>;
  bubbleSort(x, gt);
  bubbleSort(y, gt);
  bubbleSort(z, gt);
  print<vector<long>, 7>(x, "x");
  print<array<long, 7>, 7>(y, "y");
  print<long[7], 7>(z, "z");
  bool (* lt)(long, long) = &lessThan<long>;
  bubbleSort(x, lt);
  bubbleSort(y, lt);
  bubbleSort(z, lt);
  print<vector<long>, 7>(x, "x");
  print<array<long, 7>, 7>(y, "y");
  print<long[7], 7>(z, "z");
}
