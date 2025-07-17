#include <stdio.h>

// guessing game
int main()
{
    // the secret number
    int sec_num = 4;

    //number of lives the user has
    int lives = 3; 
    int i = 0;
    int guess_num;

    while (i < lives)
    {
        // ask the user to guess a number
        printf ("guess a number: ");
        scanf("%d",&guess_num);
        i++;

        // if the number is right type you won!
        if (sec_num == guess_num)
        {
            printf("right number\n you won!");
            return 0;
        }
        // if the user typed the wrong number give hime another try
        else
        {
            // type this only if the user still has lives
            if (i < lives)
            {
                printf("wrong number, try again!\n");
            }
        }
    }

    // if the user used all his lives type you loose and tell him the righ number
    printf("sorry you loose!\n right number is 4");
    return 1;
    
}
