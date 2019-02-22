#include <stdio.h>


void SayHello();
void PrintAdd(int a, int b);
int Add(int a, int b);
int Sub(int a, int b);


int main()
{
	void(*p_funcSayHello)();
	void(*p_funcPrintAdd)(int a, int b);
	int(*p_funcAdd)(int a, int b);
	int(*p_func[])(int a, int b) = { Add, Sub };


	p_funcSayHello = SayHello;
	p_funcPrintAdd = PrintAdd;
	p_funcAdd = Add;


	p_funcSayHello();
	p_funcPrintAdd(1, 2);
	int iRet = p_funcAdd(3, 4);
	printf("iRet = %d\n", iRet);


	int iRetAdd = p_func[0](1, 2);
	int iRetSub = p_func[1](2, 3);
	printf("iRetAdd = %d\n", iRetAdd);
	printf("iRetSub = %d\n", iRetSub);


	return 0;
}


void SayHello()
{
	printf("Hello\n");
}


void PrintAdd(int a, int b)
{
	printf("%d\n", a + b);
}


int Add(int a, int b)
{
	return a + b;
}


int Sub(int a, int b)
{
	return a > b ? a - b : b - a;
}