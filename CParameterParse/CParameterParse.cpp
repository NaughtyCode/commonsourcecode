#include <stdio.h>

void PrintIntMStringN(int m,int n, ...){
	int i; char **p = (char **)&n;
	for (i = 0; i<n; i++){
		printf("%s\n", p[i+1]);
	}
	if (p[5]){
		printf("AAAAkkkkkkkkkkkK KKKKKKKKKKKKKKKKKKKKKKKKK\n");
	}
}

void PrintStringN(const char *s, ...)
{


	int ccc = ((sizeof(char*)+sizeof(int)-1) & ~(sizeof(int)-1)) - ((sizeof(char*)+sizeof(int)-1) & ~(sizeof(int)-1));

	printf("%d\n", ccc);

	char* v;
	v = (char*)&s + ((sizeof(s)+sizeof(int)-1) & ~(sizeof(int)-1));
	while (s)
	{
		printf("%s", s);
		s = *(char**)((v += ((sizeof(char*)+sizeof(int)-1) & ~(sizeof(int)-1))) - ((sizeof(char*)+sizeof(int)-1) & ~(sizeof(int)-1)));
	}
	v = (char*)0;
}

void PrintIntN(int v,...)
{
	int** pp =(int**)&v;
	
	int i = 1;
	while (pp[i])
	{
		printf("%d\n", (pp[i]));
		i++;
	}
}

int main()
{
	PrintIntMStringN(8, 3, "AAAAAAAAAA", "BBBBBBBBBBBBBBB", "CCCCCCCCCCCCCCCCCCCCC");
	PrintStringN("AAAAAAAAAA", "BBBBBBBBBBBBBBB", "CCCCCCCCCCCCCCCCCCCCC");

	PrintIntN(20, 20, 20, 20, 20, 20, 20);

	return 0;
}