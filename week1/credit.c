#include <cs50.h>
#include <stdio.h>
//declaring the functions below:-
void print_credit_card_brand(long long ccn);
bool checksum(long long ccn);
bool check_validity(long long credit_card_number);
int find_length(long long n);

int main(void)
{
    long long credit_card_number; //the input will take more than 4 bits and doest not contain decimals.
    do
    {
        credit_card_number = get_long_long("Enter your card number: ");
    }
    while (credit_card_number < 0); // card number must be +ve.
    if (check_validity(credit_card_number) == true)
    {
        print_credit_card_brand(credit_card_number);
    }
    else
    {
        printf("INVALID\n");
    }


}


bool check_validity(long long credit_card_number)  //function to check validity of the card
{
    int len = find_length(credit_card_number);

    return (len == 13 || len == 15 || len == 16) && checksum(credit_card_number);

}

int find_length(long long n) // function to check length of the card
{
    int len;
    for (len = 0; n != 0; n /= 10, len++)
        ;
    return len;
}

bool checksum(long long ccn)  // summation of 2*n place + 2n+1 places
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            int digit = 2 * (ccn % 10);
            sum += digit / 10 + digit + 10;
        }
    }
    return sum % 10 == 0;
}
void  print_credit_card_brand(long long ccn) // function to print the brand name
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))   // structure of american express

    {
        printf("AMEX\n");
    }

    else if (ccn >= 51e14 && ccn < 56e14)   // structue of mastercard
    {
        printf("MASTERCARD\n");
    }


    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))   // structue of visa
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

