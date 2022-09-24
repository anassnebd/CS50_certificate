#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Init functions
int compute_score(string word);
int get_position(char c);
void compare_score(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    //  printf("Score 1 %d",score1);
    //  printf("Score 2 %d",score2);

    // Compare and Print the winner
    compare_score(score1, score2);
}

int compute_score(string word)
{
    int count = 0;
    int score = 0;
    // Compute and return score
    for (int i = 0; word[i] != '\0'; i++)
    {
        count++; // Length of a word
    }

    for (int j = 0; j < count; j++)  // Get the score of every Alphabet
    {
        int p = get_position(word[j]);
        if (p != -1)
        {
            score += POINTS[p];
        }
        else
        {
            score += 0;
        }
    }
    return score;
}

int get_position(char c) // Get alphabetic position of a char
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else
    {
        return -1; // Not found
    }
}

void compare_score(int score1, int score2) // Compare scores and print result
{
    if (score1 == score2) // Tie
    {
        printf("Tie!\n");
    }
    if (score1 > score2) // Win
    {
        printf("Player 1 wins!\n");
    }
    if (score1 < score2) // Lost
    {
        printf("Player 2 wins!\n");
    }
}
