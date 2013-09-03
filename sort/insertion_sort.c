#include "data.c"


void insertSort(int data[], int length)
{
	int i,j;
	int temp;
	for (i = 1; i < length; ++i)
	{
		temp = data[i];
		j = i - 1;
		while(j >= 0 && temp < data[j])
		{
			data[j+1] = data[j--];
		}
		data[j+1] = temp;
	}
}

void binInsertSort(int data[], int length)
{
	int i, j, low, high, mid;
	int temp;
	for (i = 1; i < length; ++i)
	{
		temp = data[i];
		low = 0;
		high = i - 1;
		while(low <= high)
		{
			mid = (low + high)/2;
			if (temp < data[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		for (j = i-1; j >= low; --j)
		{
			data[j+1] = data[j];
		}
		data[low] = temp;
	}
}


int main(int argc, char const *argv[])
{
	printf("%s\n", "init data");
	printData();
 	
 	// insertionSort(data,length);
 	binInsertSort(data,length);
 	printData();

	return 0;
}