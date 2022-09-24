#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Init functions
int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
double avg_letters(int letters, int words);
double avg_sentences(int sentences, int words);
int coleman_liau_formula(double letters, double sentences);

int main(void)
{
    // Scanning
    string text = get_string("Text:");

    int letters = count_letters(text);
    int sentences = count_sentences(text);
    int words = count_words(text);
    double lett = avg_letters(letters, words);
    double sent = avg_sentences(sentences, words);
    int index = coleman_liau_formula(lett, sent);

    if (index < 1)
    {
        printf("Before Grade 1\n"); // if the index is negative
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n"); // if the index is more than 16
    }
    else
    {
        printf("Grade %d\n", index); // Normal index grade
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++) //Boucle finish after the last alphabet
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) // Filtering letters
        {
            letters++;
        }
    }
    return letters;
}

int count_sentences(string text)
{
    int count = 0;
    int i = 0;
    while (text[i] != '\0') // Boucle finish after the last alphabet
    {
        // A sentence should finish with a ? . !
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') // Divide text by sentences
        {
            count++;
        }
        i++;
    }
    return count;
}

int count_words(string text)
{
    int count = 1; //it starts by 1 becauze it stops counting before the last word
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ') // Filtering split words by space
        {
            count++;
        }
    }
    return count;
}

double avg_letters(int letters, int words)
{
    return (double)letters / (double)words * 100;
}

double avg_sentences(int sentences, int words)
{
    return (double)sentences / (double)words * 100;
}

int coleman_liau_formula(double avg_letters, double avg_sentences) // Coleman liau formula : index = 0.0588 * L - 0.296 * S - 15.8
{
    return round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8); // Around result
}
