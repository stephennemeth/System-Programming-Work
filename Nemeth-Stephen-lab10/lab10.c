#include <stdlib.h>
#include <stdio.h>

/*
* Main entrance into the program. Takes in a string as a command line argument.
* Interates through via a char pointer and if the character is a letter, converts it
* with a ROT13 cipher. If character is not a letter it is not convereted.
*/
int main(int argc, char * argv[]) {
   
   char * string = argv[1];
   int i = 0;
   while (string[i] != '\0') {
       if ((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z')) {
           if ((string[i] <= 'M' && string[i] >= 'A') || (string[i] <= 'm' && string[i] >= 'a')) {
               string[i] += 13;
           } else{
               string[i] -= 13;
           }
       }
       printf("%c", string[i]);
       i++;
   }
   printf("\n");
}