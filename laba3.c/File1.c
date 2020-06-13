//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main(void)
{
	int m, n;
	printf("Input m, n: ");
	scanf("%d %d", &m, &n);

	int k, l;
	printf("Input k, l: ");
	scanf("%d %d", &k, &l);

	int** arr = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
		arr[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		   arr[i][j] = (abs(k - i) > abs(1/*это эл*/ - j) ? abs(k - i) + 1 : abs(1 - j) + 1);


	printf("Your matrix:\n");
	for (int i = 0; i < m; i++)
	{
	 for (int j = 0; j< n; j++)
		 printf("%3d", arr[i][j]);
	 printf("\n");
	}
	//  чистим память
	for (int i = 0; i < m ; i++)
		free (arr[i]);
	free (arr);

	getchar();
	return 0;
}
