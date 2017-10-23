#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string();
    //printf("String inputted: %s\n", name);

    for (int i = 0, n = strlen(name); i < n; i++)
    {
        printf("%c\n", name[i]);
    }
}