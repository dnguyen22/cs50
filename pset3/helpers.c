/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <string.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Binary search O(log(n))
    int lower_index = 0;
    int upper_index = n - 1;

    do
    {
        // Check middle index
        int middle_index = (lower_index + upper_index) / 2;

        if (values[middle_index] == value)
        {
            return true;
        }

        // Reassign upper and lower index for next search
        if (values[middle_index] > value)
        {
            upper_index = middle_index - 1;
        }
        else
        {
            lower_index = middle_index + 1;
        }
    }
    while (upper_index >= lower_index);

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // maximum amount of hay
    const int MAX = 65536;

    // Array stores number of times value appears in values
    int value_count[MAX];
    memset( value_count, 0, MAX*sizeof(int) );
    int index = 0;

    // Loop through values to count value
    for (int i = 0; i < n; i++)
    {
        value_count[values[i]]++;
    }

    // Loop through value_count and fill in values sorted
    for (int j = 0; j < MAX; j++)
    {
        for (int k = value_count[j]; k > 0; k--)
        {
            values[index] = j;
            index++;
        }
    }

    return;
}
