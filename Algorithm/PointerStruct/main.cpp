#include <stdio.h>
#include <string.h>


// 構造体関数渡し（コピーを渡さずポインタからデータを参照するので直接渡すより処理軽い
struct STNameAge
{
	int iId;
	char szName[20];
	int iAge;
};

void PrintStruct(STNameAge* pstNameAge, int iSize);


int main()
{
	STNameAge stNameAge[2];

	stNameAge[0].iId = 1;
	strcpy_s(stNameAge[0].szName, "Tateno");
	stNameAge[0].iAge = 23;

	stNameAge[1].iId = 2;
	strcpy_s(stNameAge[1].szName, "TatenoYU");
	stNameAge[1].iAge = 46;

	PrintStruct(stNameAge, sizeof(stNameAge) / sizeof(STNameAge));

	return 0;
}


void PrintStruct(STNameAge * pstNameAge, int iSize)
{
	for (int i = 0; i != iSize; ++i)
	{
		printf("Id: %d\n", (pstNameAge + i)->iId);
		printf("Name: %s\n", (pstNameAge + i)->szName);
		printf("Age: %d\n", (pstNameAge + i)->iAge);
	}
}
