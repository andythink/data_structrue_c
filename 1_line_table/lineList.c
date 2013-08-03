#define MaxSize 1000
// -----------------------------------
// ElemType A[MaxSize];
// int n;
//------------------------------------
/*

1.



*/
int  A[MaxSize];
int n = 0;

void printLineTable()
{

	for (int i = 0; i < n; ++i)
	{		
		printf("%d--> %d\n",i,A[i] );
	}
}


void init()
{
	for (int i = 0; i < 10; ++i)
	{
		A[i] = i + 1;
	}
	n = 10;

	
}
/*
	在长度为n的线性表A的第i个位置插入一个新的数据元素item	
*/

int insertListLine(int A[], int * nc, int ic, int item)
{
	int n = *nc;
	int num = (n - ic +  1);
	if ((n + 1) >= MaxSize)
	{
		return -1;
	}

	for (int i = 1; i <= num; ++i)
	{
		A[n-i+1] = A[n-i];
	}

	A[ic-1] = item;
	*nc = n + 1;

	return 1;

}

// 删除长度为n的线性表A的第i个数据元素
int deleteListLine(int A[], int * nc, int ic)
{
	int n = *nc;
	int num = n - ic;
	if (ic < 1 || ic > n)
	{
		return -1;
	}
	int value = A[ic - 1];
	for (int i = 1; i <= num; ++i)
	{
		A[ic-1 + i -1] = A[ic + i -1];
	}

	*nc = n -1;

	return  value;
}

int localItem(int A[],int n,int item)
{
	for (int i = 0; i < n; ++i)
	{
		if (A[i] == item)
		{
			return (i + 1);
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{

	init();
	printLineTable();
	// insertListLine(A,&n,6,1000);
	// deleteListLine(A,&n,6);
	// int local = localItem(A,n,6);	

	return 0;
}
