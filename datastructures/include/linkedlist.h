// linkedlist.h
typedef int bool;
#define FALSE	0
#define TRUE	1

int create_linkedlist();

typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node_t;

typedef struct linkedlist {
	node_t *head;
	node_t *tail;
} linkedlist;
