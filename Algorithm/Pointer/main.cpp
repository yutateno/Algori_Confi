#include <stdio.h>
#include <stdlib.h>


int main()
{
	// 多重配列のポインタと通常での表示
	const int row = 3;
	const int col = 2;

	int aiScore[row][col] = { {56,60},{65,70},{85,50} };
	int *piData;

	for (int i = 0; i != row; ++i)
	{
		for (int j = 0; j != col; ++j)
		{
			printf("[%d][%d]: %d\n", i, j, *(*(aiScore + i) + j));
			// printf("[%d][%d]: %d\n", i, j, aiScore[i][j]);  // と同じ
		}
	}

	piData = (int *)aiScore;
	for (int i = 0; i != row * col; ++i)
	{
		printf("*(piData * %d): %d\n", i, *(piData + i));
	}
	printf("\n");
	// 多重配列のポインタと通常での表示


	// ダイナミックに確保
	const int arrayNum = 3;

	int *piData2 = nullptr;
	
	piData2 = (int *)malloc(sizeof(int) * arrayNum);
	if (piData2 == nullptr)
	{
		return -1;
	}

	*(piData2 + 0) = 10;
	*(piData2 + 1) = 20;
	*(piData2 + 2) = 30;

	for (int i = 0; i != arrayNum; ++i)
	{
		printf("[%d]: %d\n", i, *(piData2 + i));
	}

	*(piData2 + 0) = 100;
	printf("[0]: %d\n\n", *(piData2 + 0));

	free(piData2);
	// ダイナミックに確保


	// 文字列ポインタ
	char aa[] = "abc";
	char bb[] = { 'a','b','c','\0' };
	const char *cc = "abc";				// constにしているのは、constを消したところで中身を弄ることが出来ないからです。やれば…わかる…
	printf("aaとbbとccのメモリ状態は：%d, %d, %d\n", sizeof(aa), sizeof(bb), sizeof(cc));

	printf("0のアドレス: %p\n", cc);
	printf("1のアドレス: %p\n", cc + 1);
	printf("2のアドレス: %p\n", cc + 2);
	printf("3のアドレス: %p\n", cc + 3);

	printf("0の中身: %c\n", *cc);
	printf("1の中身: %c\n", *(cc + 1));
	printf("2の中身: %c\n", *(cc + 2));
	printf("3の中身: 0x%02x\n\n", *(cc + 3));		// NULLのため%cでは表示できないので2桁の16進数
	printf("全部: %s\n", cc);
	// 文字列ポインタ

	return 0;
}