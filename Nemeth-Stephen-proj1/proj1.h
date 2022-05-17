#ifndef PROJ1_H
#define PROJ1_H

using namespace std;
// List of all the prototypes used in this project
void exhaustiveSearch(int goal, string flag, vector<int> numbers);
void exhaustiveSearchBitwise(int target, vector<int> numbers, string expression);
void leftShift(int target, int opp, string expression, vector<int> numbers);
void rightShift(int target, int opp, string expression, vector<int> numbers);
void lAND(int target, int opp, string expression, vector<int> numbers);
void lOR(int target, int opp, string expression, vector<int> numbers);
void lXOR(int target, int opp, string expression, vector<int> numbers);
void exhaustiveSearchArithmetic(int target, vector<int> numbers, string expression);
void add(int target, int opp, string expression, vector<int> numbers);
void sub(int target, int opp, string expression, vector<int> numbers);
void mult(int target, int opp, string expression, vector<int> numbers);
void div(int target, int opp, string expression, vector<int> numbers);
void mod(int target, int opp, string expression, vector<int> numbers);
void printExpressions();
bool contains(string target, vector<string> & vector);
vector<int> copyVector(vector<int> numbers);

#endif
