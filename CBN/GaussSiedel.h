#pragma once
#include"EquationHandler.h"
#include<stdio.h>

void Iterations(PEquation EquationSet[], int NumEquations) {
	float xith = 0;
	float yith = 0;
	float zith = 0;

	int iter = 20;
	while (iter--) {

		xith = (EquationSet[0]->Ans - EquationSet[0]->Coefficients[1]*yith - EquationSet[0]->Coefficients[2]*zith) / EquationSet[0]->Coefficients[0];
		zith = (EquationSet[2]->Ans - EquationSet[2]->Coefficients[0]*xith - EquationSet[2]->Coefficients[1]*yith) / EquationSet[2]->Coefficients[2];
		yith = (EquationSet[1]->Ans - EquationSet[1]->Coefficients[0]*xith - EquationSet[1]->Coefficients[2]*zith) / EquationSet[1]->Coefficients[1];

		
		printf("\nX:%f",xith);
		printf("\nY:%f",yith);
		printf("\nZ:%f",zith);
		printf("\n\n");
	}



}

void test() {
	PEquation Equations[3];
	float* Vals = (float *)malloc(sizeof(float) * 3);

	Equations[0] = FillEquation(3, 5, 2, 1, 12);
	Equations[1] = FillEquation(3, 1, 4, 2, 15);
	Equations[2] = FillEquation(3, 1, 2, 5, 20);

	Iterations(Equations, 3);
	system("pause");

}