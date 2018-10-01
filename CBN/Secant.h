#pragma once
#include<stdio.h>
#include<math.h>


#define Func(x) (x*x*x - 4) // f(x)= x^3-4

void test()
{
	float x1, x2, x3, allError, Ittr;
	int count = 1, n;
	printf("\n\nEnter the values of x1 and x2:\n"); //(x1,x2) must contain the solution.
	scanf("%f%f", &x1, &x2);
	printf("Enter the values of allowed error and maximun number of iterations:\n");
	scanf("%f %d", &Ittr, &n);
	do
	{
		if (Func(x1) == Func(x2))
		{
			printf("\nSolution cannot be found as the values of x1 and x2 are same.\n");
			return;
		}
		x3 = (x1*Func(x2) - x2 * Func(x1)) / (Func(x2) - Func(x1));
		x1 = x2;
		x2 = x3;
		printf("Iteration No-%d    x=%f\n", count, x3);
		count++;
		if (count == n)
		{
			break;
		}
	} while (fabs(Func(x3)) > Ittr);
	printf("\n The required solution is %f\n", x3);

}
