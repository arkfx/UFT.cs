#include <stdio.h>

int main() {
    // Declare and initialize an array of integers
    int numbers[] = {1, 2, 3, 4, 5};

    // Access and print the elements of the array
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("%d ", numbers[i]);
    }

    return 0;

}

int sample(){
    int *v = malloc(sizeof(int) * 10);
}
