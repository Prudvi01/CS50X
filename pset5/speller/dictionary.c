// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

#define H_SIZE 99999

unsigned int counter = 0;

//Initialising a new data type.
typedef struct node
{
    char text[LENGTH + 1];
    struct node *next;
}
node;

//Creating a hashtable to store the dictionary.
node hashtable[H_SIZE];

//HASH FUNCTION
// Ref: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
inline size_t hashOf(const char *word)
{
    unsigned int hash = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ toupper(word[i]);
    }
    return hash % H_SIZE;
}




// Returns true if word is in dictionary else false
bool check(const char *word)
{

    node *cursor;
    cursor = hashtable[ hashOf(word) % H_SIZE ].next;
    /*CHECKING EACH AND EVERY NODE IN THE LINKED LIST CORRESPONDING
        TO THE HASHTABLE'S INDEX.*/
    while (cursor != NULL)
    {
        node *temp = cursor;
        if (strcasecmp(temp -> text, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char Text[LENGTH + 1];

    FILE *fp = fopen(dictionary, "r");

    while (fscanf(fp, "%s", Text) != EOF)
    {
        //ALLOCATING MEMORY SPACE TO THE NEWNODE.
        node *newnode  = malloc(sizeof(node));

        /*IF MEMORY COULD NOT BE ALLOCATED TO THE NEW NODE THE DICTIONARY
            IS UNLOADED AND EXIT CODE FALSE IS RETURNED*/
        if (newnode == NULL)
        {
            unload();
            return false;
        }

        //COPYING THE WORD INTO THE NODE'S TEXT.
        strcpy(newnode -> text, Text);

        //node *cursor;

        size_t index = hashOf(Text) % H_SIZE;

        //TO ENTER THE NEW NODE TOTHE LINKED LIST.
        newnode -> next = hashtable[index].next;
        hashtable[index].next = newnode;

        //TO COUNT THE NUMBER OF WORDS IN THE DICTIONARY.
        counter++;

    }
    //CLOSING THE DICTIONARY FILE.
    fclose(fp);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int index = 0; index < H_SIZE; index++)
    {
        if (hashtable[index].next == NULL)
        {
            continue;
        }
        else
        {
            node *cursor;
            cursor = hashtable[index].next;
            while (cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor -> next;

                //TO FREE THE ALLOCATED MEMORY SPACE.
                free(temp);

            }
        }

    }
    return true;
}


//END OF PROGRAM FILE.