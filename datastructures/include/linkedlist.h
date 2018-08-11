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

list_t	*new_list(int id);
int		list_add_int(list_t *list, int value);
int		list_add_str(list_t *list, char str[]);
int		list_remove_first(list_t *list);
int		list_remove_last(list_t *list);
void	print_list(list_t *list);
