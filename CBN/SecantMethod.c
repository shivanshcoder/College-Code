#define Equation(x) pow(x,3) -4*x -4;  
void mains () {


	int iter = 0;

	float x1, x2, x3;
	float f_x1, f_x2, f_x3;
	float root;
	x1 = 1.75;
	x2 = 2.5;
	while (++iter) {
		f_x1 = Equation(x1);
		f_x2 = Equation(x2);
		
		//x3 = (x2 + x1) / 2;
		x3 = ((x1 * f_x2) - (x2 * f_x1)) / (f_x2 - f_x1);

		f_x3 = Equation(x3);

		int tempx1 = x1 * 10000;
		int tempx2 = x2 * 10000;
		int tempx3 = x3 * 10000;

		if (tempx1 == tempx2 || tempx1 == tempx3 || tempx2 == tempx3)
			break;

		if (f_x1*f_x3 == 0) {
			root = x3;
		}
		else if (f_x1*f_x3 < 0) {
			x2 = x3;
		}
		else if (f_x1*f_x3 > 0) {
			x1 = x3;
		}

		

		printf("\n(%f, %f)", x1, x2);
		



	}

	return;

}
