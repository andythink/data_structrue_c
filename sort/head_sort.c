#include "data.c"

void adjust(int data[], int i, int length)
{
	int j;
	int temp;
	temp = data[i];
	j = 2*i + 1;
	while(j <= length)
	{
		if (j < length && data[j] < data[j+1])
		{
			j++;
		}
		if(temp > data[j])
		{
			break;
		}
		data[(j-1)/2] = data[j];
		j = 2*j + 1;
	}
	data[(j-1)/2] = temp;
}

void headSort(int data[], int length)
{
	int i;
	int temp;
	for (i=(length/2)-1; i >=0 ; i--)
	{
		adjust(data, i, length);
	}

	for (i=length-2; i >= 0 ; i--)
	{
		temp = data[i+1];
		data[i+1] = data[0];
		data[0] = temp;
		adjust(data, 0, i);
	}
}

int main(int argc, char const *argv[])
{
	printData();
	printf("\n");
	headSort(data, length);
	printData();
	return 0;
}