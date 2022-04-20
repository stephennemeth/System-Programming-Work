#include <iostream>
#include <vector>
#include <string>

using namespace std;

void compress(string dnaString);
void decompress(char * argv[], int argc);
void convertString(string temp);
void convertInt(unsigned char dnaByte, vector<string> & decompressed);

/*
 * This is the main entry point of the program, it reads in
 * command line arguments and a flag telling the program if it is to
 * compress or decompress a DNA string. If the flag is for compressing,
 * the program reads in the DNA string, calles the compress function
 * and compresses it into a series of unsigned chars and printed out in
 * their integer representation. If the flag is for decompression, it calls
 * the decompress function, reads in the integer values following the flag,
 * converts them into unsigned chars, then into the corresponding DNA string.
 */
int main(int argc, char * argv[]) {

    string flag(argv[1]); // reads in flag

    /*If statement compares the values of the flag
     * and delegates to the apporiate function.
     */
    if (flag == "-c") {
        string dnaString(argv[2]);
        compress(dnaString);
        cout << endl;
    } else if (flag == "-d") {
        decompress(argv, argc);
        cout << endl;
    } // if
} // main

/*The first function used to compress the dna string
 * if that is what the flag is selected for.
 * First prints the length of the string, then
 * splits the string for every four characters into
 * another string (two bits each for an eight bit unsigned char).
 * Then passes that string into the convertString() function, where it prints
 * the unsigned char representation of the dna substring pulled from the
 * original string.
 */
void compress(string dnaString) {
    cout << dnaString.length() << " "; // prints the length
    string temp; // temporary string used to house every four characters
    int length = dnaString.length();
    for (int i = 0; i < length; i++) {
        temp += dnaString[i]; // populates the temp string
        /*When the string is at a length of 4 convert to
         * unsigned char reprentation*/
        if (temp.length() == 4) {
            convertString(temp);
            temp = ""; // resets the temp string
        } // if
    } // for

    /*This if statement is used in case there is a group
     * of characters left in the string where the length of that
     * group is less than 4, the original loop wont call it, so
     * this one acts as clean up. They would be stored in the
     * temp string left over from the loop above, but the
     * convert function would not execute.
     */
    if (temp.length() < 4 && temp.length() != 0) {
        convertString(temp);
    } // if
}

/*
 * This function does the actual converting from string
 * represntation to the unsigned char compression. Its
 * inputs is a string taken from the above compress function. An A is compressed
 * to 00 (0), T to 01 (64 if zeros to the left), C to 10 (128 if zeros to the
 * left), and G to 11 (192 if zeros to the left). Each of these conversions are
 * stored in a vector that will be max length of 4. Each of those is bit shifted to the
 * right by 2 * i, where i is there index in the string. This way at the end they are all
 * bitwise ored together and all of the significant bits will be ored with only zeros.
 */
void convertString(string temp) {
    vector<int> dnaByte;
    int length = temp.length();
    //loops through the string and checks each character.
    for (int i = 0; i < length; i++) {
        if (temp.at(i) == 'A') {
            dnaByte.push_back(0);
        } else if (temp.at(i) == 'T') {
            dnaByte.push_back(64);
        } else if (temp.at(i) == 'C') {
            dnaByte.push_back(128);
        } else {
            dnaByte.push_back(192);
        } // if
        /*shifts the element over by 2 so if there is a 1
          it will only be orred with zeros keeping it in tact. */
        dnaByte[i] = dnaByte[i] >> (2 * i);
    } // for
    unsigned char add = 0;
    length = dnaByte.size();
    /* every thing in the vector is orred together into
       a varaible called add which is intialized with zero
       so the or operation doesnt do anything. */
    for (int i = 0; i < length; i++) {
        add = add | dnaByte[i];
    } // for
    //finally prints out the unsigned char compression in integer format
    cout << (unsigned short) add << " ";
} // convertString

/*
 * This is the first function called if the flag is
 * set to decompressing. It takes int all the same parameters,
 * read in by main, an array for the arguments (argv), and an integer
 * for the number of command line arguments. All the arguments after the flag
 * are stored in a vector and converted from strings to unsigned chars for
 * proper decompression. Each char in the vector is then converted into its string representatino
 * and stored in another vector, which is printed out at the end to show what the original
 * dna string is.
 */
void decompress(char * argv[], int argc) {
    vector<unsigned char> dnaBytes;
    vector<string> decompressed;
    string sizeString = argv[2]; // get the size of the dna string
    int size = stoi(sizeString); // converts the size to an integer for looping
    /*The integers to decompress would start at index 3
     * of the command line arguments.
     */
    for (int i = 3; i < argc; i++) {
        string byteString(argv[i]);
        unsigned char byte = stoi(byteString);
        dnaBytes.push_back(byte);
    }
    int length = dnaBytes.size();
    for (int i = 0; i < length; i++) {
        //calls convertInt to get decompress the unsigned char
        convertInt(dnaBytes[i], decompressed);
    }
    for (int i = 0; i < size; i++) {
        cout << decompressed[i];
    }
}

/*
 * This is the the function used to convert an unsigned char into its
 * string representation. This uses a bit-wise operators to mask the string
 * and pull out the first two bits, converting them to there appropriate characters,
 * shifting to the left by two, and repeating the process for the next set of bits in the sequence.
 * Since an unsigned char is representing at most 4 characters this will occur 4 times
 * per function call.
 */
void convertInt(unsigned char dnaByte, vector<string> & decompressed) {
    for (int i = 0; i < 4; i++) {
        /*
         * This mask is equivalent to
         * 11000000, when anded with anything
         * it will pull the first two bits out
         */
        unsigned char mask = 192;
        unsigned char temp = dnaByte & mask; // pulls the first two bits
        if (temp == 0) {
            decompressed.push_back("A");
        } else if (temp == 64) {
            decompressed.push_back("T");
        } else if (temp == 128) {
            decompressed.push_back("C");
        } else if (temp == 192) {
            decompressed.push_back("G");
        } // if
        dnaByte = dnaByte << 2; //shifts over by two
    } // for
} // convertInt
