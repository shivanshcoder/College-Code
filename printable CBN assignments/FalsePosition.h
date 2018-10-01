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
	int ithIteration = 0;
	float x2;
	float ithValue;


	while (++ithIteration) {

		x2 = (Range.first + Range.second) / 2;
		saveToFile << "\n\nIteration " << ithIteration
			<< "\nTaking a = " << Range.first << "  and  b =  " << Range.second
			<< "\nx{" << ithIteration << "}  =  (a+b)/2  =  "
			<< "(" << Range.first << ", " << Range.second << ")/2  =  " << x2;

		ithValue = func(x2);
		saveToFile << "\nf(" << x2 << ") = " << ithValue;

		if (ithValue > 0) {
			saveToFile << " > 0";
			Range.second = x2;
		}
		else {
			saveToFile << " < 0";
			Range.first = x2;
		}

		saveToFile << "\nroot lies between: " << Range.first << " and " << Range.second;

		float temp = Range.first*pow(10, decimalCorrectness);
		float temp2 = Range.second*pow(10, decimalCorrectness);
		if ((int)(Range.first*pow(10, decimalCorrectness)) == (int)(Range.second*pow(10, decimalCorrectness))) {
			saveToFile << "\n\nThe Root " << x2 << "  Correct upto " << decimalCorrectness << " Decimals";
			break;
		}
	}
}
