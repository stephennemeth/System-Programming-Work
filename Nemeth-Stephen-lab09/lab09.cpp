#include <iostream>
#include <stdexcept>

using namespace std;

/*
* Main entry in to the program. Takes in numeric command line
* arguents and computers their average. If there is not numeric command
* command line arguments or not all are numeric, exceptions are thrown and
* caught resulting in exiting the program.
*/
int main(int argc, char * argv[]) {
    double sum = 0;
    try {
        if (argc == 1) {
            throw 1;
        }

        for (int i = 1; i < argc; i++) {
            sum += stod(argv[i]);
        }

        double average = sum / (argc - 1);

        cout << "The average is " << average << "." << endl;

    } catch (int e) {
        cout << "Error: command line arguments must have at least one numeric value." << endl;
        cout << "Goodbye!" << endl;
        exit(2);
    } catch (invalid_argument &ie) {
        cout << "Error: command line arguments after the program name must all be numeric." << endl;
        cout << "Goodbye!" << endl;
        exit(2);
    }
}
