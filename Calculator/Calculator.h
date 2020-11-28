#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// проверка на число
bool isDig(char c);

// проверка на оператор
bool isOper(char c);

// операция
double oper(double a, double b, char c);

// считываем число
double number(const string &str, int &i);

// игнорируем пробелы
void spaces(const string &str, int &i);

// проверяем наличие '('
bool openParenth(const string &str, int &i, int &countP);

// проверяем наличие ')'
bool closeParenth(const string &str, int &i, int &countP);

// ищем оператор
char lookOper(const string &str, int &i);

// считываем число и следующий знак
void numOp(const string &str, int &i, double &num, char &op, bool &openP, bool &closeP, int &countP);

// калькулятор
double calculate(const string &str, int &i, double a, double b, char op1, char op2, bool &openP, bool &closeP, int &countP);

string calculator(const string &str);