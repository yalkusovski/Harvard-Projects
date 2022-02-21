// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <ctype.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// count read words
int dict_size = 0;


bool check(const char *word)
{
    int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// convertes letters to hashes
unsigned int hash(const char *word)
{

    unsigned int value = 0;

    unsigned int key_len = strlen(word);

    for (int i = 0; i < key_len; i++)
    {
        value = value + 37 * tolower(word[i]);
    }
    value = value % N;
    return value;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dict)
{

    // Open file
    FILE *file = fopen(dict, "r");


    if (dict == NULL)
    {
        printf("Unable to open %s\n", dict);
        return false;
    }
    // Initialise array
    char next_word[LENGTH + 1];

    // read letters from file open one at a time
    while (fscanf(file, "%s", next_word) != EOF)
    {
        // Create new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // word copying in node
        strcpy(n->word, next_word);

        int hash_value = hash(next_word);

        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }

    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

void destroy(node *root)
{

    if (root->next != NULL)
    {
        destroy(root->next);
    }
    free(root);

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {

        if (table[i] != NULL)

        {
            destroy(table[i]);

        }
    }

    return true;
}