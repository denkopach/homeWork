#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(;;){
        printf("\nEnter letter\n");
        int userAnswer = getche();
        fflush (stdin);
        char letter[] = "qwertyuiopasdfghjklzxcvbnmq";
        int i = 0;
        for (i = 0; i < 27; i++){
            if (letter[i] == userAnswer){
                printf("\nNext letter is %c\n", letter[i+1]);
                break;
            }
            if (i == 26) {
                    printf("\nYou did not enter the letter of the Latin alphabet");
            }
        }
    }
}
