#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_change();
int calculate_coins(int change);

int main(void)
{
    int change = get_change();
    int coins = calculate_coins(change);
    printf("%i", coins);
    printf("\n");
}

int get_change()
{
    float fChange = 0.00;

    do
    {
        fChange = get_float("Change Amount: ");
    }
    while (fChange <= 0);

    int iChange = round(fChange * 100);
    return iChange;
}

int calculate_coins(int change)
{
    int totalChange = change;
    int totalCoins = 0;

    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennys = 1;

    while (totalChange > 0)
    {
        if (totalChange / quarters >= 1)
        {
            totalChange -= quarters;
            totalCoins++;
        }
        else if (totalChange / dimes >= 1)
        {
            totalChange -= dimes;
            totalCoins++;
        }
        else if (totalChange / nickels >= 1)
        {
            totalChange -= nickels;
            totalCoins++;
        }
        else if (totalChange / pennys >= 1)
        {
            totalChange -= pennys;
            totalCoins++;
        }
        else
        {
            break;
        }
    }
    return totalCoins;
}
