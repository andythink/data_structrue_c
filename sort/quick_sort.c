#include "data.c"



void quickSort(int data[], int s, int t)
{
	int temp;
	int i, j;
	if (s < t)
	{
		i = s;
		j = t + 1;

		while(1)
		{
			do i++;
			while(!(data[i]>=data[s] || i == t));
			do j--;
			while(!(data[j]<=data[s] || j == s));
			if (i < j)
			{
				temp = data[i];
				data[i] = data[j];
				data[j] =temp;
			}
			else
			{
				break;
			}
		}
		temp = data[s];
		data[s] = data[j];
		data[j] = temp;
		quickSort(data, s, j-1);
		quickSort(data, j+1, t);
	}
}

int main(int argc, char const *argv[])
{
	printData();
	printf("\n");
	quickSort(data, 0, length-1);
	printData();
	return 0;
}