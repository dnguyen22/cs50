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
    // TODO: implement a searching algorithm
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
