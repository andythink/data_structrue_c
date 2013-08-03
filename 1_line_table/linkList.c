#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char  data;
	struct node * link;
}LNode, * LinkList;

void printLinkList(LinkList listHead)
{
	LinkList p = listHead;
	for(int i = 1;p != NULL;i++)
	{
		
		
		// printf("ListHeadLink: %d", p);
		if (p->link != NULL)
		{
			printf("[%d]%c:%d--->", p, p->data ,p->link);
		}
		else
			printf("[%d]%c:NULL", p,p->data);

		p = p->link;
	}
}

// 构造初始线性链表
LinkList create(int n)
{
	LinkList p,r,listHead = NULL;
	char data = 'a' - 1;
	int i;
	 for (i = 1; i <= n; ++i)
	 {
	 	data = data + 1;
	 	p = (LinkList)malloc(sizeof(LNode));
	 	p->data = data;
	 	p->link = NULL;
	 	if (listHead == NULL)
	 	{
	 		listHead = p;
	 	}
	 	else
	 		r->link = p;
	 	r = p;
	 }

	 return(listHead);
}

int length(LinkList listHead)
{
	LinkList p = listHead;
	int length = 0;
	while (p != NULL)
	{
		length++;
		p = p->link;
	}

	return length;
}



int main(int argc, char const *argv[])
{
	LinkList listHead =  create(15);
	printLinkList(listHead);
	printf("\n");
	int lengthLinklist  = length(listHead);
	printf("%d\n", lengthLinklist);
	return 0;
}