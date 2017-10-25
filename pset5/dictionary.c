/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH+1];
    struct node *next;
}
node;

// Allocate memory for hashtable
node *hashtable[HASHTABLE_SIZE] = { NULL };

// Keep track of words in dictionary
unsigned int word_count = 0;
//node *node1 = malloc(sizeof(node));  // Create node
//strcpy(node1->word, "Hello");  // Add word to node
//node1->next = node2;  // Link nodes

/**
 * Hash function via cs50 subredit / reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_func(char* hash_input)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(hash_input); i<n; i++)
        hash = (hash << 2) ^ hash_input[i];
    return hash % HASHTABLE_SIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // Capital letters is breaking hash function. Must tolower word
    int len = strlen(word);
    char word_copy[len+1];

    for (int i = 0; i < len; i++)
    {
        word_copy[i] = tolower(word[i]);
    }

    // Add null
    word_copy[len] = '\0';

    int hash_index = hash_func(word_copy);

    // Travel linked list
    node *cursor = hashtable[hash_index];
    while (cursor != NULL)
    {
        // do something
        if (strcasecmp(cursor->word, word) == 0)
        {
            // Words match
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // Open file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        // Failure to open dictionary
        return false;
    }

    // Holds word from fscanf
    char word[LENGTH+1];
    int hash_index;

    while (fscanf(file, "%s", word) != EOF)
    {
            // Create new dictionary entry
        node *dict_entry = malloc(sizeof(node));
        if (dict_entry == NULL)
        {
            unload();
            return false;
        }
        dict_entry->next = NULL;
        strcpy(dict_entry->word, word);

        //fprintf(stderr, "Next word: %s\n", dict_entry->word);
        // Hash word
        hash_index = hash_func(dict_entry->word);
        //fprintf(stderr, "Hash bucket: %d\n", hash_index);
        // Add dict_entry to hash table
        if (hashtable[hash_index] == NULL)
        {
            // Bucket is empty
            hashtable[hash_index] = dict_entry;
        }
        else
        {
            // Bucket is not empty, add dict_entry to start of linked list
            dict_entry->next = hashtable[hash_index];
            hashtable[hash_index] = dict_entry;
        }

        // Increment dictionary word count
        word_count++;
    }

    // Close file
    fclose(file);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // Loop through hash table
    for (int i = 0; i < HASHTABLE_SIZE; i ++)
    {
        node *cursor = hashtable[i];

        // Loop through linked list
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
