#include <stdio.h>
#include<stdlib.h>
 
#define MAX 50 

int q[MAX];
int rear = - 1;
int front = - 1;


void insert()
{
  int item;
  if (rear == MAX - 1)
    printf("Queue Overflow \n");
  else
  {
     if (front == - 1)
        front = 0;
     printf("Insert: ");
     scanf("%d", &item);
     rear = rear + 1;
     q[rear] = item;
   }
} 

void delete()
{
  if (front == - 1 || front > rear)
  {
     printf("Queue is empty \n");
     return ;
  }
  else
  {
     printf("Deleted element is:%d\n", q[front]);
     front = front + 1;
  }
}

void display()
{
  int i;
  if (front == - 1)
    printf("Queue is empty \n");
  else
  {
     printf("Queue is : ");
     for (i = front; i <= rear; i++)
       printf("%d ", q[i]);
     printf("\n");
  }
}

int main()
{
  int op;
  while (1)
  { 
    printf("1.Insert \t");
    printf("2.Delete\t");
    printf("3.Display\t");
    printf("4.Quit \n");
    printf("Enter your choice : ");
    scanf("%d", &op);
     switch (op)
     {
         case 1:
            insert();
            break;
         case 2:
            delete();
            break;
         case 3:
            display();
            break;
         case 4:
           exit(1);
         default:
           printf("\nWrong choice \n");
     }
    }
return 0;
}