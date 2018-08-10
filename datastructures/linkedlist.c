/*	linkedlist.c 
    Kyle Pollina
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/linkedlist.h"

// returns a pointer to newly created linked list
//	id - identifier for what type of value is stored in linked list (string/int)
linkedlist_t *new_linkedlist(int id)
{
	linkedlist_t *list;
	list = (linkedlist_t *)malloc(sizeof(linkedlist_t));
	list->id = id;
	
	node_t *head, *tail = NULL;
	head = (node_t *)malloc(sizeof(node_t));
	tail = (node_t *)malloc(sizeof(node_t));

	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;

	list->head = head;
	list->tail = tail;

	return list;
}

// adds the given value to the given linked list
//	list  - linked list to add value to
//	value - integer value to add to the linked list
int linkedlist_add_int(linkedlist_t *list, int value)
{
	if(list == NULL){
		printf("List does not exist\n");
		return -1;
	}

	if(list->id == ID_INT){
		node_t *new_node = NULL;
		new_node = (node_t *)malloc(sizeof(node_t));

		new_node->value = value;
		new_node->prev = list->tail->prev;
		new_node->next = list->tail;
		list->tail->prev->next = new_node;
		list->tail->prev = new_node;
	}
	else 
		return -1;

	return 0;
}

//TODO int linkedlist_add_str()

//TODO int linkedlist_del_int()

void linkedlist_print(linkedlist_t *list)
{
	if(list == NULL){
		printf("List does not exist\n");
		return;
	}
	
	node_t *temp = list->head->next;
	
	printf(" H <-> ");

	while(temp != list->tail) {
		printf("%d <-> ", temp->value);
		temp = temp->next;
	}

	printf("T\n");
}
