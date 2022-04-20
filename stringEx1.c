#include <stdbool.h>
#include <stdio.h>

int length (char * s) {
    int length = 0;
    int i = 0;
        while (*(s + i) != '\0') {
            length++;
            i++;
        }
    return length;
}

bool isUpperCaseLetter(char c) {
    return c >= 65 && c <= 90;
}

void toLowerCase(char * s) {
    for (int i = 0; i < length(s); i++) {
        if (isUpperCaseLetter(*(s+i))) {
            *(s + i) += 32;
        }
    }
}

void toUpperCase(char * s) {
    for (int i = 0; i < length(s); i++) {
        *(s + i) -= 32;
    }
}

int main() {

    char * s = "abcd";
    char a = 'A';
    char b = 'a';
    char * meh = "ABDBDBDBDBDBDBDBDBD";

    printf("%d\n", length(s));
    printf("%d\n", isUpperCaseLetter(a));
    printf("%d\n", isUpperCaseLetter(b));
    toLowerCase(meh);
    printf("%s\n", meh);
}
