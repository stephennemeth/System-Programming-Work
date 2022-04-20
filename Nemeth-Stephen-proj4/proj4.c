#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/stat.h>

/*
* This function makes 3 file pointers, 2 pointing to the two
* files given through the command line and a new one for a difference file.
* Any byte that is not equal to file2 in file1 is written to the difference file.
*/
void step1(char *, char *);
/*
* This function makes 3 file pointers, 2 pointing to the two
* files given through the command line and a new one for a difference file.
* The contents of the first two are read into 2 dynamically allocated arrays 
* equal to the size of the files. Any thing that is not equal to file1 in file2 is written
* to a third array that is made to store the differences, its size is equal to file2.
* After the differences are found, the contents of the third array is written to the 
* difference file.
*/
void step2(char *, char *);

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Usage: proj4.out <file1> <file2>\n");
        exit(1);
    }
    step1(argv[1], argv[2]);
    step2(argv[1], argv[2]);
}

void step1(char * f1, char * f2) {
    struct timeval start; struct timeval end; gettimeofday(&start, NULL);
    FILE * diff1 = fopen("./differencesFoundInFile1.txt", "w"); FILE * file1 = fopen(f1, "r"); FILE * file2 = fopen(f2, "r");
    if (file1 == NULL || file2 == NULL) {
        printf("There was an error reading a file.\n"); 
        exit(2);
    }
    setbuf(file1, NULL); setbuf(file2, NULL); setbuf(diff1, NULL); // buffers are turned off here
    struct stat st; stat(f1, &st); int size = st.st_size;
    char b; char c;
    for (int i = 0; i < size; i++) {
        if ((c = fgetc(file1)) != (b = fgetc(file2))) {
            int check = fputc(c, diff1);
            if (check == EOF) {
                printf("There was an error writing to a file.");
                exit(3);
            }
        }
    }
    fclose(file1); fclose(file2); fclose(diff1);
    gettimeofday(&end, NULL);
    printf("Step 1 took %6f milliseconds\n", (double) ((end.tv_sec * 1e3) + (end.tv_usec / 1e3)) - (double) ((start.tv_sec * 1e3) + (start.tv_usec / 1e3)));
}

void step2(char * f1, char * f2) {
    struct timeval start; struct timeval end; gettimeofday(&start, NULL);
    FILE * diff2 = fopen("differencesFoundInFile2.txt", "w"); FILE * file1 = fopen(f1, "r"); FILE * file2 = fopen(f2, "r");
    struct stat st; stat(f1, &st); int size1 = st.st_size; stat(f2, &st); int size2 = st.st_size;
    char * array1 = malloc(sizeof(char) * size1); char * array2 = malloc(sizeof(char) * size2); // uses malloc here
    int a = fread(array1, sizeof(char), size1, file1); int b = fread(array2, sizeof(char), size2, file2); char * array3 = malloc(sizeof(char) * size2);
    if (a != size1 || b != size2) {
        printf("There was an error reading a file.\n");
        exit(2);
    }
    int count = 0;
    for (int i = 0; i < size2; i++) {
        if (i >= size1) {
            array3[count++] = array2[i];
        } else if (array2[i] != array1[i]) {
            array3[count++] = array2[i];
        }
    }
    int wrote = fwrite(array3, sizeof(char), count, diff2);
    if (wrote != count) {
        printf("There was an error writing to a file\n");
        exit(3);
    }
    free(array1); free(array2); free(array3); // frees arrays here
    fclose(file1); fclose(file2); fclose(diff2);
    gettimeofday(&end, NULL);
    printf("Step 2 took %6f milliseconds\n", (double) ((end.tv_sec * 1e3) + (end.tv_usec / 1e3)) - (double) ((start.tv_sec * 1e3) + (start.tv_usec / 1e3)));
}