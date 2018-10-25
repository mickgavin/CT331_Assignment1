#include <stdio.h>
#include "genericLinkedList.h"

void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

//Print an integer element
void printInt(void* data) {
	printf("%d\n", *(int*)data);
}

//Print a float element
void printFloat(void* data) {
	printf("%f\n", *(float*)data);
}

//Print a string element
void printStr(void* data) {
	printf("%s\n", data);
}
//Print a char element

void printLong(void* data) {
	printf("%ld\n", *(long*)data);
}

void runTests(){
	genericlistElement* l = createEl("first", 20, printStr);
	printf("\n");

	//Test insert after
	int num = 123;
	insertAfter(l, &num, sizeof(int), &printInt);
	traverse(l);
	printf("\n");

	// Test delete after
	deleteAfter(l);
	traverse(l);
	printf("\n");

	//Test push
	char a = 'a';
	push(&l, &a, sizeof(char), &printChar);
	traverse(l);
	printf("\n");

	//Test length
	printf("%d\n\n", length(l));

	//Test pop
	pop(&l);
	traverse(l);
	printf("\n");

	//Test enqueue
	float i = 12.5;
	enqueue(&l, &i, sizeof(float), &printFloat);
	traverse(l);
	printf("\n");

	//Test dequeue
	dequeue(l);
	traverse(l);
	printf("\n");
  printf("\nTests complete.\n");


  //Test enqueue
  long a = 8;
  enqueue(&l, &a, sizeof(long), &printLong);
  traverse(l);
  printf("\n");

  //Test dequeue
  dequeue(l);
  traverse(l);
  printf("\n");
}
