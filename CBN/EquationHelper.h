#pragma once
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//
//#define NUM 0
//#define VAR 1
//
//#define POWER 2
//#define OPERATOR 3
//
//
//#define EMPTY 99
//
//typedef struct tagVariables{
//	double Exp[3];
//}Variables;
//
//Variables Expression[10];
//int SizeExpression = 0;
//
//void IniExpression() {
//	for (int i = 0; i < 10; ++i) {
//		Expression[i].Exp[NUM] = 1;
//		Expression[i].Exp[VAR] = 0;
//		Expression[i].Exp[NUM] = 1;
//	}
//}
//
//float EvalExp(int X) {
//	float sum = 0;
//	for (int i = 0; i < SizeExpression; ++i)
//		sum += Expression[i].Exp[0] * pow(Expression[i].Exp[1] * X, Expression[i].Exp[2]);
//	return sum;
//}
//
//int Categorize(char **String) {
//	if (isdigit(**String) || **String == '-' || **String == '+')
//		return NUM;
//	else if (**String == '^') {
//		return POWER;
//	}
//	else if (**String == '\0')
//		return EMPTY;
//	else if (**String == '_' || isalpha(**String))
//		return VAR;
//}
//
//void InputVariables(char **String, Variables* Var) {
//	if (Categorize(String) == NUM) {
//		Var->Exp[VAR] = 1;
//
//		if (!isdigit(*(*String + 1)))
//			Var->Exp[NUM] *= -1;
//		else {
//			Var->Exp[NUM] = strtod(*String, String);
//		}
//	}
//
//	while (Categorize(String) == VAR)
//		(*String)++;
//
//	if (Categorize(String) == POWER) {
//		(*String)++;
//		Var->Exp[POWER] = strtod(*String, String);
//	}
//}
//
//double FillExp(char* Equation) {
//	IniExpression();
//	//-2x^3-4x-5
//	int index = 0;
//	char* CurrentIndex = Equation;
//
//	while (*CurrentIndex) {
//		InputVariables(&CurrentIndex, Expression + index);
//		index++;
//
//	}
//	SizeExpression = index;
//
//}
int sizeExpression(char* Equation);
void FillExpression(char* Equation, Variable* Expression);
void Fill(char* Equation);


typedef struct tagVar {
	float *Var;
	char Operator;
	struct tagVar *Next;
}Variable;

int sizeExpression(char* Equation) {
	int index = 0;
	while (*Equation != ')') {
		index++;
	}
}

void FillExpression(char* Equation,Variable* Expression) {
	int SizeExp = sizeExpression(Equation + 1);

}

void ReadInput(char* Equation) {
	switch (*Equation) {
	case '(':
	case ')':


	}
}

void Fill(char* Equation) {
	Variable *Expression;
	if (*Equation == '(') {
		Expression = (Variable*)malloc(sizeof(Variable));

	}

}