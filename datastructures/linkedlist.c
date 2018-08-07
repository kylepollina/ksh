/*	linkedlist.c 
    Kyle Pollina
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/linkedlist.h"

bool linkedlist_exists = FALSE;
struct linkedlist list;

int create_linkedlist()
{
	// if list has already been created
	if(linkedlist_exists == TRUE)
		return -1;
	else {
		linkedlist_exists = TRUE;
		
		node_t *head, *tail = NULL;
		head = (node_t *)malloc(sizeof(node_t));
		tail = (node_t *)malloc(sizeof(node_t));

		head->next = tail;
		head->prev = NULL;
		tail->next = NULL;
		tail->prev = head;

		list.head = head;
		list.tail = tail;
	}

	return 0;
}

int add(int value)
{
	if(linkedlist_exists == FALSE)
		return -1;

	return 0;	
}
