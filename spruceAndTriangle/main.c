#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floors, i, stars, space = 0;
    scanf("%d", &floors);

    //draw a spruce
    for (i = 0; i < floors; i++, stars += 2){
        for (space = floors - 1; space >= i; space--){
            printf(" ");
        }
        for (stars = 0; stars < i*2+1; stars++){
            printf("*");
        }
        printf("\n");
    }

    //draw a stump
    for (space = 0; space < floors; space++){
        printf(" ");
    }
    printf("*\n");

    //draw a triangle with a vertex on top
    for (i = 0; i < floors; i++){
        for(stars = 0; stars <= i; stars++){
            printf("*");
        }
        printf("\n");
    }

    //draw a triangle with a vertex on the bottom
     for (i = 0; i < floors; i++){
        for(stars = floors; stars > i; stars--){
            printf("*");
        }
        printf("\n");
    }
    getch();
    return 0;
}
