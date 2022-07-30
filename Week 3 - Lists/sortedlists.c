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

list* sort_lists(list *h)
{
	while( h->next != NULL )
	{
		if( h->data > h->next->data ){
			h->next = h->next->next;
			h->next->next = h->next;
			h->next->data = h->data;
		}
		h->next = h->next->next;
	}
}



int main()
{

}

