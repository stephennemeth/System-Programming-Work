#include <iostream>
#include "Fraction.h"
using namespace std;

/*A test case for fractions 1/3 and 1/3*/
void test2();
/*A test case for fractions 2/6 and 1/3*/
void test3();
/*A test case for fractions 4/6 and 14/15*/
void test4();
/*A test case for fractions 9/18 and 3/6*/
void test5();

//Test the functions and operators in the Fraction class
int main(void){
  Fraction f(3, 4);
  Fraction g(2, 5);
  cout << "f is ";  !f;  //!f prints the Fraction f to standard output
  cout << "g is ";  !g;  //!g prints the Fraction g to standard output
  cout << endl;
  cout << "f + g is ";  !(f + g);
  cout << "f - g is ";  !(f - g);
  cout << "f * g is ";  !(f * g);
  cout << "f / g is ";  !(f / g);
  cout << endl;
  cout << "f == g is " << (f == g) << endl;
  cout << "f != g is " << (f != g) << endl;
  cout << endl;
  cout << "f + 5 is ";  !(f + 5);
  cout << "f - 5 is ";  !(f - 5);
  cout << "f * 5 is ";  !(f * 5);
  cout << "f / 5 is ";  !(f / 5);
  test2();
  return 0;
}

//second test for operators in fraction class
void test2() {
  Fraction f(1, 3);
  Fraction g(1, 3);
  cout << "\nf is ";  !f;  //!f prints the Fraction f to standard output
  cout << "g is ";  !g;  //!g prints the Fraction g to standard output
  cout << endl;
  cout << "f + g is ";  !(f + g);
  cout << "f - g is ";  !(f - g);
  cout << "f * g is ";  !(f * g);
  cout << "f / g is ";  !(f / g);
  cout << endl;
  cout << "f == g is " << (f == g) << endl;
  cout << "f != g is " << (f != g) << endl;
  cout << endl;
  cout << "f + 2 is ";  !(f + 2);
  cout << "f - 2 is ";  !(f - 2);
  cout << "f * 2 is ";  !(f * 2);
  cout << "f / 2 is ";  !(f / 2);
  test3();
}

//third test for operators in fraction class
void test3() {
  Fraction f(2, 6);
  Fraction g(1, 3);
  cout << "\nf is ";  !f;  //!f prints the Fraction f to standard output
  cout << "g is ";  !g;  //!g prints the Fraction g to standard output
  cout << endl;
  cout << "f + g is ";  !(f + g);
  cout << "f - g is ";  !(f - g);
  cout << "f * g is ";  !(f * g);
  cout << "f / g is ";  !(f / g);
  cout << endl;
  cout << "f == g is " << (f == g) << endl;
  cout << "f != g is " << (f != g) << endl;
  cout << endl;
  cout << "f + 3 is ";  !(f + 3);
  cout << "f - 3 is ";  !(f - 3);
  cout << "f * 3 is ";  !(f * 3);
  cout << "f / 3 is ";  !(f / 3);
  test4();
}

//fourth test for fractions in operator class
void test4() {
Fraction f(4, 6);
  Fraction g(14, 15);
  cout << "\nf is ";  !f;  //!f prints the Fraction f to standard output
  cout << "g is ";  !g;  //!g prints the Fraction g to standard output
  cout << endl;
  cout << "f + g is ";  !(f + g);
  cout << "f - g is ";  !(f - g);
  cout << "f * g is ";  !(f * g);
  cout << "f / g is ";  !(f / g);
  cout << endl;
  cout << "f == g is " << (f == g) << endl;
  cout << "f != g is " << (f != g) << endl;
  cout << endl;
  cout << "f + 4 is ";  !(f + 4);
  cout << "f - 4 is ";  !(f - 4);
  cout << "f * 4 is ";  !(f * 4);
  cout << "f / 4 is ";  !(f / 4);
  test5();
}

//fifth test for fractions in operator class
void test5() {
Fraction f(9, 18);
  Fraction g(3, 6);
  cout << "\nf is ";  !f;  //!f prints the Fraction f to standard output
  cout << "g is ";  !g;  //!g prints the Fraction g to standard output
  cout << endl;
  cout << "f + g is ";  !(f + g);
  cout << "f - g is ";  !(f - g);
  cout << "f * g is ";  !(f * g);
  cout << "f / g is ";  !(f / g);
  cout << endl;
  cout << "f == g is " << (f == g) << endl;
  cout << "f != g is " << (f != g) << endl;
  cout << endl;
  cout << "f + 5 is ";  !(f + 5);
  cout << "f - 5 is ";  !(f - 5);
  cout << "f * 5 is ";  !(f * 5);
  cout << "f / 5 is ";  !(f / 5);
}