// linkedlist.h
typedef int bool;

typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node_t;

typedef struct linkedlist {
	node_t *head;
	node_t *tail;
} linkedlist_t;


struct linkedlist *new_linkedlist();
