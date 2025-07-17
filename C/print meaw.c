#include <stdio.h>

void meaw(int x);
int get_postive_number(void);

int main(void)
{
    int n = get_postive_number();
    meaw(n);
    
    return 0;
}


void meaw(int x)
{
    for (int i = x; i > 0; i--)
        printf("meaw\n");
}


int get_postive_number(void)
{
     int n;
    do
    {
    printf("how many times you want print meaw? ");
    scanf("%i", &n);
    
    } 
    while (n < 1);
    return n;
}