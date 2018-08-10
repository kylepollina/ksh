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
} linkedlist_t;

linkedlist_t *new_linkedlist(int id);
int linkedlist_add_int(linkedlist_t *list, int value);
int linkedlist_add_str(linkedlist_t *list, char *str);
int linkedlist_remove_first(linkedlist_t *list);
int linkedlist_remove_last(linkedlist_t *list);
void linkedlist_print(linkedlist_t *list);
