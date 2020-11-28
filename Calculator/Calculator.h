#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// checking for a number
bool isDig(char c);

// checking for an operator
bool isOper(char c);

// operator
double oper(double a, double b, char c);

// reading the number
double number(const string &str, int &i);

// ignore the spaces
void spaces(const string &str, int &i);

// checking for availability '('
bool openParenth(const string &str, int &i, int &countP);

// checking for availability ')'
bool closeParenth(const string &str, int &i, int &countP);

// looking for an operator
char lookOper(const string &str, int &i);

// read the number and the next operator
void numOp(const string &str, int &i, double &num, char &op, bool &openP, bool &closeP, int &countP);

// calculation
double calculate(const string &str, int &i, double a, double b, char op1, char op2, bool &openP, bool &closeP, int &countP);

string calculator(const string &str);