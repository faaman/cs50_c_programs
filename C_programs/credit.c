#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    long card_no = 0, no_counting;
    int count_digits = 0, first_digit, temp;
    long big_ten = 1000000000000000;

    printf("What is your credit card number: ");

    while (scanf("%ld", &card_no) != 1)
    {
    	while (getchar() != '\n');
    	printf ("Non-numeric input, try again: ");
    }
    
    no_counting = card_no;

    //find how many digits in the card number
    while (no_counting > 0)
    {
        no_counting = no_counting / 10;
        count_digits = count_digits + 1;
    }
	
    no_counting = card_no;
    int my_digits[count_digits];
    temp = 0;
    int num = 1;
    int checksum = 0;
    do
    {
        my_digits[temp] = no_counting % 10;

        //find checksum
        if (num % 2 == 0)
        {
            if ((my_digits[temp] * 2) > 9)
            {
                int u = (my_digits[temp] * 2) / 10;
                int v = (my_digits[temp] * 2) % 10;
                checksum = checksum + u + v;
            }
            else
            {
                checksum = checksum + (my_digits[temp] * 2);
            }
        }
        else
        {
            checksum = checksum + my_digits[temp];
        }

        num++;
        temp++;
        no_counting = no_counting / 10;
    }
    while (no_counting > 0);
    //done filling array, in reverse actually because we need it that way, so that we can get to multiply from second last digit

    int index_zero = count_digits - 1;
    int index_one = count_digits - 2;
    int starter = (my_digits[index_zero] * 10) + my_digits[index_one];

    //calculate checksum
    int our_mod = checksum % 10;
    if (our_mod != 0)
    {
        printf("INVALID 1\n");
        return 0;
    }
    else
    {

        //find if correct visa first digit
        if (count_digits == 16)
        {
            first_digit = card_no / 1000000000000000;
            if (first_digit == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else if (starter <= 55 && starter >= 51)
            {
                // or mastercard
                printf("MASTERCARD\n");
                return 0;
            }
            else
            {
                printf("INVALID 2\n");
                return 0;
            }
        }
        else if (count_digits == 13)
        {
            int a = card_no / 1000000000000;
            if (a == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID 3\n");
                return 0;
            }
        }
        //find if correct amex first digit
        else if (count_digits == 15)
        {
            if (starter == 34 || starter == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID 4\n");
                return 0;
            }
        }
        else
        {
            printf("INVALID 5\n");
            return 0;
        }

    }
}
