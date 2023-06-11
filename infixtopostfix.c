#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char item)
{
	if(top >= 100-1)
	{
		printf("\nStack Overflow.");
	}
	else
		stack[++top] = item;
}
char pop()
{
	char item ;

	if(top < 0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top--];
		return(item);
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
		return 1;
	else
		return 0;
}
int precedence(char symbol)
{
	if(symbol == '^') 
		return(3);
	else if(symbol == '*' || symbol == '/')
		return(2);
	else if(symbol == '+' || symbol == '-')        
		return(1);
	else
		return(0);
}

void InfixToPostfix(char in[], char post[])
{ 
	int i = 0, j = 0;
	char item;
	char x;

	push('(');                            
	strcat(in,")");                 
	item = in[i];      

	while(item != '\0')      
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			post[j] = item;             
			j++;
		}
		else if(is_operator(item) == 1)      
		{
			x = pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				post[j++] = x;    
				x = pop();                     
			}
			push(x);
			push(item);                
		}
		else if(item == ')')         
		{
			x = pop();                   
			while(x != '(')              
			{
				post[j++] = x;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}
		i++;
		item = in[i];
	} 
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");       
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");       
		getchar();
		exit(1);
	}
	post[j] = '\0'; 
}

void main()
{
	char in[50], post[50];     
	printf("Assume the infix expression contains single letter variables and single digit constants only.\n");
	printf("Enter Infix expression\n");
	scanf("%s",in);
	InfixToPostfix(in,post);               
	printf("Postfix Expression\n");
	puts(post);   
}