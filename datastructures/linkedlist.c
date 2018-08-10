// linkedlist.c
//  doubly linked list datastructure
//  Kyle Pollina

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
int linkedlist_add_int(linkedlist_t *list, int value)
{
	if(list == NULL)
		return ERR;
	

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
		return ERR;

	return 0;
}

// adds the given string to the given linked list
int linkedlist_add_str(linkedlist_t *list, char *str)
{
	if(list == NULL)
		return ERR;

	if(list->id == ID_STR){
		node_t *new_node = NULL;
		new_node = (node_t *)malloc(sizeof(node_t));

		new_node->str = str;
		new_node->prev = list->tail->prev;
		new_node->next = list->tail;
		list->tail->prev->next = new_node;
		list->tail->prev = new_node;
	}
	else 
		return ERR;

	return 0;

}

// removes the first element in the linked list (not including the head or tail)
int linkedlist_remove_first(linkedlist_t *list)
{
	if(list == NULL)
		return ERR;

	if(list->head->next == list->tail)
		return 0;

	node_t *temp = list->head->next;
	list->head->next = temp->next;
	temp->next->prev = list->head;
	free(temp);

	return 0;
}

// removes the last element in the linked list (not including the head or tail)
int linkedlist_remove_last(linkedlist_t *list)
{
	if(list == NULL)
		return ERR;
	
	if(list->tail->prev == list->head)
		return 0;
	
	node_t *temp = list->tail->prev;
	list->tail->prev = temp->prev;
	temp->prev->next = list->tail;
	free(temp);

	return 0;
}

int linkedlist_remove_int(linkedlist_t *list, int value)
{
	if(list == NULL || list->id != ID_INT)
		return ERR;

	node_t *temp = list->head->next;

	while(temp != list->tail){
		if(value == temp->value){
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);

			return 0;
		}
	}

	return ERR;
}

node_t *linkedlist_get(linkedlist_t *list, int index)
{
	node_t *temp = list->head->next;

	for(int i = 0; i < index; i++){
		if(temp == list->tail)
			return NULL;

		temp = temp->next;
	}

	return temp;
}

int linkedlist_length(linkedlist_t *list)
{
	node_t *temp = list->head;

	int i = 0;
	while(temp != list->tail){
		temp = temp->next;
		i++;
	}

	return i;
}

//TODO int linkedlist_remove_str(linkedlist_t *list, char *str)
//TODO int linkedlist_sort(linkedlist_t *list);

void linkedlist_print(linkedlist_t *list)
{
	if(list == NULL)
		return;
	
	node_t *temp = list->head->next;
	
	printf(" H <-> ");

	while(temp != list->tail) {
		printf("%d <-> ", temp->value);
		temp = temp->next;
	}

	printf("T\n");
}
