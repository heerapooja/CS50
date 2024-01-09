#include <cs50.h>
#include <stdio.h>
/*
TODO
* prompt for user input
* calc checksum
* check for card length

* American Express uses 15-digit numbers and start with 34 or 37,
* MasterCard uses 16-digit numbers, and start with 51, 52, 53, 54, or 55
* Visa uses 13- and 16-digit numbers and start with 4.
*/
int main(void)
{
    long cardnum = get_long("Card Number: ");
    int r;
    int sum = 0;
    int len = 0;
    long num = cardnum;
    while (num)
    {
        num = num / 10;
        len++;
    }
    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // calculating checksum
    num = cardnum;
    while (num)
    {
        r = num % 100;    // 2 digit remainder
        sum += r % 10;    // add digit that are not to multiply by 2
        r = (r / 10) * 2; // extract 2nd digit everyime
        if (r >= 0 && r <= 9)
        {
            sum += r;
        }
        else
        {
            while (r)
            { // while the rem is of 2 digit
                sum += r % 10;
                r = r / 10;
            }
        }
        num = num / 100;
    }

    // Luhn Algorithm to check the last digit of the sum
    if (sum % 10)
    {
        printf("INVALID\n");
        return 0;
    }
    // extract starting digits
    long startdigit = cardnum;
    do
    {
        startdigit = startdigit / 10;
    } while (startdigit > 100);

    if (startdigit / 10 == 3 && (startdigit % 10 == 4 || startdigit % 10 == 7))
        printf("AMEX\n");

    // check for 50 to 55
    else if ((startdigit / 10 == 5) && (startdigit % 10 > 0 && startdigit % 10 < 6))
        printf("MASTERCARD\n");
    else if (startdigit / 10 == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");
    return 0;
}
