#include <stdio.h>
#include <stdlib.h>
int arr[8][8], fl;
int func(int a, int b)
{
    int i;
    for (i = 0; i < a; i++)
        if (arr[i][b] == 1)
            return 0;
    for (i = 1; i <= a && b - i >= 0; i++)
        if (arr[a - i][b - i] == 1)
            return 0;
    for (i = 1; i < a && b + i < 8; i++)
        if (arr[a - i][b + i] == 1)
            return 0;
    return 1;

}

void rec(int a)// a - номер очередной строки в которой нужно поставить очередного ферзя
{
    if (a == 8)// здесь выводим на экран результат (массив arr[][]) и выходим из программы (или прерываем рекурсию)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }
        fl = 1;
    }
    for (int i = 0; i < 8 && !fl; i++)
        if (func(a, i))// здесь проверяем что если поставим в arr[a][i] единицу, то она будет единственной в этой строке, столбце и диагоналях
        {
            arr[a][i] = 1;
            rec(a + 1);
            arr[a][i] = 0;
        }
}

int main()
{
    rec(0);
    return 0;
}