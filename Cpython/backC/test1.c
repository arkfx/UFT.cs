#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    FILE *fp;
    char input[100];

    fp = fopen("output.txt", "w");
    printf("Enter input: ");
    scanf("%s", input);

    fprintf(fp, "%s", input);
    printf("Input saved to output.txt\n");
    return 0;
}