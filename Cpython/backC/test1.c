#include <stdio.h>
 
char* content;

int main() {
    
    readNextLine();
    return 0;
}

void writeToFile(char* content) {
    FILE* file = fopen("/workspaces/UFT.cs/Cpython/backC/output.txt", "a");
    fprintf(file, "%s\n", content);
    fclose(file);
}

void readNextLine() {
    static FILE* file = NULL;
    if (!file) file = fopen("/workspaces/UFT.cs/Cpython/frontPY/input.txt", "r");
    char line[1024];
    if (fgets(line, sizeof(line), file)) printf("%s", line);
    else fclose(file);
}