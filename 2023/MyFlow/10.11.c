#include <stdio.h>
#include <unistd.h>

//2d array
//100x100 pixels
//walls in border
//print square for walls
//print space for empty
//ball in center
//print ball
//move ball with wasd
//move ball with gravity

int map[100][100];

int main() {
    printf("Hello, world!");

    printf("\n");
    printf("\n");

    printMap();
    printBall();

    printf("\n");
    printf("\n");

    //create another thread to update the map
    //create another thread to apply gravity to the ball
    //create another thread to move the ball with wasd

    while (1){
        updateMap();
        gravity();
        updateMap();
        moveBall();
    }


    return 0;
}

void printMap(){
    //i = y
    //j = x
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 100; j++){
            if (i == 0 || i == 29 || j == 0 || j == 99){
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }
} 

void printBall(){
    map[15][49] = 2;
    
}

void updateMap(){
    //wait 1 second
    sleep(10);

    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 100; j++){
            if (map[i][j] == 1){
                //print a white square
                printf("█");
            } else if (map[i][j] == 2){
                //print a white square with a black circle
                printf("⬤");
            } else if (map[i][j] == 0){
                printf(" ");
            }
        }
        printf("\n");
    }
}

void moveBall(){
    //if pressed w
    //if ball is not on ceiling
    //move ball up 1 pixel
    //if pressed a
    //if ball is not on left wall
    //move ball left 1 pixel
    //if pressed s
    //if ball is not on floor
    //move ball down 1 pixel
    //if pressed d
    //if ball is not on right wall
    //move ball right 1 pixelw
    char c = getchar();
    if (c == 'w'){
        for (int i = 0; i < 30; i++){
            for (int j = 0; j < 100; j++){
                if (map[i][j] == 2){
                    if (map[i-1][j] == 0){
                        map[i][j] = 0;
                        map[i-1][j] = 2;
                    }
                }
            }
        }
    } else if (c == 'a'){
        for (int i = 0; i < 30; i++){
            for (int j = 0; j < 100; j++){
                if (map[i][j] == 2){
                    if (map[i][j-1] == 0){
                        map[i][j] = 0;
                        map[i][j-1] = 2;
                    }
                }
            }
        }
    } else if (c == 's'){
        for (int i = 0; i < 30; i++){
            for (int j = 0; j < 100; j++){
                if (map[i][j] == 2){
                    if (map[i+1][j] == 0){
                        map[i][j] = 0;
                        map[i+1][j] = 2;
                    }
                }
            }
        }
    } else if (c == 'd'){
        for (int i = 0; i < 30; i++){
            for (int j = 0; j < 100; j++){
                if (map[i][j] == 2){
                    if (map[i][j+1] == 0){
                        map[i][j] = 0;
                        map[i][j+1] = 2;
                    }
                }
            }
        }
    }    
}

void gravity(){
    //if ball is not on floor
    //each second, move ball down 1 pixel
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 100; j++){
            if (map[i][j] == 2){
                if (map[i+1][j] == 0){
                    map[i][j] = 0;
                    map[i+1][j] = 2;
                }
            }
        }
    }
}