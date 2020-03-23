#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool authenticate(long cardNum);
void print_card_type();
bool amex_check(long cardNum);
bool visa_check_one(long cardNum);
bool visa_check_two(long cardNum);
bool mastercard_check(long cardNum);
bool luhns_test(long cardNum, int numOfDigits);

int main(void)
{
    bool authenticated = false;
    long cardNum = 0;
    do
    {
        cardNum = get_long("Card Number: ");
    }
    while (cardNum <= 0);
    authenticated = authenticate(cardNum);
}

bool authenticate(long cardNum)
{
    int numOfDigits = 0;
    string cardType = "INVALID\n";
    //Figure out how many digits are in the card number entered
    if (amex_check(cardNum))
    {
        numOfDigits = 15;
        cardType = "AMEX\n";
    }
    else if (mastercard_check(cardNum))
    {
        numOfDigits = 16;
        cardType = "MASTERCARD\n";
    }
    else if (visa_check_one(cardNum))
    {
        numOfDigits = 16;
        cardType = "VISA\n";
    }
    else if (visa_check_two(cardNum))
    {
        numOfDigits = 13;
        cardType = "VISA\n";
    }

    if (!luhns_test(cardNum, numOfDigits))
    {
        printf("%s", "INVALID\n");
        return false;
    }
    else
    {
        printf("%s", cardType);
        return true;
    };
}

bool amex_check(long cardNum)
{
    long amexDigitCheck = 10000000000000;
    int cardNumCheck = cardNum / amexDigitCheck;
    if (cardNumCheck == 34 || cardNumCheck == 37)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool visa_check_one(long cardNum)
{
    long visaDigitCheck = 100000000000000;
    
    int cardNumCheck = cardNum / visaDigitCheck;
    cardNumCheck = cardNumCheck / 10; 

    if (cardNumCheck == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool visa_check_two(long cardNum)
{
    long visaDigitCheck = 1000000000000;
    int cardNumCheck = cardNum / visaDigitCheck;
    if (cardNumCheck == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool mastercard_check(long cardNum)
{
    long mastercardDigitCheck = 100000000000000;
    int cardNumCheck = cardNum / mastercardDigitCheck;
    if (cardNumCheck <= 55 && cardNumCheck >= 51)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool luhns_test(long cardNum, int numOfDigits)
{
    //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    int totalSum = 0;   
    int switcher = 1;

    for (int i = 1; i <= numOfDigits; i++)
    {
        long multiplier = 1;

        //This is the first iteration. The multiplier isn't used here which is why it is separate.
        if (switcher % 2 == 1 && i == 1)
        {
            totalSum += (cardNum % 10);
        }
        else if (switcher % 2 == 0)
        {
            for (int j = 2; j <= i; j++)
            {
                multiplier = multiplier * 10;
            }
            //This code block handles when a product of the multiplication is greater than 9. We add the digits individually per reqs.
            int dubDigit = ((cardNum / multiplier) % 10) * 2;
            if (dubDigit > 9)
            {
                totalSum += (dubDigit  % 10);
                totalSum += ((dubDigit / 10) % 10);
            }
            else
            {
                totalSum += ((cardNum / multiplier) % 10) * 2;
                int console = ((cardNum / multiplier) % 10) * 2;
            }
        }
        //Add the sum to the sum of the digits that weren’t multiplied by 2.
        else
        {
            for (int h = 2; h <= i; h++)
            {
                multiplier = multiplier * 10;
            }
            totalSum += ((cardNum / multiplier) % 10);
            int console = ((cardNum / multiplier) % 10);
        }
        switcher++;
    }

    //If the total modulo 10 is congruent to 0, the number is valid!
    totalSum = totalSum % 10;
    if (totalSum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
