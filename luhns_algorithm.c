#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int get_length(double number)
{
    int length = floor(log10(fabs(number))) + 1;  //NBR CHIFRRES
    return length;
}

double get_first_2numb(double number)
{
    double dig = number;

    while (dig >= 100) //it should be less than 100 to have 2 digits
    {
        dig /= 10;
    }
    return dig;
}

double get_first_1numb(double number)
{
    double dig = number;

    while (dig >= 10)   //it should be less than 10 to have 1 digit
    {
        dig /= 10;
    }
    return dig;
}

void get_type_card(double number)
{
    int length = get_length(number);
    int first2 = get_first_2numb(number);
    int first1 = get_first_1numb(number);
    if (length == 15)
    {
        if (first2 == 34 || first2 == 37)
        {
            printf("AMEX\n"); //American Express
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (length == 16)
    {
        if (first2 == 51 || first2 == 52 || first2 == 53 || first2 == 54 || first2 == 55)
        {
            printf("MASTERCARD\n"); //Mastercard
        }
        else if (first1 == 4)
        {
            printf("VISA\n");   //Visa
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (length == 13)
    {
        if (first1 == 4)
        {
            printf("VISA\n");   //Visa
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhn_algorithm(long number, int length)
{
    int i = 0;
    int temp = 0;
    int first = 0;
    int second = 0;
    int final = 0;

    while (number)
    {
        if (i % 2 != 0)
        {
            first = ((number % 10) * 2);
            if (first > 9) //If the calculated number equal or more than 10
            {
                while (first)
                {
                    temp += first % 10;
                    first /= 10;
                }
            }
            temp += first;  //Pair sum
        }
        else
        {
            second += number % 10;  //Impair plus pair
        }
        number /= 10;
        i++;
    }

    temp += second;

    final = temp % 10;

    if (final == 0) //Check if its valid thenn the card number is valid
    {
        return 1;   //True
    }

    return 0;   //False
}

int main(void)
{
    double number = get_double("Number : ");
    int length = get_length(number);
    int check = luhn_algorithm(number, length);
    if (check == 1) //Checking with luhn algo before the card type
    {
        get_type_card(number);  //Return card type
    }
    else
    {
        printf("INVALID\n");
    }
}

