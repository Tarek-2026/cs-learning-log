#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(int text_length, char text[], char argv[]);


int main(int argc, char *argv[])
{
    // the user shouls only input one command line argument
    if (argc != 2)
    {
        printf("invalid, you must have only one key\n");
        return 1;
    }

    int key_length = strlen(argv[1]);

    // the key should be a string of 26 charachters
    if (key_length != 26)
    {
        printf("invalid, the key must be 26 charachters\n");
        return 2;
    }
    for (int x=0; x < key_length; x++)
    {
        if (!isalpha(argv[1][x]))
        {
            printf("invalid, the key must be alphabtic\n");
            return 3;
        }
        for(int y = 0; y < key_length; y++)
        {
            if(argv[1][x] == argv[1][y])
            {
                printf("invalid, the key charachter must be unique\n");
                return 4;
            }
        }
    }

    // The key should be case-insensitive
    char key[key_length];
    for(int i = 0; i< key_length; i++)
    {
        key[i] = toupper(argv[1][i]);
    }
    

    // user input for the text
    char text [2000];
    printf("plain text:  ");
    fgets(text, sizeof(text), stdin);
    int text_length = strlen(text);
    if (text[text_length - 1] == '\n')
    {
        text[text_length - 1] = '\0';
        text_length--;
    }   

    encrypt(text_length, text, key);
    return 0;
}

// the encreption should be changing every letter to the croosponding charachter in the key
void encrypt(int text_length, char text[], char key[])
{
    char cipher[text_length];
    int x;
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            if(islower(text[i]))
            {
                x = text[i] - 'a';
                cipher[i] = tolower(key[x]);
            }
            else if(isupper(text[i]))
            {
                x = text[i] - 'A';
                cipher[i] = (key[x]);
            }
        }
        else
        {
            cipher[i] = text[i];
        }
    }
    cipher[text_length] = '\0'; 
    printf("cipher text: %s\n", cipher);
}

