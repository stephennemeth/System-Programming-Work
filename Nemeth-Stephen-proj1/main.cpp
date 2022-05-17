#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <cstdlib>
#include "proj1.h"

using namespace std;

/*
 * Main entry point into the program, reads in all the
 * command line arguments passed into the function and passed that to the 
 * exhaustiveSearch() function located in proj.cpp.
 */
int main(int argc, char *argv[]) {
    vector<int> numbers; // to store the numbers in the program
    string flag; // indicating what type of evaluation
    int goal;
    for (int i = 0; i < argc; i++) {
       string arg(argv[i]);
       if (arg == "-a" || arg == "-b") {
           flag = arg;
       }
       if (arg == "-e") {
           goal = stoi(string(argv[i + 1]));
       }
       if (arg == "-v") {
            numbers.push_back(stoi(string(argv[i + 1])));
            numbers.push_back(stoi(string(argv[i + 2])));
            numbers.push_back(stoi(string(argv[i + 3])));
            numbers.push_back(stoi(string(argv[i + 4])));
            numbers.push_back(stoi(string(argv[i + 5])));
       }
    }
    exhaustiveSearch(goal, flag, numbers);
} // main
