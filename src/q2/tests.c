#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests() {
	printf("Tests running...\n");
	listElement* l = createEl("Test String (1).", 30);
	//printf("%s\n%p\n", l->data, l->next);
	//Test create and traverse
	traverse(l);
	printf("\n");

	//Test insert after
	listElement* l2 = insertAfter(l, "another string (2)", 30);
	insertAfter(l2, "a final string (3)", 30);
	traverse(l);
	printf("\n");

	// Test delete after
	deleteAfter(l);
	traverse(l);
	printf("\n");
}


  void testStack() {
	  listElement*m = NULL;

	  push(&m, "how ", 20);
	  push(&m, "are", 20);
	  push(&m, "you", 20);
	  traverse(m);


	  printf("Length: %d", length(m));
	  printf("TESTING POP\n");
	  *pop(&m);
	  traverse(m);
	  printf("Length: %d", length(m));
  }

  void testQueue{
  listElement* g = NULL;
  enqueue(&g, "one", 20);
  enqueue(&g, "two", 20);
  enqueue(&g, "three", 20);
  traverse(g);
  printf("Length: %d", length(g));
  printf("\nTESTING DEQUEUE\n");


  dequeue(g);
  traverse(g);
  printf("Length: %d", length(g));


  printf("\nTests complete.\n");
  }

