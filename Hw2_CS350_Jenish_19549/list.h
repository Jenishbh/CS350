#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

// The name of the List ADT
typedef struct list LIST;

// Create a new List ADT
LIST* createList(int (*compare)(void*, void*));

// Insert a new item to the List
void insert(LIST* L, void* newitem);

// Delete a target item from the list
void delete(LIST* L, void* target);

// Search and retrieve an target item
void* search(LIST* L, void* target);

// Display the entire List
void displayList(LIST* L, void (*display)(void*));

// Destroy the List ADT
void destroyList(LIST* L);