#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genericLinkedList.h"
//Creates a new linked list element with given content of size
//Returns a pointer to the element

genericlistElement* createEl(void* data, size_t size, printFn print) {
	genericlistElement* e = malloc(sizeof(genericlistElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	memmove(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->print = print;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(genericlistElement* head) {
	genericlistElement* current = head;
	while (current != NULL) {
		current->print(current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericlistElement* insertAfter(genericlistElement* el, void* data,
	size_t size, printFn print) {
	genericlistElement* newEl = createEl(data, size, print);
	genericlistElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}

//Delete the element after the given el
void deleteAfter(genericlistElement* after) {
	genericlistElement* delete = after->next;
	genericlistElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

// Returns the number of elements in a linked list.
int length(genericlistElement* list) {
	genericlistElement* temp = list;
	int counter = 0;
	while (temp != NULL) {
		temp = temp->next;
		counter++;
	}
	return counter;
}

// Push a new element onto the head of a list.
void push(genericlistElement** list, void* data, size_t size, printFn print) {
	if (*list == NULL) {
		*list = createEl(data, size, print);
	}
	else {
		genericlistElement* newEl = createEl(data, size, print);
		newEl->next = *list;
		*list = newEl;
	} 
}

// Pop an element from the head of a list.
genericlistElement* pop(genericlistElement** list) {
	genericlistElement *head = *list;
	if (head) {


		*list = head->next;
	}
	return *head;
}

//Enqueue a new element onto the head of the list.
void enqueue(genericlistElement** list, void* data,
	size_t size, printFn print) {
	if (*list == NULL) {
		*list = createEl(data, size, print);
	}
	else {
		genericlistElement* newEl = createEl(data, size, print);
		newEl->next = *list;
		*list = newEl;
	}
}

//Dequeue an element from the tail of the list.
genericlistElement* dequeue(genericlistElement* list) {
	genericlistElement* temp = list;
	//find the second last elemnt
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	genericlistElement* last = temp->next;
	temp->next = NULL;
	return last;
}

