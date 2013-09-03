#include "data.c"

void bubbleSort(int data[], int length)
{
	int i, j, flag;
	int temp;
	for (i = length; i > 1; i--)
	{
		flag = 0;
		for (j = length-1; j > length-i; j--)
		{
			if (data[j] < data[j-1])
			{
				flag = 1;
				temp = data[j];
				data[j] =  data[j-1];
				data[j-1] =temp;
			}
		}
		printData();
		if (flag == 0)
		{
			break;
		}
	}
}

int main(int argc, char const *argv[])
{
	printData();
	printf("\n");
	bubbleSort(data, length);
	// printData();
	return 0;
}