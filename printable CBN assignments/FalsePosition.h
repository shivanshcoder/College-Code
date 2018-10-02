#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<math.h>


float func(float x);

#ifndef printFunc
#define printFunc(x) std::cout<<"\nERROR printFunc MACRO not Found"
#endif // !printFunc


extern std::string FileName;

#define saveToFile std::cout 

//Finds the range
std::pair<float, float> FindingRootRange(float startRange = 0.0) {

	if (func(startRange) < 0.0) {

		while (func(startRange += .5) < 0.0);

		//Negative side
		printFunc(startRange - 0.5);
		saveToFile << " = " << func(startRange - 0.5) << " < 0";

		//Positive side
		printFunc(startRange);
		saveToFile << " = " << func(startRange) << " > 0";

		saveToFile << "\n\nSo the Real root of equation lies in the interval (" << startRange - 0.5 << ", " << startRange << ")";
		return std::make_pair(startRange - 0.5, startRange);
	}
	else
		return FindingRootRange(startRange -= 10);
}

void Iterations(int decimalCorrectness) {
	std::pair<float, float> Range = FindingRootRange();

	std::pair<float, float> f_Range;
	int ithIteration = 0;
	float x2;
	float f_x2;
	


	while (++ithIteration) {
		f_Range = std::make_pair(func(Range.first), func(Range.second));

		x2 = (Range.first*f_Range.second - Range.second*f_Range.first) / (f_Range.second - f_Range.first);

		f_x2 = func(x2);
		saveToFile << "\n\nIteration " << ithIteration
			<< "\nTaking a = " << Range.first << "  and  b =  " << Range.second;

		saveToFile << "\nx{" << ithIteration << "}  =  ( a*f(b) - b*f(a) ) / ( f(b) - f(a) ) ";

		saveToFile << "\nx{" << ithIteration << "}  =  "
			<< "( " << Range.first << " * " << f_Range.second << "  -  " << Range.second << " * " << f_Range.first << " ) / ( "
			<< f_Range.second << " - " << f_Range.first << " )  =" << x2;

		printFunc(x2);
		saveToFile << "\nf(" << x2 << ") = " << f_x2;

		if (f_x2 == 0) {
			break;
		}
		else if ((f_x2 * func(Range.first)) > 0) {
			Range.second = x2;
		}
		else {
			Range.first = x2;
		}

		saveToFile << "\nroot lies between: " << Range.first << " and " << Range.second;

		float temp = Range.first*pow(10, decimalCorrectness);
		float temp2 = Range.second*pow(10, decimalCorrectness);
		if ((int)(Range.first*pow(10, decimalCorrectness)) == (int)(Range.second*pow(10, decimalCorrectness))) {
			break;
		}
	}

	saveToFile << "\n\nThe Root " << x2 << "  Correct upto " << decimalCorrectness << " Decimals";
}
