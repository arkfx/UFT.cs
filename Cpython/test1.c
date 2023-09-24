#include <stdio.h>

int main() {
    char text[1000];

    printf("Enter the text to save: ");
    scanf("%s", text);

    FILE *file = fopen("output.txt", "w");
    fprintf(file, "%s", text);
    fclose(file);

    return 0;
}