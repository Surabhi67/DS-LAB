#include<stdio.h>
#include<stdlib.h>
#define size 10
int top=-1, stack[size]={0};

int stfull()
{
 if(top>=size-1)
  return 1;
 else
  return 0;
}

void Push(int n)
{
  top++;
  stack[top]=n;
}

int stempty()
{
 if(top==-1)
  return 1;
 else
  return 0;
}

void pop()
{
 printf("%d\n",stack[top]);
 top--;
}

void Display()
{
 for(int i=0; i<=top; i++)
  {
  printf("%d\t",stack[i]);
  }
  printf("\n");
}

void main()
{
  int op, n, p=1;
  printf("Choose what you want to do\n");
 do
 {
  printf("1.Push\t 2.Pop\t 3.Display\t 4.Exit\n");
  scanf("%d",&op);
  switch(op)
  {
   case 1:
     printf("Enter the number to be pushed : ");
     scanf("%d",&n);
     if(stfull())
       printf("Stack is full");
     else
       Push(n);
     break;
  case 2:
    if(stempty())
     printf("Stack is empty");
    else
     pop();
    break;
  case 3:
    if(stempty())
     printf("Stack is empty");
    else
     Display();
    break;
  case 4:
   exit(0);
  }
 }while(1);
}