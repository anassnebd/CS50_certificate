#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void cipher_text(string plaintext, int key);


//              www.tedora.tk               //
//           ig : tedora_design             //

//Return 1 means that there is an error
int main(int argc, string argv[])
{
    if (argv[1] == NULL)    //To handle null params key
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    if (argc == 2 && (atoi(argv[1]) > 0))
        for (int i = 0, len = strlen(argv[1]); i < len; i++)    //Check every char of the text
        {
            char n = argv[1][i];
            int digit = isdigit(n);
            if (!isdigit(argv[1][i]))   //To handle non-numeric key
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

    else    //Automatically handle too many arguments
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // To handle the lack of argv[1] i declared the ey after testing all possibilities null, isdigits etc...
    int key = atoi(argv[1]);
    string text = get_string("Text: ");
    printf("ciphertext: ");
    //Calling algorithm
    cipher_text(text, key);
    printf("\n");
    return 0;
}

//Cipher chiffring text with key algorithm
void cipher_text(string plaintext, int key)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') //Non capital chars
        {
            printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
        }

        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') //Capital chars
        {
            printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
        }

        else if (isalpha(plaintext[i]) == false)    //Digits
        {
            printf("%c", plaintext[i]);
        }

    }
}
