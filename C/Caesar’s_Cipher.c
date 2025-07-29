#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int convert_to_int(int text_length,char argv[]);
void rotate (int key, char argv[]);

int main(int argc, char *argv[])
{
    // make sure the user input only one command line argument
    if (argc != 2)
    {
        printf("invalid input, you should only input only one argument\n");
        return 1;
    } 

    // make sure the argument is intger
    int text_length = strlen(argv[1]);
    for (int i = 0; i < text_length; i++ )
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert the string to an intger
    int key = convert_to_int(text_length, argv[1]);
    printf("%i\n", key);


    // user input for the plain text
    char plain_text[2000];
    printf("plaintext:  ");
    fgets(plain_text, sizeof(plain_text), stdin);

    // encrypt the plain text and output the cipher text
    rotate(key, plain_text);
    return 0;

}

// convert the string to an intger
int convert_to_int(int text_length,char argv[])
{
    int output = 0;
    int power = 0;
    for(int i = text_length-1; i >= 0; i--)
    {
        output += (argv[i] - '0') * pow(10 , power );
        power ++;
    }
    return output;
}

// rotate the alpha 
void rotate (int key, char plain_text[])
{
    int text_length = strlen(plain_text);

    int v = key % 26;
    for (int i = 0; i < text_length; i++)
    {
        // any non alpha stays the same without incryption 
        if (isalpha(plain_text[i]))
        {
            if (isupper(plain_text[i]))
            {
                plain_text[i] = ((plain_text[i] - 'A' + v) % 26) + 'A';
            }
            else if (islower(plain_text[i]))
            {
                plain_text[i] = ((plain_text[i] - 'a' + v) % 26) + 'a';
            }

        }
    }
    printf("ciphertext: %s\n", plain_text);

}


