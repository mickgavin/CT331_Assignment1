#include <stdio.h>





int main(int arg, char* argc[]) {
int* p;
long b;
double* d;
char** c;
int a;
	printf("Hello assignment1.\n");
	printf("%ld\n", sizeof(p));
	printf("%ld\n", sizeof(b));
	printf("%ld\n", sizeof(d));
	printf("%ld\n", sizeof(c));
	printf("%ld", sizeof(a));
	return 0;

}