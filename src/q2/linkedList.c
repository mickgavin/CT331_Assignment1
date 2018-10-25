#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}


int length(listElement*list) {
	listElement* temp = list;
	int counter = 0;
	while (temp != NULL) {
		temp = temp->next;
		counter++;
	}
	return counter;

}


void push(listElement** list, char* data, size_t size) {
	if (*list == NULL) {
		*list = createEl(data, size);
	}
	else {
		listElement* newEl = createEl(data, size);
		newEl->next = *list;
		*list = newEl;
	}
}


listElement* pop(listElement** list) {
	listElement *head = *list;
	if (head) {
		*list = head->next;
	}
	return *head;
}


void enqueue(listElement** list, char* data, size_t size) {
	if (*list == NULL) {
		*list = createEl(data, size);
	}
	else {
		listElement* newEl = createEl(data, size);
		newEl->next = *list;
		*list = newEl;
	}
}


	listElement* dequeue(listElement* list) {
		listElement* temp = list;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		listElement* last = temp->next;
		temp->next = NULL;
		return last;
	}