#include <stdio.h>
#include <stdlib.h>


int main()
{
	// ���d�z��̃|�C���^�ƒʏ�ł̕\��
	const int row = 3;
	const int col = 2;

	int aiScore[row][col] = { {56,60},{65,70},{85,50} };
	int *piData;

	for (int i = 0; i != row; ++i)
	{
		for (int j = 0; j != col; ++j)
		{
			printf("[%d][%d]: %d\n", i, j, *(*(aiScore + i) + j));
			// printf("[%d][%d]: %d\n", i, j, aiScore[i][j]);  // �Ɠ���
		}
	}

	piData = (int *)aiScore;
	for (int i = 0; i != row * col; ++i)
	{
		printf("*(piData * %d): %d\n", i, *(piData + i));
	}
	printf("\n");
	// ���d�z��̃|�C���^�ƒʏ�ł̕\��


	// �_�C�i�~�b�N�Ɋm��
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
	// �_�C�i�~�b�N�Ɋm��


	// ������|�C���^
	char aa[] = "abc";
	char bb[] = { 'a','b','c','\0' };
	const char *cc = "abc";				// const�ɂ��Ă���̂́Aconst���������Ƃ���Œ��g��M�邱�Ƃ��o���Ȃ�����ł��B���΁c�킩��c
	printf("aa��bb��cc�̃�������Ԃ́F%d, %d, %d\n", sizeof(aa), sizeof(bb), sizeof(cc));

	printf("0�̃A�h���X: %p\n", cc);
	printf("1�̃A�h���X: %p\n", cc + 1);
	printf("2�̃A�h���X: %p\n", cc + 2);
	printf("3�̃A�h���X: %p\n", cc + 3);

	printf("0�̒��g: %c\n", *cc);
	printf("1�̒��g: %c\n", *(cc + 1));
	printf("2�̒��g: %c\n", *(cc + 2));
	printf("3�̒��g: 0x%02x\n\n", *(cc + 3));		// NULL�̂���%c�ł͕\���ł��Ȃ��̂�2����16�i��
	printf("�S��: %s\n", cc);
	// ������|�C���^

	return 0;
}