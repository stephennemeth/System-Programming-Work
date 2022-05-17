#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <cstdlib>
#include "proj1.h"

using namespace std;

//A vector used to hold all the valid expressions
// that equal the target value
vector<string> expressions;
//string to store if this is for
//bitwise or arithmetic operations
string flag;
//The target value expression are evaluated against
int goal;

/*
 * This method takes in the arguments from the command line
 * taken from main and passed them into functions to find list of all
 * arethmetic and bitwise experessions. Its parameters are int goalfm(goal from main),
 * int flagfm(flag from main) and vecotr<int> numbers (a vector housing all the numbers
 * taken from command line). Based on the flag it calls the bitwise or arithemtic exhaustive
 * search functions and passes in goal and numbers.
 */
void exhaustiveSearch(int goalfm, string flagfm, vector<int> numbers) {
    goal = goalfm;
    flag = flagfm;
    // This represents the start of the expression string
    string expression = "(((";
    if (flag == "-a") {
        exhaustiveSearchArithmetic(0, numbers, expression);
    } else {
        exhaustiveSearchBitwise(0, numbers, expression);
    }
    printExpressions();
} // handle

/*
* Function used to print all the valid expressions housed in the
* string vector expressions that evaluate to the
* target value. Also prints a final line that displays the numbers
* of expressions that evaluates to the target value.
*/
void printExpressions() {
    for (unsigned int i = 0; i < expressions.size(); i++) {
        cout << expressions[i] << endl;
    }
    string type = flag == "-a" ? " arithmetic " : " bitwise "; // indicates what type of expressions.
    cout << expressions.size() << type << "expressions that evaluate to " << goal << endl;
}

/*
* This bitwise implentation of the exhaustive search that is psuedo-recursive.
* Its parameters are target which represents the sum so far for a particular expressoin,
* the vector of numbers this particular branch of the search is working on, and the string
* representing the expression this particular branch of the search is working on. This function,
* for each element housed in numbers, removes a element and the vector is copied. That element is
* then used for every bitwise operation against the sum tracked for that particular branch. If
* numbers is empty, this signifies that there is nothing left to evaluate and if the expression is
* not a duplicate and the sum equals the goal value, it is added to the expressions vector to be
* printed out later.
*/
void exhaustiveSearchBitwise(int target, vector<int> numbers, string expression) {
    if (numbers.size() == 0) {
        //There is an extra parenthese that the substring helps remove
        expression = expression.substr(0, expression.size() - 1);
        if (target == goal && !contains(expression, expressions)) {
            expressions.push_back(expression);
            return;
        }
    } else {
        for (unsigned int i = 0; i < numbers.size(); i++) {
            int operand = numbers[i]; // opp stands for operand
            vector<int> temp = copyVector(numbers); // to house the new vector values
            temp.erase(temp.begin() + i); // removes opp from the temporary vector
            //Runs opp with every bitwise operator against the sum
            leftShift(target, operand, expression, temp);
            rightShift(target, operand, expression, temp);
            lAND(target, operand, expression, temp);
            lOR(target, operand, expression, temp);
            lXOR(target, operand, expression, temp);
        }
    }
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It left shifts target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchBitwise() again to repeat the process.
*/
void leftShift(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target <<= operand;
        expression += "<<";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchBitwise(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It right shifts target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchBitwise() again to repeat the process.
*/
void rightShift(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target >>= operand;
        expression += ">>";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchBitwise(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It logially ANDs target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchBitwise() again to repeat the process.
*/
void lAND(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target &= operand;
        expression += "&";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchBitwise(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It logically ORs target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchBitwise() again to repeat the process.
*/
void lOR(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target |= operand;
        expression += "|";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchBitwise(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It lorgially XORs target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchBitwise() again to repeat the process.
*/
void lXOR(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target ^= operand;
        expression += "^";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchBitwise(target, numbers, expression);
}

/*
* This arithemtic implentation of the exhaustive search that is psuedo-recursive.
* Its parameters are target which represents the sum so far for a particular expressoin,
* the vector of numbers this particular branch of the search is working on, and the string
* representing the expression this particular branch of the search is working on. This function,
* for each element housed in numbers, removes a element and the vector is copied. That element is
* then used for every arithmetic operation against the sum tracked for that particular branch. If
* numbers is empty, this signifies that there is nothing left to evaluate and if the expression is
* not a duplicate and the sum equals the goal value, it is added to the expressions vector to be
* printed out later.
*/
void exhaustiveSearchArithmetic(int target, vector<int> numbers, string expression) {
    if (numbers.size() == 0) {
        expression = expression.substr(0, expression.size() - 1);
        if (target == goal && !contains(expression, expressions)) {
            expressions.push_back(expression);
            return;
        }
    } else {
        for (unsigned int i = 0; i < numbers.size(); i++) {
            int operand = numbers[i];
            vector<int> temp = copyVector(numbers);
            temp.erase(temp.begin() + i);
            add(target, operand, expression, temp);
            sub(target, operand, expression, temp);
            mult(target, operand, expression, temp);
            div(target, operand, expression, temp);
            mod(target, operand, expression, temp);
        }
    }
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It adds target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchArithmetic() again to repeat the process.
*/
void add(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target += operand;
        expression += "+";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchArithmetic(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It subtracts target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchArithmetic() again to repeat the process.
*/
void sub(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target -= operand;
        expression += "-";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchArithmetic(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It multiplies target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp
* this function then recalls exhaustiveSearchArithmetic() again to repeat the process.
*/
void mult(int target, int operand, string expression, vector<int> numbers) {
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target *= operand;
        expression += "*";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchArithmetic(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It divides target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp. If opp is zero, the expression is invalid
* and should not be evaluated further and return is called effectively killing this search.
* this function then recalls exhaustiveSearchArithmetic() again to repeat the process.
*/
void div(int target, int operand, string expression, vector<int> numbers) {
    if (operand == 0) {
        return;
    }
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target /= operand;
        expression += "/";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchArithmetic(target, numbers, expression);
}

/*
* This function takes two ints, target and opp a string represnting the expression
* being tracked and a vector of ints. It mods target by opp and then
* updates the expression to reflect the operation. If the string is equals to (((
* that means there are no numbers in the expression yet, so there should be no operation
* and the expression should just append opp. If opp is zero, the expression is invalid
* and should not be evaluated further and return is called effectively killing this search.
* this function then recalls exhaustiveSearchArithmetic() again to repeat the process.
*/
void mod(int target, int operand, string expression, vector<int> numbers) {
    if (operand == 0) {
        return;
    }
    if (target == 0 && expression == "(((") {
        target = operand;
        expression += to_string(operand);
    } else {
        target %= operand;
        expression += "%";
        expression += to_string(operand);
        expression += ")";
    }
    exhaustiveSearchArithmetic(target, numbers, expression);
}

/*
* This function takes in a string and a reference to a vector containing
* strings. Runs a linear search if the string is found and return true.
* If the string is not found it returns false.
*/
bool contains(string target, vector<string> & vector) {
    for (unsigned int i = 0; i < vector.size(); i++) {
        if (vector[i] == target) {
            return 1;
        }
    }
    return 0;
}

/*
* This method takes in a vector of ints. Creates a new vector
* and all elements from the original is copied over into the new vector.
* Afterwards the new vector is returned.
*/
vector<int> copyVector(vector<int> numbers) {
    vector<int> newVector;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        newVector.push_back(numbers[i]);
    }
    return newVector;
}
