#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//              www.tedora.tk               //
//           ig : tedora_design             //

int get_position(char c);
void cipher_text(string plaintext, char argv[]);
bool check_duplicate(string text);

int main(int argc, string argv[])
{
    if (argv[1] == NULL) // If the parameter is null
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26) // The length of the param key should be the same size as alphabets
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc == 2 && strlen(argv[1]) == 26) // Params should be 2 compiler and key param and the key should be 26 chars
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)    //Check every char of the text
        {
            char n = argv[1][i];
            int digit = isdigit(n);
            if (!isalpha(argv[1][i]))   //To handle non-numeric key
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");    //Automatic handle too many arguments
        return 1;
    }
    if (check_duplicate(argv[1]) == 0)  //check if there is a duplicate char in the key
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string text = get_string("Text: ");
    printf("ciphertext: ");
    cipher_text(text, argv[1]);
    printf("\n");
    return 0;
}

int get_position(char c) // Get alphabetic position of a char
{
    if (c >= 'a' && c <= 'z')   // Non capital
    {
        return c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A'; // Capital
    }
    else
    {
        return -1; // Not found
    }
}

//Cipher chiffring text with STRING key algorithm
void cipher_text(string plaintext, char argv[])
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') //Non capital chars
        {
            printf("%c", tolower(argv[get_position(plaintext[i])]));
        }

        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') //Capital chars
        {
            printf("%c", toupper(argv[get_position(plaintext[i])]));
        }

        else if (isalpha(plaintext[i]) == false)    //Digits
        {
            printf("%c", plaintext[i]);
        }

    }
}

bool check_duplicate(string text)
{
    for (int i = 0, j = strlen(text); i < j; i++)   // Init the alphabet that we have to compare
    {
        for (int k = i + 1; k < j; k++) // Compare it with every alphabet
        {
            if (text[i] == text[k])
            {
                return false;
            }

        }
    }
    return true;
}