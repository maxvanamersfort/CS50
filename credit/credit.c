#include <stdio.h>
#include <cs50.h>
#include <math.h>

    int main(void)
    {
        //declare long long cardnumber = 0
        long long cardnumber = 0;

        //promt user for card number & do/while loop to make sure no negative input is used
        do
        {
            cardnumber= get_long_long("card number: ");
        }
        while (cardnumber < 0);

        //daclare int count = 0 & long long digits = cardnumber & break loop if bigger then 0
        int count = 0;
        long long digits = cardnumber;
        while (digits > 0)

        //decalring digits to be divided by 10 & setting count to 1
        {
            digits = digits/10;
            count++;
        }

        //make sure the input takes & making array count
        if ((count != 13)&& (count != 15)&& (count != 16))
        {
            printf("INVALID\n");
        }
        int number[count];

    //starting the formula for the card
    for (int i = 0; i < count; i++)
    //declaring number[i] = cardnumber % 10 & cardnumber = cardnumber / 10
    {
        number[i] = cardnumber % 10;
        cardnumber = cardnumber / 10;
    }

    int originalnumber[count];
    for (int i = 1; i < count; i++)
    {
        originalnumber[i] = number[i];
    }

    for (int i = 1; i < count; i+=2)
    {
        number[i] = number[i] * 2;
    }

    int v = 0;
    int temp;

    if (count == 13)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[12] == 4 && v % 10 == 0)
      {
        printf("VISA\n");
      }
      else
      {
        printf("INVALID\n");
      }
    }
    if (count == 15)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[14] == 3 && v % 10 == 0 && (originalnumber[13] == 4 || originalnumber[13] == 7))
      {
        printf("AMEX\n");
      }
      else
      {
        printf("INVALID\n");
      }
    }
    if (count == 16)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[15] == 4 && v % 10 == 0)
      {
        printf("VISA\n");
      }
      else if (originalnumber[15] == 5 && v % 10 == 0 && (originalnumber[14] == 1 || originalnumber[14] == 2 || originalnumber[14] == 3 || originalnumber[14] == 4 || originalnumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }
      else
      {
        printf("INVALID\n");
      }
    }

    return 0;
    }

