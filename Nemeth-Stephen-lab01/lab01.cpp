#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hamming(int int1, int int2); // calculates the hamming distance between two ints
vector<int> binaryConversion(int x); // converts an int into a bit string
vector<int> pad(vector<int> vector, int difference); // pads a bitstring with 0s
string bitString(vector<int> vector); // converts a vector bitstring into a string

/*
 * Main entry point into the program, takes
 * two non-negative integers via the command line,
 * finds their bit string representation and calculates the hamming
 * distance between them.
 */
int main(int argc, char * argv[]) {
    //find the hamming distance by comparing passing in the two numbers
    int hammingDistance = hamming(atoi(argv[1]), atoi(argv[2]));

    //This stores the two bitstring as vectors
    vector<int> firstInt = binaryConversion(atoi(argv[1]));
    vector<int> secondInt = binaryConversion(atoi(argv[2]));

    //This if statement decides which vector is getting padded with zeros
    if (firstInt.size() > secondInt.size()) {
        secondInt = pad(secondInt, firstInt.size() - secondInt.size());
    } else {
        firstInt = pad(firstInt, secondInt.size() - firstInt.size());
    } // if

    //prints out the result
    cout << bitString(firstInt) << " is the bit string for " << atoi(argv[1]) << endl;
    cout << bitString(secondInt) << " is the bit string for " << atoi(argv[2]) << endl;
    cout << hammingDistance << " is the Hamming distance between the bit strings" << endl;

    return EXIT_SUCCESS;
} // main

/*
 * This function takes in an integer vector
 * that houses a bitstring and converts it into a
 * string representation of a bit string.
 */
string bitString(vector<int> vector) {
    string bitString; // intializes an empty string
    for (int i = 0; i < vector.size(); i++) {
        bitString += to_string(vector[i]); // adds the 1s and 0s into the string
    }
    return bitString;
} // bitString

/*
 * This function calculates the hamming distance of
 * two integers using bitwise AND and right shift. It
 * iteratively goes through and pulls the individual bits and compares
 * them using the & operator. Then shift both numbers to the right and repeats
 * until they are both equal to zero. This takes in the parameters int1 and int2
 * which are both integers to be compared and returns an int representing the
 * hamming distance between them.
 */
int hamming(int int1, int int2) {

    int hamming = 0; // to represent the hamming distance

    while(int1 != 0 || int2 != 0) {
        int newInt1 = int1 & 1; // pulls least significant bit
        int newInt2 = int2 & 1; // pulls least significant bit
        if (newInt1 != newInt2) { // compares the new bytes and sees if the same
            hamming++; // if the bits are not the same, increases by 1
        } // if
        int1 = int1 >> 1; // bit shift to the right
        int2 = int2 >> 1; // bit shift to the right
    } // while

    return hamming;
} // hamming

/*
 * This function converts an integer into its binary
 * representation as a bitstring and stores it
 * inside of a vector. The integer is assumed positive or zero.
 * The parameter is x and is an integer.
 */
vector<int> binaryConversion(int x) {

    vector<int> vector; // used to store the bits
    int quotient = x; // used to store the remaining values
    int remainder = 0; // represents the bit to be stored

    while (quotient > 0) {
        remainder = quotient % 2; // pulls the 1 or 0 from the number
        quotient /= 2; // continually halves until equal to zero
        vector.insert(vector.begin(), remainder); // inserts the 1 or 0 into the vector
    } // while

    if (quotient = 0) { // edge case if x is 0
        vector.push_back(0); // 0 = 0 in binary
    } // if

    return vector;
} // binaryConversion

/*
 * This method prepends an integer vector with zeros.
 * The amount of zeros to prepend is determined by another
 * integer, reffered to as difference, passed into the
 * function.
 */
vector<int> pad(vector<int> vector, int difference) {
    for (int i = 0; i < difference; i++) {
        vector.insert(vector.begin(), 0); // prepends the vector with zeros
    } // for
    return vector;
} // pad
