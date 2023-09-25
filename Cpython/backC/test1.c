#include <stdio.h>

int main() {
    char* content1 = "This is the first line";
    char* content2 = "This is the second line";
    writeToFile(content1);
    writeToFile(content2);
    readNextLine();
    readNextLine();
    readNextLine();
    readNextLine();
    readNextLine();
    return 0;
}

void writeToFile(char* content) {
    char* fileName = "/workspaces/UFT.cs/Cpython/backC/output.txt";
    FILE* file = fopen(fileName, "a"); // open file in append mode
    fprintf(file, "%s\n", content); // write content to file with a newline character
    fclose(file); // close file
}

void readNextLine() {
    static FILE* file = NULL; // static variable to keep track of file pointer
    if (file == NULL) {
        char* fileName = "/workspaces/UFT.cs/Cpython/frontPY/input.txt";
        file = fopen(fileName, "r"); // open file in read mode
    }
    char line[1024];
    if (fgets(line, sizeof(line), file) != NULL) { // read next line from file
        printf("%s\n", line); // print line to console
    } else {
        fclose(file); // close file when all lines have been read
        file = NULL; // reset file pointer
    }
}