#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    FILE *fp;
    char input[100];
    char path[PATH_MAX];

    fp = fopen("output.txt", "w");

    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    printf("Enter input: ");
    scanf("%s", input);

    fprintf(fp, "%s", input);

    realpath("output.txt", path);
    printf("File path: %s\n", path);

    fclose(fp);

    return 0;
}