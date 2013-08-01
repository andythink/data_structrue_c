int main(int argc, char const *argv[])
{
	int n = 10;

	a(&n);
	return 0;
}

void a(int * n)
{
	printf("%d \n",* n);
}
