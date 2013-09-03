#include "data.c"

void selectSort(int data[], int length)
{
	int i, j, d;
	int temp;
	for (i = 0; i < length-1; ++i)
	{
		d = i;
		for (j = i+1; j < length; ++j)
		{
			if(data[j] < data[d])
				d = j;
		}

		if(d != i)
		{
			temp = data[i];
			data[i] = data[d];
			data[d] = temp;
		}
	}
}


int main(int argc, char const *argv[])
{
	printData();

	printf("\n");
	selectSort(data,length);
	printData();
	return 0;
}