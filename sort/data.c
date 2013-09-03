// #include <stdio.h>
int length = 8;
int data[] = {49,38,65,97,76,13,27,49};

void printData()
{
	
	printf("%c", ' ');
	for (int i = 0; i < length; ++i)
	{
		if (i == (length - 1))
		{
			printf("%d ", i);
		}
		else
		{
			printf("%d  , ", i);
		}
	}
	
	printf("\n%c", '[');

	for (int i = 0; i < length; ++i)
	{
		if (i == (length - 1))
		{
			printf("%d", data[i]);
		}
		else
		{
			printf("%d , ", data[i]);
		}
	}

	printf("%c\n", ']');

}
