#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Get name from user
    string name = get_string();

    // Loop through user input
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // Ignore spaces
        if (name[i] != ' ')
        {
            // Print capitalized letter if first in string or after a space
            if (i == 0 || name[i-1] == ' ')
            {
                printf("%c", toupper(name[i]));
            }
        }
    }

    // Create new line after looping through input
    printf("\n");
}