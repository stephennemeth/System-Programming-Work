#include <iostream>
#include <string>
#include "Test.h"

using namespace std;

void print(string s) {
    cout << s << endl;
}
int main() {
    const int x = 1;

    int * p1 = &x;

    const int * p2 = p1;
    *p2 = 2;
    cout << p2 << endl;
    cout << p1 << endl;


}
