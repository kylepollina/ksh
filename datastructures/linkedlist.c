// linkedlist.c
//  doubly linked list datastructure
//  Kyle Pollina

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/linkedlist.h"

// returns a pointer to newly created linked list
list_t *newList(int id)
{
	list_t *list;
	list = (list_t *)malloc(sizeof(list_t));
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
int listAddInt(list_t *list, int value)
{
	if(list == NULL)
		return ERR;
	if(list->id != ID_INT)
		return ERR;

	node_t *new_node = NULL;
	new_node = (node_t *)malloc(sizeof(node_t));

	new_node->value = value;
	new_node->prev = list->tail->prev;
	new_node->next = list->tail;
	list->tail->prev->next = new_node;
	list->tail->prev = new_node;

	return 0;
}

// adds the given string to the given linked list
int listAddStr(list_t *list, char str[])
{
	if(list == NULL)
		return ERR;
	if(list->id != ID_STR)
		return ERR;

	node_t *new_node = NULL;
	new_node = (node_t *)malloc(sizeof(node_t));

	char *new_str = (char *)malloc(sizeof(char *) * strlen(str));
	memcpy(new_str, str, strlen(str) + 1);

	new_node->str = new_str;
	new_node->prev = list->tail->prev;
	new_node->next = list->tail;
	list->tail->prev->next = new_node;
	list->tail->prev = new_node;

	return 0;

}

// removes the first element in the linked list (not including the head or tail)
int listRemoveFirst(list_t *list)
{
	if(list == NULL)
		return ERR;

	if(list->head->next == list->tail)
		return 0;

	node_t *temp = list->head->next;
	list->head->next = temp->next;
	temp->next->prev = list->head;
	free(temp->str);
	free(temp);

	return 0;
}

// removes the last element in the linked list (not including the head or tail)
int listRemoveLast(list_t *list)
{
	if(list == NULL)
		return ERR;
	
	if(list->tail->prev == list->head)
		return 0;
	
	node_t *temp = list->tail->prev;
	list->tail->prev = temp->prev;
	temp->prev->next = list->tail;
	free(temp->str);
	free(temp);

	return 0;
}

//TODO document
int listRemoveInt(list_t *list, int value)
{
	if(list == NULL)
		return ERR;
	if(list->id != ID_INT)
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

//TODO int list_remove_str(list_t *list, char *str)

node_t *listGet(list_t *list, int index)
{
	node_t *temp = list->head->next;

	for(int i = 0; i < index; i++){
		if(temp == list->tail)
			return NULL;

		temp = temp->next;
	}

	return temp;
}

int list_length(list_t *list)
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

void printList(list_t *list)
{
	if(list == NULL)
		return;
	
	node_t *temp = list->head->next;
	
	printf(" H <-> ");

	while(temp != list->tail) {
		if(list->id == ID_INT)
			printf("%d <-> ", temp->value);
		else if(list->id == ID_STR)
			printf("%s <-> ", temp->str);

		temp = temp->next;
	}

	printf("T\n");
}
