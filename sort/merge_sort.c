
int datax[] = {55, 40, 74, 90, 98, 150, 12, 66, 80, 120};
int dataz[10];
int n = 10;

void printData(int data[])
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%d   ", data[i]);
	}
	printf("\n");
}

void merge(int datax[], int dataz[], int s, int u, int v)
{
	int i, j, q;
	i = s;
	j = u + 1;
	q = s;
	while(i <= u && j<= v)
	{
		if (datax[i] < datax[j])
		{
			dataz[q++] = datax[i++];
		}
		else
		{
			dataz[q++] = datax[j++];
		}
	}
	while(i <= u)
	{
		dataz[q++] = datax[i++];
	}
	while(j <= v)
	{
		dataz[q++] = datax[j++];
	}
}

void mpass(int datax[], int dataz[], int n, int t)
{
	int i, j;
	i = 0;

	while(n-i+1 >= 2*t)
	{
		merge(datax, dataz, i, i+t-1, i+2*t-1);
		i = i + 2*t;
	}

	if (n-i+1 > t)
	{
		merge(datax, dataz, i, i+t-1, n);
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			dataz[j] = datax[j];
		}
	}

}

void mergeSort(int datax[], int dataz[], int n)
{
	int t = 1;
	while(t < n-1)
	{		
		mpass(datax, dataz, n-1, t);
		// t *= 2;
		t = t*2;
		if (t < n)
		{
			mpass(dataz, datax, n-1, t);
		}

		// t *= 2;
		t = t*2;
	}
}

int main(int argc, char const *argv[])
{
	printData(datax);
	printData(dataz);
	printf("-------------------------------------------------\n");
	// merge(datax, dataz, 0, 5, 9);

	mergeSort(datax, dataz, n);

	printData(datax);
	printData(dataz);

	return 0;
}