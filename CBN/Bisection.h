#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



#define Func(x) x*x*x - 4 * x - 9



void bisection(float *x, float a, float b, int *itr)
/* this function performs and prints the result of one iteration */
{
	*x = (a + b) / 2;
	++(*itr);
	printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}

void test()
{
	int itr = 0, maxmitr;
	float xOld, x1, x2, allerr, xNew;
	printf("\nEnter the values of x1, x2, allowed error and maximum iterations:\n");
	scanf("%f %f %f %d", &x1, &x2, &allerr, &maxmitr);
	bisection(&xOld, x1, x2, &itr);
	do
	{
		if (Func(x1)*Func(xOld) < 0)
			x2 = xOld;
		else
			x1 = xOld;

		bisection(&xNew, x1, x2, &itr);
		if (fabs(xNew - xOld) < allerr)
		{
			printf("After %d iterations, root = %6.4f\n", itr, x1);
			return;
		}
		xOld = xNew;
	} while (itr < maxmitr);
	printf("The solution does not converge or iterations are not sufficient");
	return ;
}
