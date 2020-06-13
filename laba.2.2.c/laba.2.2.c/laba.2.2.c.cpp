#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Pow(double X, int n)
{
	double result = 1;
	unsigned long long int k = 0;
	while (k < n)
	{
		result *= X;
		k++;
	}
	return result;
}

double Fact(int X)
{
	if (X == 1)
	{
		return X;
	}
	else
	{
		return X * Fact(X - 1);
	}
}

double Sin(double X, int n)
{
	double result = 0;
	int i = 1;
	while (i < n + 1)
	{
		result += Pow(-1, i - 1) * Pow(X, 2 * i - 1) / Fact(2 * i - 1);
		i++;
	}
	return result;
}

int main()
{
	double X = 0.1;
	double result;
	double check;
	double infelicity;//погрешность 
	double currentInfelicity;//текущая погрешность 
	double temp = 9;
	int i = 0;
	int j;
	printf("Set infelicity in percent: ");
	scanf_s("%lf", &infelicity);
	infelicity /= 100;
	while (i < 100)
	{
		j = 1;
		currentInfelicity = fabs(sin(X) * infelicity);
		check = sin(X);

		while (fabs(temp) - currentInfelicity > 0)
		{
			temp = check - Sin(X, j);
			j++;
		}
		temp = 9;
		result = Sin(X, j);
		printf("%d| Form sin: %lf | default sin: %lf | infelicity: %lf | n: %d\n", i, result, check, currentInfelicity, j);
		X += 0.1;
		i++;
	}
	return 0;
}