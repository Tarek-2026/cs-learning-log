#include <stdio.h>
#include <string.h>
#include <ctype.h>

int score (char player[]);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{ 

    char player_one [50];
    char player_two [50];

    printf("player 1: ");
    scanf("%49s", player_one);

    printf("player 2: ");
    scanf("%49s", player_two);
    
    int result_1 = score (player_one);
    int result_2 = score (player_two);

    if (result_1 > result_2)
    {
        printf("player 1 wins!\n");
    }
    else if (result_1 < result_2)
    {
        printf("player 2 wins!\n");
    }
    else
    {
        printf("tie!\n");
    }

}

int score (char player[])
{
    int word = strlen(player);
    int total = 0;
    for (int i = 0; i < word; i++)
    {
        if (isalpha(player[i]))
        {
            int index = tolower(player[i]) - 'a';
            total +=  points[index];
        }
    }
    return total;
}