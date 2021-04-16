/* File: hash.c */
/* demonstrates hash table with linear probing */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS	11
#define EMPTY		-1

struct item
{
	int key;
	char name[32];
	
	
};
typedef struct item ItemType;

struct hash
{
	ItemType info[MAX_ITEMS];
};
typedef struct hash HashType;

/* constructor */
HashType* createHashTable(void);         	   			  
/* Retrieves table element whose key */
ItemType* retrieveItem(HashType* h, int targetKey);     
/* Adds item to table. */
void insertItem(HashType* h, int key, char* name);    	  
/* Print all elements in table. */
void printTable(HashType* h);

int hash(int idNum)
{
	return (idNum % MAX_ITEMS);
}

HashType* createHashTable(void)
{
	int index;
	HashType* h = (HashType *) malloc (sizeof(HashType));
	for (index = 0; index < MAX_ITEMS; index++) {
		h->info[index].key = EMPTY;
	}
	return h;
}

ItemType* retrieveItem(HashType* h, int targetKey)
{
	int startLoc = hash(targetKey);
	int location = startLoc;
	int stepNo = 0;
	
	do
	{
		if (h->info[location].key == targetKey || h->info[location].key == EMPTY)
		{
			break;
		}
		location = (location + stepNo*stepNo) % MAX_ITEMS;
		stepNo++;
	} while (location != startLoc );
	
	if ( h->info[location].key == targetKey )
	{
		return &h->info[location];
	}
	return NULL;
}

void insertItem(HashType *h, int key, char* name)
{
	int location = hash(key);
	int x = location;
	int stepNo = 0;
	
	while (h->info[location].key != EMPTY)
	{
		location = (x + stepNo * stepNo) % MAX_ITEMS;
		stepNo++;
	}
	
	h->info[location].key = key;
	strcpy(h->info[location].name, name);
}

void printTable(HashType* h)
{
	int index;
	printf("\nElements in the list are:\n");
	
	for (index = 0; index < MAX_ITEMS; index++)
	{
		if (h->info[index].key == EMPTY) continue;
		
		printf("Index: %d  Key: %d, %s\n", index,
			   h->info[index].key, h->info[index].name);
	}
	puts("");
}

int main(void)
{
	HashType *h;
	ItemType *pItem;
	FILE *fp;
	int key;
	char name[32];
	char choice;
	h = createHashTable();
	// Fill in the list with some items
	insertItem(h, 1000, "Hammer");
	insertItem(h, 2001, "Computer");
	insertItem(h, 1005, "Book");
	while (1)
	{
		puts("");
		printf("       Main Menu\n\n");
		printf("1)     Insert\n");
		printf("2)     Find\n");
		printf("3)     Print\n");
		printf("4)     Exit\n\n");
		printf("Enter your choice: ");
		scanf(" %c", &choice);
		switch (choice)
		{
			case '1':	
				printf("\nPlease enter a key and a name for insertion: ");
				scanf("%d%s", &key, name);
				insertItem(h, key, name);
				break;
			case '2':
				printf("\nPlease enter a key for searching: ");
				scanf("%d", &key);
				if ( pItem = retrieveItem(h, key) )
					printf("Key: %d, %s\n", pItem->key, pItem->name);
				else
					printf("Key: %d not found\n", pItem->key);
				break;
			case '3':
				printTable(h);
				break;
			case '4':
				puts("Bye!");
				exit (0);
		}
	}
	return 0;
}
