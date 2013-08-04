#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node * link;
}QNode, * QLink;

QLink front,rear;

void init()
{
	front = rear = NULL;
}

int isEmpty(QLink front)
{
	return (front == NULL);
}

void printQueue(QLink front)
{
	while (!isEmpty(front))
	{
		printf("%c\n", front->data);
		front = front->link;
	}
}

int addQueue(char item)
{
	int len = sizeof(QNode);
	QLink p;
	if (!(p = (QLink)malloc(len)))
	{
		return 0;
	}

	p->data = item;
	p->link = NULL;
	if(isEmpty(front))
	{
		front = p;
	}
	else
	{
		rear->link = p;		
	}

	rear = p;
	return 1;
}

int deleteQueue(char * item)
{	
	QLink p;
	if(isEmpty(front))
		return 0;
	*item = front->data;
	p = front;
	front = front->link;
	free(p);
	return 1;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < 10; ++i)
	{
			addQueue('a' + i);
	}
	printQueue(front);
	char item;
	deleteQueue(& item);
	printQueue(front);
	return 0;
}