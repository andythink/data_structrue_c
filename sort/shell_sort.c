#include "data.c"

void shellSort(int data[], int length)
{
	int i, j, flag, d = length, num;
	int temp;
	while(d>1)
	{
		d = d/2;
		num = 0;
		do
		{
			flag = 0;
			// 每次循环，在每个子序列上进行一次冒泡排序，num用于将每个子序列已经排好的去掉，
			// 每次循环每个子序列排好的个数为d的值
			/*
				D = 4 
				0  ,  1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , <10> , <11> , <12>  , <13> 
				[49 , 38 , 65 , 97 , 76 , 13 , 27 , 49 ,  1 ,  2 ,  3 ,  4 ,  5 ,   100]


				D=3
				 0  ,  1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 10  , <11> , <12>  , <13> 
				[49 , 38 , 65 , 97 , 76 , 13 , 27 , 49 ,  1 ,  2 ,  3 ,  4 ,  5 ,   100]

			*/
			for (i = 0; i < length - num*d - d; ++i)
			{
				j = i + d;
				if(data[i] > data[j])
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
					flag = 1;
				}
			}
			num++;

		}while(flag != 0);
	}
}

int main(int argc, char const *argv[])
{
	printData();
	printf("\n");
	shellSort(data, length);
	printData();
	return 0;
}