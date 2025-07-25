#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letters (char text []);
int words (char text []);
int sentences (char text []);

int main(void)
{
    // prompt userto input a text
    char text [2000];
    printf("Text: ");
    fgets(text , sizeof(text), stdin);
    
    //L is the average number of letters per 100 words in the text
    float L = letters(text) /(float)words(text) * 100;
    printf("%f\n", L);

    //S is the average number of sentences per 100 words in the text.
    float S = sentences(text) /(float)words(text) * 100;

    /*The Coleman-Liau index of a text is designed to output 
    that (U.S.) grade level that is needed to understand some text.*/
    int index = (int)round(0.0588 * L - 0.296 * S - 15.8);
    printf("%d\n", index);

    // Print the grade level 
    if (index > 16)
    {
        printf("grade 16+\n");
    }
    else if(index < 1)
    {
        printf("before grade one\n"); 
    }
    else
    {   
        printf("grade %i\n", index);
    }
}






// a function to count the letters in a text
int letters (char text [])
{
    int text_length = strlen(text);
    int count_letters = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            count_letters += 1;
        }  
    }
    return count_letters;
}

// a function to count words in a text
int words (char text [])
{
    int text_length = strlen(text);
    int count_words = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (isblank(text[i]) || text[i] == '\n')
        {
            count_words += 1;
        }  
    }
    return count_words;
}

//count a sentences in a text
int sentences (char text [])
{
    int text_length = strlen(text);
    int count_sentences = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences += 1;
        }  
    }
    return count_sentences;
}


            
