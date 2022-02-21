#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int main(void)
{

    //Prompt user for text
    string userinput = get_string("Text: ");

    // Number of letters 
    int lettertotal = strlen(userinput);

    int lettercount = 0;

    for (int i = 0; (i < lettertotal); i++)
    {
        if (isalpha(userinput[i]))
        {
            lettercount = lettercount + 1;
            }
    }

    // Calculate number of words with strlen
    int wordtotal = strlen(userinput);

    int wordcount = 1;

    for (int i = 1; (i < wordtotal); i++)
    {
        if ((isspace(userinput[i])) && (isalpha(userinput[i + 1])))
        {
            wordcount = wordcount + 1;
        }
    }


    int sentencetotal = strlen(userinput);

    int sentencecount = 0;
    for (int i = 0; (i < sentencetotal); i++)
    {
        if (userinput[i] == '.' || userinput[i] == '?' || userinput[i] == '!' || userinput[i] == ':') //|| userinput[i] == ';')
    {
            sentencecount = sentencecount + 1;
     }
    }
    

    // average number of letters per 100 words
    float averagenumberoflettersper100words = ((float)lettercount * 100) / (float)wordcount;
    

    // average number of sentences per 100 words
    float averagenumberofsentencesper100words = ((float)sentencecount * 100) / (float)wordcount;
   

    // Calculate grade range
    float grade = 0.0588 * averagenumberoflettersper100words - 0.296 * averagenumberofsentencesper100words - 15.8;
    //float finalgrade = round(grade);

    if (grade >= 1 && grade <= 16)
    
    {
        printf("Grade %i\n", (int) round(grade));
    }

    else
    {
        if (grade < 1)
        {
           printf("Before Grade 1\n");
        }
   
    }

    {
       if (grade > 16)
        {
           printf("Grade 16+\n");
        }
    }
}