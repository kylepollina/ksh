// linkedlist.h
//	doubly linked list capable of storing strings or integers
//  Kyle Pollina

#include "defaults.h"
#define ID_INT	0
#define ID_STR	1

typedef struct node {
	int value;
	char *str;
	struct node *next;
	struct node *prev;
} node_t;

typedef struct linkedlist {
	int id;
	node_t *head;
	node_t *tail;
} list_t;

list_t	*newList(int id);
int		listAddInt(list_t *list, int value);
int		listAddStr(list_t *list, char str[]);
int		listRemoveFirst(list_t *list);
int		listRemoveLast(list_t *list);
node_t  *listGet(list_t *list, int index);
void	printList(list_t *list);
