#include <stdio.h>
#include <stdlib.h>
#include "history.h"



List *init_history() // initializes history. sets root to null
{
  List *history = malloc(sizeof(List)); // allocates memory for size of list
  history->root = NULL;
  return history;
}


void add_history(List *list, char *str)
{
  Item *item = malloc(sizeof(Item)); // allocates memory for a new item.
  Item *temp = list->root;

  item->str = str;
  item->next = NULL;
  int count = 0;

  if (list->root == NULL) { // if history is empty, new item becomes root
    item->id = count;
    list->root = item;
  } else {             // if history is not empty, travese through linked list to find last empty node
    count = 1;
    while (temp->next != NULL) {
      count++;
      temp = temp ->next;
    }                    // add item to list with correct id
    temp->next = item;
    item->id = count;
  }
}


char *get_history(List *list, int id)
{
  Item *temp = list->root; // starts at root of list
  while (temp != NULL) // traverses list until empty node
  {
    if (temp->id == id)  // if current nodes id matches the id its looking for, return the nodes string
    {
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL; // if id not found, returns NULL
}


void print_history(List *list)
{
  Item *temp = list->root;
  printf("\n");
  while (temp != NULL) { // traverses thru until it null
    printf("ID: %d String: %s\n", temp->id, temp->str); // prints id and string of item
    temp = temp->next;
  }
  printf("\n");
}


void free_history(List *list)
{
  Item *temp;                // temp to store old root
  while (list->root != NULL) { // Traverse through the list by setting
    temp = list->root;       // the root to be the next of current root
    list->root = list->root->next; // new root is the next of current root
    free(temp);              // frees the old root item
  }
  free(list);                // frees the memory allocated for list
}
