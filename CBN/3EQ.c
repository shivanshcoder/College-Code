#include"GaussEquations.h"


void main() {
	PEquation Equations[3];
	float* Vals = (float *)malloc(sizeof(float) * 3);
	
	Equations[0] = FillEquation(3, 1, 2, 3, 6);
	Equations[1] = FillEquation(3, 2, 1, 2, 5);
	Equations[2] = FillEquation(3, 4, 2, 5, 11);


	solveEquation(Equations, Vals, 3);

	//Vals stores the value of coefficients x, y, z
	for (int i = 0; i < 3; ++i) {
		printf("%f   ", *(Vals + i));
	}
	//system("pause");
}
