#include <stdio.h>

int coins (int change);

int main(void)
{
    int change;
    do
    {
        printf("change owed: ");
        scanf("%i", &change);
        if (change < 0)
        {
           printf("invalid input!\n");
        }

    } while (change < 0);
    printf("%i\n", coins (change));
}


int coins (int change)
{
    int change1 = 1;
    int change2 = 5;
    int change3 = 10;
    int change4 = 25;
    int result;
    int change_count = 0;

    while(change > 0)
    {
        if (change >= change4)
        {
            result = change / change4;
            change = change % change4;
            change_count += result;
        }
        else if (change >= change3)
        {
            result = change / change3;
            change = change % change3;
            change_count += result;
        }
        else if (change >= change2)
        {
            result = change / change2;
            change = change % change2;
            change_count += result;
        }
        else if (change >= change1)
        {
            result = change / change1;
            change = change % change1;
            change_count += result;
        }
    }
    return change_count;
}