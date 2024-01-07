// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Stores size of dictionary to be used in size()
int sizeofdictionary;

// TEMP: VERIFY IF hashtable POINTS TO NULL
bool ishashnull(void)
{
    for (int i = 0; i < N; i++)
    {
        if (hashtable[0])
        {
            return false;
        }
    }
    return true;
}

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // allocate new node
        node *new_node = malloc(sizeof(node));
        if (!new_node)
        {
            unload();
            return false;
        }

        // hash the word
        int hashcode = hash(word);

        // put the word into the node value
        strcpy(new_node->word, word);

        // point the node to where hashtable[hashcode] is pointing to
        new_node->next = hashtable[hashcode];

        // make hashtable[hashcode] point to new node
        hashtable[hashcode] = new_node;

        // update sizeofdictionary
        sizeofdictionary++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (hashtable[i])
        {
            j++;
        }
    }

    if (j == 0)
    {
        return j;
    }
    return sizeofdictionary;
}

// Returns true if word is in dictionary else false
bool check(const char *wordToCheck)
{
    // hash the word
    int hashcode = hash(wordToCheck);

    // make a cursor initialized to the hash
    node *cursor = hashtable[hashcode];

    // make a while loop
    while (cursor != NULL)
    {
        // if words match return true
        if (strcasecmp(wordToCheck, cursor->word) == 0)
        {
            return true;
        }

        // otherwise advance
        cursor = cursor->next;
    }

    // return false when no match
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        hashtable[i] = NULL;
    }

    for (int i = 0; i < N; i++)
    {
        if (hashtable[i] != NULL)
        {
            return false;
        }
    }

    return true;
}
