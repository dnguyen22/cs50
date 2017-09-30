#include <stdio.h>
#include <cs50.h>

void print_layer(char block, int num_spaces, int num_blocks);

void repeat_print(char character, int repeats);

int main(void)
{
    int height;

    do
    {
        printf("Height: ");
        height = get_int();
    }
    while(height < 0 || height > 23);

    for (int i = 1; i <= height; i++)
    {
        print_layer('#', (height-i), i);
        printf("\n");
    }
}

void print_layer(char block, int num_spaces, int num_blocks)
{
    repeat_print(' ', num_spaces);
    repeat_print(block, num_blocks);
    repeat_print(' ', 2);
    repeat_print(block, num_blocks);
}

void repeat_print(char character, int repeats)
{
    for (int i = 0; i < repeats; i++)
    {
        printf("%c", character);
    }
}