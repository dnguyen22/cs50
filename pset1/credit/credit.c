#include <stdio.h>
#include <cs50.h>

bool validate_card(long long card_number);

int count_digits(long long card_number);

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

    // Checksum to validate card
    bool is_valid = validate_card(card_number);
    int digit_count = count_digits(card_number);

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
                if (digit_count == 15)
                {
                    printf("AMEX\n");
                }
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                if (digit_count == 16)
                {
                    printf("MASTERCARD\n");
                }
                break;
            default:
                if ((card_id /= 10) == 4 && (digit_count == 13 || digit_count == 16))
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }

        }
    }
}

// Calculates checksum of credit card
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

// Returns first two digits of card number
int get_card_id(long long card_number)
{
    while(card_number >= 100)
    {
        card_number /= 10;
    }

    int card_id = card_number;

    return card_id;
}

// Returns number of digits in card number
int count_digits(long long card_number)
{
    int num_digits = 0;

    while(card_number > 0)
    {
        card_number /= 10;
        num_digits++;
    }

    return num_digits;
}