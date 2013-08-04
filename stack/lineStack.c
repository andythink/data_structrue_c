#include <stdio.h>

#define MAXSIZE  100
int STACK[MAXSIZE];
int top;


void printStack(int STACK[],int top)
{
	while(top >= 0)
	{
		printf("%d : %d\n",top,STACK[top]);
		top--;
	}
}





void init(int * top)
{
	*top = -1;
}

int isEmpty(int top)
{
	return (top == -1);
}

int isFull(int top)
{
	return (top == MAXSIZE - 1);
}

int push(int STACK[],  int * topc,int item)
{
	int top = *topc;
	if (isFull(top))
	{
		return 0;
	}


	STACK[++top] = item;
	*topc = top;
	return 1;

}

int pop(int STACK[],int * topc,int * item)
{
	int top = *topc;
	if (isEmpty(top))
	{
		return 0;
	}

	*item = STACK[top];
	*topc = top - 1;
	return 1;
}

int main(int argc, char const *argv[])
{
	init(&top);
	for (int i = 1; i <= 10; ++i)
	{
		push(STACK,&top,i);
	}
	
	printStack(STACK,top);

	int item;
	pop(STACK,&top,&item);

	printStack(STACK,top);
	return 0;
}