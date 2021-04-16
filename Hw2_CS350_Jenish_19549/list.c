#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"

struct list
{
void* items[N];
int (*compare)(void*, void*);
int length;
};

LIST* createList(int (*compare)(void*, void*))
{
LIST* L = (LIST*) malloc(sizeof(LIST));
L->length = 0;
L->compare = compare;
return L;
}

void insert(LIST* L, void* newitem)
{
if (L->length == N)
{
printf("The list is full.\n");
return;
}
L->items[L->length] = newitem;
L->length++;
}

void* search(LIST* L, void* target)
{
int i;
for (i = 0; i < L->length; i++)
{
if (L->compare(target, L->items[i]) == 0)
{
return L->items[i];
}
}
return NULL;
}

void delete(LIST* L, void* target)
{
int i;
int found = 0;
for (i = 0; i < L->length; i++)
{
if (L->compare(target, L->items[i]) == 0)
{
found = 1;
break;
}
}
if (found)
{
L->items[i] = L->items[L->length - 1];
L->length--;
}
}

void displayList(LIST* L, void (*display)(void*))
{
int i;
for (i = 0; i < L->length; i++)
{
display(L->items[i]);
}
}

void destroyList(LIST* L)
{
int i;
for (i = 0; i < L->length; i++)
{
free(L->items[i]);
}
free(L);
}