#include <stdio.h>

int main() {
    char* content1 = "primeira linha de output";
    char* content2 = "segunda linha de output";
    writeToFile(content1);
    writeToFile(content2);
    readNextLine();
    readNextLine();
    readNextLine();
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