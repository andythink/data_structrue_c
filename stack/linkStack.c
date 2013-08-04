#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node * link;
}STNode, * STLink;

STLink top;

int isEmpty(STLink top)
{
	return (top == NULL);
}

void printLinkStack(STLink top)
{
	
	while(!isEmpty(top))
	{    
		printf("%d  [ %c ] %d\n", top, top->data, top->link);
		top = top->link;
	}

}

void init(STLink * top)
{
	*top = NULL;

}



int push(STLink * topc,char item)
{
	STLink p;
	if (!(p = (STLink)malloc(sizeof(STNode))))
	{
		return 0;
	}

	p->data = item;
	p->link = *topc;
	*topc = p;
	return 1;
}

int pop(STLink *topc,char * item)
{
	STLink top = *topc;
	if (isEmpty(top))
	{
		return 0;
	}

	*item = top->data;
	*topc = top->link;
	free(top);
	return 1;
}


int main(int argc, char const *argv[])
{
	init(&top);
	for (int i = 0; i < 10; ++i)
	{
		push(&top,'a' + i);
	}
	
	printLinkStack(top);

	char item;
	pop(&top,&item);
	printLinkStack(top);
	
	return 0;
}