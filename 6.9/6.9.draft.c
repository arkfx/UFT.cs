// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    for(int i = 1; i <= 1000; i++){
    printf("%d", i);
    printf("\n");
        if(i >= 10){
            break;
        }
    }
    
    printf("fim");
    return 0;
}