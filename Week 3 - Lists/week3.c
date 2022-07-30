#include <stdio.h>
#include <stdlib.h> //Malloc is in the standard library
#include <ctype.h>
#include <assert.h>

typedef struct list {
	int data; 
	struct list *next; 
} list; 

int is_empty(const list *l)
{
  return( l==NULL );
}

void print_list(list *h, char *title)
{

  printf("%s\n", title);

  while( h != NULL ) //Test on "sentinel"
	{
    printf("%d : ", h->data);
    h = h->next;
  }

	printf("NULL");

}

list* create_list(int d)
{

	list* head = malloc(sizeof(head)); //sizeof returns unsigned long, malloc returns pointer to void
	//dynamic memory i.e. heap based memory.
	head->data = d;
	head->next = NULL;
	return head;

}

list* add_to_front(int d, list* h)
{

	list* head = create_list(d);
	head->next = h; 
	return head;
		
}

list* array_to_list(int d[], int size)
{
	list* head = create_list(d[0]);
	int i; 
	for( i = 1; i < size; i++ )
	{
		head = add_to_front(d[i], head); 
	}
	return head; 
}

// Recursion to count
int count(list* h)
{
	if(h == NULL)
		return 0; 
	else
		return( 1 + count(h->next) );
}

// Concatenation recursion as well
void concat(list* h1, list* h2)
{
	assert(h1 != NULL);
//	if(h1 -> NULL) // If h1 is empty?
//		h1->next = h2;
	if( h1-> next == NULL )
		h1->next = h2;
	else
		concat(h1->next, h2);
}

// P1 = first, P2 = last, p3 = insert
void insert(list *first, list* last, list* insert)
{
	assert(first->next == last);
	first->next = insert;
	insert->next = last; 
}

void testFunc2(const int* data)
{
	printf("pointed data");
}

void testFunc1(int data)
{
	printf("data");
	testFunc2((const int*)data);
}


//////////////////////////////////////////////////////////////// Main
int main(){

  list* head = NULL;
	int data[6] = {2,3,5,7,8,9};
	head = array_to_list(data, 6); 

	int this; 	
	testFunc1(this);

  print_list(head, "Array to Int");
	printf("\n\n");

	return 0;

}


