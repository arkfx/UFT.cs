#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char input[100];

    fp = fopen("output.txt", "w");
    printf("Enter input: ");
    scanf("%s", input);

    fprintf(fp, "%s", input);

    return 0;
}