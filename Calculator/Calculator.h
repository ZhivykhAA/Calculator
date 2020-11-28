#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// �������� �� �����
bool isDig(char c);

// �������� �� ��������
bool isOper(char c);

// ��������
double oper(double a, double b, char c);

// ��������� �����
double number(const string &str, int &i);

// ���������� �������
void spaces(const string &str, int &i);

// ��������� ������� '('
bool openParenth(const string &str, int &i, int &countP);

// ��������� ������� ')'
bool closeParenth(const string &str, int &i, int &countP);

// ���� ��������
char lookOper(const string &str, int &i);

// ��������� ����� � ��������� ����
void numOp(const string &str, int &i, double &num, char &op, bool &openP, bool &closeP, int &countP);

// �����������
double calculate(const string &str, int &i, double a, double b, char op1, char op2, bool &openP, bool &closeP, int &countP);

string calculator(const string &str);