#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

typedef struct tagEquation {
	float *Coefficients;
	float Ans;
}*PEquation;

PEquation initEquation(int numVars) {
	PEquation temp = (PEquation)malloc(sizeof(struct tagEquation));
	temp->Coefficients = (float*)malloc(sizeof(int) * numVars);
	return temp;
}

PEquation FillEquation(int numVars, ...) {
	va_list valist;

	PEquation temp = (PEquation)malloc(sizeof(struct tagEquation));
	

	va_start(valist, numVars);

	temp->Coefficients = (float*)malloc(sizeof(float) * numVars);

	for (int i = 0; i < numVars; ++i) {
		float t = va_arg(valist, int);
		temp->Coefficients[i] = t;
	}
	temp->Ans = va_arg(valist, int);

	va_end(valist);

	return temp;

}

void EliminateEquation(PEquation Equation, PEquation Equation2, PEquation *SimplifiedEqation, int NumberTerms) {
	float ratio = Equation2->Coefficients[0] / Equation->Coefficients[0];

	(*SimplifiedEqation)->Ans = Equation2->Ans - ratio * Equation->Ans;

	for (int i = 0; i < NumberTerms; ++i) {
		(*SimplifiedEqation)->Coefficients[i] = Equation2->Coefficients[i] - ratio * Equation->Coefficients[i];
	}

	(*SimplifiedEqation)->Coefficients++;
}

void solveEquation(PEquation EquationSet[], float *Vals, int NumEquations) {

	if (NumEquations >= 2) {
		for (int ithEquation = 1; ithEquation < NumEquations; ++ithEquation)
			EliminateEquation(EquationSet[0], EquationSet[ithEquation], EquationSet + ithEquation, NumEquations);


		solveEquation(EquationSet + 1, Vals + 1, NumEquations - 1);
		*Vals = EquationSet[0]->Ans;

		for (int ithTerm = 1; ithTerm < NumEquations; ++ithTerm)
			*Vals -= (EquationSet[0]->Coefficients[ithTerm] * (*(Vals + ithTerm)));


		*Vals /= EquationSet[0]->Coefficients[0];
	}
	else {
		*Vals = EquationSet[0]->Ans / EquationSet[0]->Coefficients[0];
		Vals--;
	}
}