// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Global Variables
int words_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 500000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Get the length of word + one space for the null character    
    int length = (strlen(word) + 1);
    // Temporary variable to store the lowercase characters 
    char tmp[length];
   
    // Convert all the characters of a word to lower case to be compared with lower case characters on the dictionary
    for (int i = 0; i < (length - 1); i++)
    {
        char c = tolower(word[i]);
        tmp[i] = c;
    }
   
    // Insert the null character at the end of the word
    tmp[length - 1] = '\0';
   
    // Hash the words stored in the tmp variable and get it an index
    int header = hash(tmp);

    // Loop to compare the words in the text with the words of the dictionary stored in the hash table.
    for (node *cursor = header[index]; cursor != NULL; cursor = cursor->next)
    {
        // If the words matchs the word in the hash table, return true
        if (strcasecmp(cursor->word, tmp) == 0)
        {
             return true;
           
        }
       
    }
    // Otherwise, return false
    return false;
}




// Hashes word to a number
// Hash function *djb2* by Dan Bernstein 
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c = 0;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % N;

}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];

    // Open the dictionary files
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Error! Can't open the file.\n");
        return false;
    }

    // Loop to scan the file
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Increase words_count to use it on the function Size
        words_count++;

        // Allocate memory for a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Error, not enough memory!\n");
            return false;
        }

        // Copy the content from word to n->word
        strcpy(new_node->word, word);

        // Call function hash and store an number as index
        int index = hash(new_node->word);

        // Create first node of an empty linked list.
        if (table[index] == NULL)
        {
            table[index] = new_node; // Point table[index] to new_node
            new_node->next = NULL; // new_node points to null
        }
        // If linked list not empty, insert a new node
        else
        {
            new_node->next = table[index]; // New node points at what table[index] is pointing at
            table[index] = new_node; // Table[index] points at new node
        }
    }

    // Close dictionary
    fclose(dict);
    return true;
}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return words_count;
}



// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Loop to iterate over the hash table and each node to then free them
    for (int i = 0; i < N; i++)
    {
        // Cursor points to where table[i] points
        node *cursor = table[i];

        while (cursor != NULL)
        {
            // TMP node points to where cursor points at
            node *tmp = cursor;
            // Cursor moves one element forward in the linked list, while tmp continues to point at the previous element
            cursor = cursor->next;
            // Free the node that tmp is pointing at without losing the track because cursor is pointing to the next element
            free(tmp);

        }
        // After all have been freed, free cursor.
        free(cursor);
    }

    return true;
}
