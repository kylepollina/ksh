/*	linkedlist.c 
    Kyle Pollina
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/linkedlist.h"

linkedlist_t *new_linkedlist()
{
	linkedlist_t *list;
	list = (linkedlist_t *)malloc(sizeof(linkedlist_t));
	
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

/* int add(linkedlist list, int value) */
/* { */
/* 	if(linkedlist_exists == FALSE) */
/* 		return -1; */
/* 	else { */
/* 		node_t *new_node = NULL; */
/* 		new_node = (node_t *)malloc(sizeof(node_t)); */

/* 		new_node->value = value; */
/* 		new_node->prev = list.tail->prev; */
/* 		new_node->next = list.tail; */
/* 		list.tail->prev->next = new_node; */
/* 		list.tail->prev = new_node; */
/* 	} */	

/* 	return 0; */	
/* } */
