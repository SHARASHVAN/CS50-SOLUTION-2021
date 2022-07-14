#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int main(void)
{
    string text = get_string("Text:");
    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')  // we counting the no. of spaces
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!') //this if for identifying sentences
        {
            sentences++;
        }
        else
        {
            continue;
        }
    }
    words += 1; // to account for the last word
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16) // to assign the grade which excede 16
    {
        printf("Grade 16+\n");
    }
    else if (index > 1 && index < 16)
    {
        printf(" Grade %i\n", index); // to assign the grades lying between 1 and 16
    }

    return 0;
}