#pragma once
#include<stdarg.h>
#include<stdlib.h>

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
