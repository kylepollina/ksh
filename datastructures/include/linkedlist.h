// linkedlist.h
//	Doubly linked list capable of storing strings or integers

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
void linkedlist_print(linkedlist_t *list);
