#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*temp = NULL, *prev=NULL, *trav=NULL, *start=NULL, *end=NULL;

void InsertatStart()
{
 temp = (struct node*)malloc(sizeof(struct node));
 printf("Enter the number you want to add to the list.\n");
 scanf("%d", &temp->data);
 if(start == NULL)
 {
   start = temp;
   end = temp;
   temp->next = NULL;
 }
 else
 {
   temp->next = start;
   start = temp;
 }
}

void InsertatEnd()
{
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter the number you want to add to the list.\n");
 scanf("%d", &temp->data);
 if(start == NULL)
 {
   start = temp;
   end = temp;
   temp->next = NULL;
 }
 else
 {
   end->next = temp;
   temp->next = NULL;
   end = temp;
 }
}

void InsertatPos()
{
  int n,i;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter the position.\n");
  scanf("%d",&n);
  if(n == 0)
    InsertatStart();
  else 
  {
    prev = NULL;
    trav = start;
    for(i = 0; i < n - 1; i++)
    {
      prev = trav;
      trav = trav->next;
    }
    printf("Enter the number you want to add to the list.\n");
    scanf("%d", &temp->data);
    prev->next = temp;
    temp->next = trav;
  }
}

void DelatStart()
{
  if(start == NULL)
    printf("List is empty\n");
  else
  {
    temp= start->next;
    start = temp;
  } 
}


void DelatEnd() 
{
  if(start == NULL)
    printf("List is empty\n");
  else
  {
    temp = start;
    while(temp != end)
    {
      prev = temp;
      temp = temp->next;
    }
    prev->next = NULL;
    end = prev;
  } 
}

void DelatPos()
{
  int n, i;
  printf("Enter the position you want to delete from the list.\n");
  scanf("%d", &n);
  if(n == 0)
    DelatStart();
  else 
  {
    prev = NULL;
    trav = start;
    for(i = 0; i < n - 1; i++)
    {
      prev = trav;
      trav = trav->next;
    }
    prev->next = trav->next;
  }
}

void display()
{
  if(start == NULL)
    printf("The list is empty.\n");
  temp = start;
  do
  {
	printf("%d\t", temp->data);
	temp = temp->next;
  }while(temp != NULL);
  printf("\n");
}

int main()
{
	int op;
  printf("Enter your choice\n");
	do
	{
		printf("1.Insert at the start\t2.Insert at the end\t3.Insert at specific position\t4.Delete at start\t5.Delete at end   \t6.Delete at specific position\t7.Display\t8.End\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				InsertatStart();
				break;
			case 2:
				InsertatEnd();
				break;
			case 3:
				InsertatPos();
				break;
			case 4:
				DelatStart();
				break;
			case 5:
				DelatEnd();
				break;
			case 6:
				DelatPos();
				break;	
			case 7:
				display();
				break;
			case 8:
				return 1;	
			default:
				return 1;
				break;	
		}
	}while(1);
}