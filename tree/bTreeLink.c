#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

char DATA[] = {'A','(','B','(','D',',','E','(','G',')',')',',','C','(','F','(',',','H',')',')',')','@'};

typedef struct node
{
	char data;
	struct  node * lchild, * rchild;
}BTNode, * BTLink;


BTLink create()
{
	BTLink T = NULL,p,STACK[MAXSIZE];
	char ch;
	int flag,top = -1;
	int i = 0;
	while(1)
	{	
		
		// scanf("%c", &ch);
		ch = DATA[i++];
		printf("%c\n", ch);
		switch(ch)
		{

			case '@' : 
				return(T);
			case '(' : 
				STACK[++top] = p;
				flag = 1;
				break;
			case ')' :
				top--;
				break;
			case ',' :
				flag = 2;
				break;
			default :
				p = (BTLink)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = NULL;
				p->rchild = NULL;
				if(T == NULL)
					T = p;
				else if(flag == 1)
					STACK[top]->lchild = p;
				else
					STACK[top]->rchild = p;  
		}
	}
}

int countLeaf(BTLink T)
{
	if(T == NULL)
		return 0;
	if(T->lchild == NULL && T->rchild == NULL)
		return 1;
	return(countLeaf(T->lchild) + countLeaf(T->rchild));
}

void visitFront(BTLink T)
{
	if(T == NULL)
		return;
	printf("%c  ", T->data);
	visitFront(T->lchild);
	visitFront(T->rchild);
}

void visitMiddle(BTLink T)
{
	if(T == NULL)
		return;
	visitMiddle(T->lchild);
	printf("%c  ", T->data);
	visitMiddle(T->rchild);
}

void visitBehind(BTLink T)
{
	if(T != NULL)
	{
		visitBehind(T->lchild);
		visitBehind(T->rchild);
		printf("%c  ", T->data);
	}
}



void visitLayer(BTLink T)
{

	if (T == NULL)
	{
		return;
	}
	BTLink QUEUE[100],p;
	int front,rear;
	QUEUE[0] =  T;
	front = -1;
	rear = 0;
	while(front < rear)
	{
		p = QUEUE[++front];
		printf("%c  ", p->data);
		if (p->lchild != NULL)
		{
			QUEUE[++rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			QUEUE[++rear] =  p->rchild;
		}
	}

}


int main(int argc, char const *argv[])
{
	for (int i = 0; DATA[i] != '@'; ++i)
	{
		printf("%c", DATA[i]);
	}
	printf("@\n------------------------------------------------------------------------------\n");
	BTLink T = create();
	int num = countLeaf(T);
	printf("%c\n", T->data);
	printf("%d\n", num);
	printf("visitFront:");
	visitFront(T);
	printf("\n");
	printf("visitMiddle:");
	visitMiddle(T);

	printf("\n");
	printf("visitBehind:");
	visitBehind(T);

	printf("\n");
	printf("visitLayer:");
	visitLayer(T);
	return 0;
}