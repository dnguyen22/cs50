#include <stdio.h>
#include <cs50.h>

bool validate_card(long long card_number);

int get_card_id(long long card_number);

int main(void)
{
    long long card_number;

    do
    {
        printf("Number: ");
        card_number = get_long_long();
    }
    while (card_number < 0);

    bool is_valid = validate_card(card_number);

    if(!is_valid)
    {
        printf("INVALID\n");
    }
    else
    {
        int card_id = get_card_id(card_number);

        switch(card_id)
        {
            case 34:
            case 37:
                printf("AMEX\n");
                break;
            case
        }
    }

    printf("For number %lld, the card is %d\n", card_number, is_valid);
}

bool validate_card(long long card_number)
{
    bool is_even_digit = false;
    int last_digit_doubled;
    int sum_even_digits = 0;
    int sum_odd_digits = 0;
    long long copy_card = card_number;

    while(copy_card > 0)
    {

        if(is_even_digit)
        {
            last_digit_doubled = (copy_card % 10) * 2;

            do
            {
                sum_even_digits += last_digit_doubled % 10;
                last_digit_doubled /= 10;
            }
            while (last_digit_doubled > 0);

        }
        else
        {
            sum_odd_digits += copy_card % 10;
        }

        copy_card /= 10;
        is_even_digit = !is_even_digit;
    }

    sum_odd_digits += sum_even_digits;

    return (sum_odd_digits % 10) == 0;
}

int get_card_id(long long card_number)
{
    while(card_number >= 100)
    {
        card_number /= 10;
    }

    int card_id = card_number;

    return card_id;
}