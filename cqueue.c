#include<stdio.h>
#include<stdlib.h>

int cq[50],front=-1,rear=-1,n;
void display()
{
    int i=0;
    if(front==-1)
    {
        printf("the circular Queue is empty\n");
    }
    else
    {
          for(i=front;i!=rear;i=(i+1)%n)
           {
              printf("%d ",cq[i]);
           } 
            printf("%d ",cq[i]);
     }
    printf("\n");
}
void enqueue()
{
    int next,item,i;
    printf("Enter the element : ");
    scanf("%d",&item);
    
    if(front==-1)
    {
        front=0;
        rear=0;
        cq[rear]=item;
    }
    else
    {
        next=(rear+1)% n;
        if(next!=front)
        {
            rear=next;
            cq[rear]=item;
        }
        else
        {
            printf("Circular Queue is full\n");
          }
    }
}
void dequeue()
{
    int item,i;
    if(front==-1)
    {
        printf("The circular queue is empty");
    }
    else
    {
        item=cq[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%n;
        }
    }
}

void main()
{
    int op;
    printf("Enter the size of the queue : ");
    scanf("%d",&n);
    printf("What do you want to do\n");
    while(1)
    {
    printf("1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
    scanf("%d",&op);
    switch(op)
      {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        default:
        printf("There is no such operation");
        break;
      }
    }
}