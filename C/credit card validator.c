#include <stdio.h>

long exponentiation (int count);
int length (long long credit);
int validation (long long credit,int credit_length );

int main(void)
{
    // prompt the user to input a credit number
    long long credit;
    printf("enter a credit number: ");
    scanf("%lld", &credit);

    // getting the length of the credit number
    int credit_length = length (credit);
    

    // check the credit number validation
    int credit_validation =validation(credit, credit_length );
    
    long exponentiation_2 = exponentiation (credit_length-2);
    if (credit_validation % 10 == 0)
    {
        if (credit_length == 15 &&  (credit / exponentiation_2 == 37|| credit / exponentiation_2 == 34))
        {
            printf("american express\n");
        }
        else if((credit_length == 13 || credit_length == 16) && credit / exponentiation (credit_length-1) == 4)
        {
            printf("Visa\n");
        }
        else if (credit_length == 16 &&(credit / exponentiation_2 == 51|| credit / exponentiation_2 == 52 ||credit / exponentiation_2 == 53|| credit / exponentiation_2 == 54 || credit / exponentiation_2 == 55))
        {
            printf("Master card\n");
        }
    }
    else
    {
        printf("invalid\n");
    }

}




int length (long long credit)
{
    int count = 0;
    long long copy = credit;
    while ( copy > 0)
    {
        copy = copy / 10;
        count ++;
    }
    return count;
}

long exponentiation (int count)
{
    long power = 1;
    while (count > 0)
    {
        power *= 10;
        count --;
    }
    return power;
}

int validation (long long credit,int credit_length )
{
    int sum = 0;
    int count = 0;
    while( credit_length > count)
    {
        if (count % 2 == 0)
        {
            sum += credit % 10; 
            credit/= 10;
        }
        else
        {
            if ((credit % 10) *2 < 10)
            {
                sum += (credit % 10) *2;
                credit /= 10;
            }
            else
            {
                int x = (credit % 10) *2;
                sum += x % 10 + x / 10;
                 credit /= 10;
            }
        }
        count ++;
    }
    return sum;
}

