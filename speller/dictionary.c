// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//number of buckets in hashtable is 2 ^ 16
const unsigned int N = 65536;

// Hash table
node *table[N];

//initiate count
int count=0;

//declare head to NULL
node *head = NULL;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //int for length
    int length =strlen(word);
    //copy of word
    char copy[length+1];
    //value for end of word
    copy[length] = '\0';
//go through word
 for (int i = 0; i < length; i++)
    {
        copy[i] = tolower(word[i]);
    }
        //set hash
       int hcode=hash(copy);
       //set node for table
       node *tmp=table[hcode];
       // if tmp is null
       if(tmp==NULL)
       {
           return false;
        }
        // if there is a word
       while(tmp!=NULL)
       {
           if(strcasecmp(tmp->word,copy)==0)
           {
               return true;
           }
                tmp=tmp->next;
       }
       return false;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;

    int w = *word;

    while (w == *word++)
    {
        hash = ((hash << 5) + hash) + w;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open file
   FILE *file=fopen(dictionary,"r");
   //if nothings there
   if(file==NULL)
   {
       return false;
   }
   {
       //assign char
      char w[LENGTH+1];
      //scan file
       while(fscanf(file,"%s",w)!=EOF)
       {
           //allocate memeroy
       node *n=malloc(sizeof(node));
          if(n==NULL)
          {
              //if not close
            fclose(file);
           return false;
          }
        //if there is
         else
          {
              //copy to node
              strcpy(n->word,w);
            //point to null
           n->next=NULL;
            //hash the word
           unsigned int index =hash(w);
            //dont orphan & ++ count
            n->next=table[index];
            table[index]=n;
            count++;
             }
       }
       //close file and return true
       fclose(file);
       return true;
   }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //just return the count
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //loop through arrays
    for(int i=0;i<N;i++)
   {
       //set a copy node
        node *copy=table[i];
        //if it's there then
        while(copy!=NULL)
        {
            //unload the memory and free tmp
           node *tmp = copy;
            copy = copy -> next;
            free(tmp);
        }
   }
    //return true
    return true;
}
