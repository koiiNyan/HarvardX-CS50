// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

// Defining a size of a hashtable
#define HASHTABLE_SIZE 500

// Creating nodes

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Creating a hashtable
node *hashtable[HASHTABLE_SIZE];


// Create global boolean for tracking load/unload dictionary operations
bool loaded = false;


// Hash function from https://github.com/hathix/cs50-section/blob/master/code/7/sample-hash-functions/good-hash-function.c
int hash_function(const char* word)
 {
     unsigned long hash = 5381;

     for (const char* ptr = word; *ptr != '\0'; ptr++)
     {
         hash = ((hash << 5) + hash) + tolower(*ptr);
     }

     return hash % HASHTABLE_SIZE;
 }




// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Making an array for a copy of the word so we can make all characters of it lowercase to compare strings (we cant edit const char)
    int word_len = strlen(word);
    char word_copy[word_len + 1];

    // Converting input word to lowercase and storing it in a copy array
    for (int i = 0; i < word_len; i++)
    {
        word_copy[i] = tolower(word[i]);
    }

    // Adding null to the end of the string
    word_copy[word_len] = '\0';

    //Hashcode returned from calling hash function
    int hashcode = hash_function(word_copy);

    //Check words until the end of the linked list
    for(node *cursor = hashtable[hashcode]; cursor!=NULL; cursor = cursor->next)
        if(strcmp(cursor->word,word_copy)==0)
            return true;
    return false;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Opening a dictionary file for READING
    FILE *file = fopen(dictionary, "r");
    char word[LENGTH + 1];

    // Scan dictionary word by word till the end of the file
    while (fscanf(file, "%s", word) != EOF)
    {

        /* Allocating memory to store nodes while reading the file
        Using sizeof to calculate the size in bytes of a node  */

        // Malloc a node* for each new word
        node *individual_node = malloc(sizeof(node));
        //If you're running out of memory, malloc will return NULL.
        if (individual_node == NULL)
        {
            unload();
            return false;
        }
        //If everything's OK, copy word into node
        strcpy(individual_node->word, word);

        //Hashcode returned from calling hash function
        int hashcode = hash_function(individual_node->word);
        //Insert node into a linked list
        // Setting node's next pointer to the current head
        individual_node->next = hashtable[hashcode];
        // Moving the head pointer to the newly-created node
        hashtable[hashcode] = individual_node;

    }

    loaded = true;
    return true;
}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Creating a variable to count words
    int word_counter = 0;
      // Making a for loop to loop through all words in a hashtable

    for(int index = 0; index < HASHTABLE_SIZE; index++)
        for(node* cursor=hashtable[index]; cursor!=NULL; cursor = cursor->next)
            word_counter++;

    if (loaded)
    {
        return word_counter;
    }
    else
    {
        return 0;
    }
}





// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Making a for loop to loop through all words in a hashtable
    for (int index = 0; index < HASHTABLE_SIZE; index++)
    {

        // Node pointing to the first element in a linked list
        node *cursor = hashtable[index];

        while (cursor != NULL)
        {
            // Creating a temporary node ponter to a cursor
            node *temp = cursor;
            // Advance cursor
            cursor = cursor->next;
            // Free temporary pointer
            free(temp);
        }
    }


    loaded = false;
    return true;
}
