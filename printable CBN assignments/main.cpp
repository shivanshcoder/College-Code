#define printFunc(x) std::cout << "\n\nf(" << x << ")  =  " << x << "^4 - " << x << " - 10"

#include"Secant.h"

//float func(float x) {
//	return (x*x*x) - 2 * x - 5;
//}
//
//void printFunc(float x) {
//	std::cout << "\n\nf(" << x << ")  =  " << x << "^3" << " -  2*" << x << "  - 5";
//}


//float func(float x) {
//	return x * x - 5;
//}
//
//void printFunc(float x) {
//	std::cout << "\n\nf(" << x << ")  =  " << x << "^2" << " - 5";
//}


//float func(float x) {
//	return x * exp(x) - 1;
//}
//
//void printFunc(float x) {
//	std::cout << "\n\nf(" << x << ")  =  " << x << "* e^" << x << " - 1";
//}

float func(float x) {
	return pow(x, 4) - x - 10;
}

//void printFunc(float x) {
//	std::cout << "\n\nf(" << x << ")  =  " << x << "^3 -" << x << " - 1";
//}



void main() {
	Iterations(3);
	system("pause");
}