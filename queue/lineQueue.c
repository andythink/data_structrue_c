#include <stdio.h>

#define MAXSIZE 100

int QUEUE[MAXSIZE];
int front, rear;

void init(int * front, int * rear)
{
	*front = -1;
	*rear = -1;
}

int isEmpty(int front, int rear)
{
	return (front == rear);
}

void printQueue(int QUEUE[], int front, int rear)
{
	while(!isEmpty(front, rear))
	{
		front = (front  + 1) % MAXSIZE;
		printf("%d\n", QUEUE[front]);
		
	}
}

int isFull(int front, int rear)
{
	return ((rear + 1) % MAXSIZE == front);
}

int addQueue(int QUEUE[], int front, int * rear_c, int item)
{
	int rear = *rear_c;
	if(isFull(front,rear))
		return 0;
	rear = (rear + 1) % MAXSIZE;
	QUEUE[rear] = item;
	*rear_c = rear;
	return 1;
}

int deleteQueue(int QUEUE[], int * front_c, int rear,int * item)
{
	int front = *front_c;
	if(isEmpty(front,rear))
		return 0;

	front = (front + 1) % MAXSIZE;
	*item = QUEUE[front];
	*front_c = front;
	return 1;
}

int main(int argc, char const *argv[])
{
	init(&front, &rear);
	for (int i = 1; i <= 10; ++i)
	{
		addQueue(QUEUE, front, &rear, i);	
	}
	printQueue(QUEUE,front,rear);
	int item;
	deleteQueue(QUEUE,&front,rear,&item);
	printf("%d %d\n", front, rear);
	printQueue(QUEUE,front,rear);
	return 0;
}