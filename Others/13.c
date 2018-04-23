//A program that tells the month of your birth

#include <stdio.h>

int main (void)
{
int m= 0;

printf("Birthmonth: \n");
    scanf("%i", &m);

    if (m==1)
    printf ("Your birthmonth is January!\n");

    else if (m==2)
    printf ("Your birthmonth is February!\n");

      else if (m==3)
    printf ("Your birthmonth is March!\n");

      else if (m==4)
    printf ("Your birthmonth is April!\n");

      else if (m==5)
    printf ("Your birthmonth is May!\n");

      else if (m==6)
    printf ("Your birthmonth is June!\n");

      else if (m==7)
    printf ("Your birthmonth is July!\n");

      else if (m==8)
    printf ("Your birthmonth is August!\n");

      else if (m==9)
    printf ("Your birthmonth is September!\n");

      else if (m==10)
    printf ("Your birthmonth is October!\n");

      else if (m==11)
    printf ("Your birthmonth is November!\n");

  else if (m==12)
    printf ("Your birthmonth is December!\n");
    else
    printf ("Type your birthmonth using a number\n");
}
