#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)

{
    int letters= 0;
    int words= 1;
    int sentences= 0;

    //prompt text and return
    string text = get_string("Text: ");
    //printf("Text: %s\n", text); for the print text again check

    //count letters and print output
    int textnum = strlen(text);
    for (int i= 0; i < textnum; i++)
    {
        if(isalpha(text[i]))
        {
        letters++;
        }
    }
    //printf("%i letters\n", letters); for the letters check

    //count words and print output
    int wordsnum = strlen(text);
    for (int i= 0; i < wordsnum; i++)
    {
        if(isspace(text[i]))
        {
            words++;
        }
    }
    //printf("%i words\n", words); for the words check

    //count sentences and print output
    int sentnum = strlen(text);
    for (int i= 0; i < sentnum; i++)
    {
        if(text[i] =='.' || text[i] =='?' || text[i] =='!')
        {
            sentences++;
        }
    }
    //printf("%i sentences\n", sentences); for the sentences check

    //index = 0.0588 * L - 0.296 * S - 15.8

    //calaculate the readability index
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);

    //making output if < 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    //making output if > 16
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    //making output if within parameters
    else
    {
        printf("Grade %i\n", index);
    }
}
