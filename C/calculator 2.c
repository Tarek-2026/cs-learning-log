#include <stdio.h>
#include <string.h>

float calculator (void);

int main()
{
    char run[10];

    do
    {
        printf("run the calculator: on/off\n");
        scanf("%s",run);

        if (strcmp(run, "off") == 0)
        {
            break;
        }
        else if ((strcmp(run, "on") == 0))
        {
            printf("%f\n",calculator ());
        }
        else
        {
            printf("invalid");
            return 3;
        }
    } while (strcmp(run, "on") == 0);
    
}



float calculator (void)
{
    float num1;
    float num2;
    char operator;
    float result;

    printf("enter the first number: ");
    scanf("%f", &num1);

    printf("enter the operator:");
    scanf(" %c", &operator);

    printf("enter the second number: ");
    scanf("%f", &num2);

    if (operator == '+')
    {
        result = num1 + num2;
    }
    else if (operator == '-')
    {
        result = num1 - num2;
    }
    else if (operator == '*')
    {
        result = num1 * num2;
    }
    else if (operator == '/')
    {
        if (num2 == 0)
        {
            printf("invalid operation, dividing by zero is not allowed\n");
            return 2;
        }
        result = num1 / num2;
    }
    else 
    {
    printf("invalid operator\n");
    return 1;
    }
return result;
}