#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<math.h>


float func(float x);
float Drevfunc(float x);

#ifndef printFunc
#define printFunc(x) std::cout<<"\nERROR printFunc MACRO not Found"
#endif // !printFunc

#ifndef printDrevFunc
#define printDrevFunc(x) std::cout<<"\nERROR printFunc MACRO not Found"
#endif // !printFunc


extern std::string FileName;

#define saveToFile std::cout 

//Finds the range
float FindingRootRange(float startRange = 0.0) {

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