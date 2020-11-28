#include "Calculator.h"

// checking for a number
bool isDig(char c) {
	return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

// checking for an operator
bool isOper(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// operator
double oper(double a, double b, char c) {
	double res = 0;
	if (c == '+') {
		return a + b;
	}
	else if (c == '-') {
		return a - b;
	}
	else if (c == '*') {
		return a * b;
	}
	else if (c == '/') {
		if (b == 0) {
			throw - 1;
		}
		return a / b;
	}
	return res;
}

// reading the number
double number(const string &str, int &i) {
	string numStr = "";
	double num;

	while (i < str.size() && (isDig(str[i]) || !numStr.empty() && (str[i] == '.' || str[i] == ','))) {
		if (str[i] == ',') {
			numStr += '.';
		}
		else {
			numStr += str[i];
		}
		++i;
	}

	istringstream(numStr) >> num;

	return num;
}

// ignore the spaces
void spaces(const string &str, int &i) {
	while (i < str.size() && str[i] == ' ') {
		++i;
	}
}

// checking for availability '('
bool openParenth(const string &str, int &i, int &countP) {
	// ignore the spaces
	spaces(str, i);

	while (i < str.size() && str[i] == '(') {
		++i;
		++countP;
		return true;
	}

	return false;
}

// checking for availability ')'
bool closeParenth(const string &str, int &i, int &countP) {
	// ignore the spaces
	spaces(str, i);

	while (i < str.size() && str[i] == ')') {
		++i;
		--countP;
		return true;
	}

	return false;
}

// looking for an operator
char lookOper(const string &str, int &i) {
	// ignore the spaces
	spaces(str, i);

	// operator
	if (i < str.size() && isOper(str[i])) {
		++i;
		return str[i - 1];
	}
	return NULL;
}


// read the number and the next operator
void numOp(const string &str, int &i, double &num, char &op, bool &openP, bool &closeP, int &countP) {

	// checking for availability '('
	openP = openParenth(str, i, countP);

	// ignore the spaces
	spaces(str, i);

	// try reading the number
	if (i < str.size() && isDig(str[i])) {
		num = number(str, i);
	}

	// checking for availability ')'
	if (closeParenth(str, i, countP)) {
		closeP = true;
		return;
	}

	// operator
	op = lookOper(str, i);

	// checking for invalid characters
	string incorrectChar = "";
	while (i < str.size() && str[i] != '(' && str[i] != ')' && str[i] != ' ' && !isDig(str[i]) && !isOper(str[i])) {
		incorrectChar += str[i];
		++i;
	}
	if (!incorrectChar.empty()) {
		throw "invalid input, the string contains an invalid expression " + incorrectChar;
	}
}

// calculation
double calculate(const string &str, int &i, double a, double b, char op1, char op2, bool &openP, bool &closeP, int &countP) {
	double res = 0;

	while (i < str.size()) {

		if (op1 == NULL && op2 == NULL) {
			numOp(str, i, a, op1, openP, closeP, countP);
			if (openP) {
				res = calculate(str, i, a, b, op1, NULL, openP, closeP, countP);
				a = res;
				op1 = lookOper(str, i);
				openP = false;
			}

			numOp(str, i, b, op2, openP, closeP, countP);
			if (openP && !closeP) {
				b = calculate(str, i, b, 0, op2, NULL, openP, closeP, countP);
				op2 = lookOper(str, i);
			}

		}
		else if (op2 == NULL) {
			numOp(str, i, b, op2, openP, closeP, countP);
			if (openP && !closeP) {
				b = calculate(str, i, b, 0, op2, NULL, openP, closeP, countP);
				op2 = lookOper(str, i);
			}
		}

		if (((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-' || op2 == NULL)) ||
			((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/' || op2 == NULL)) ||
			((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-' || op2 == NULL))) {
			res = oper(a, b, op1);
			if (closeP || closeParenth(str, i, countP)) {
				closeP = false;
				return res;
			}
			else {
				a = res;
				op1 = op2;
				b = NULL;
				op2 = NULL;
			}
		}
		else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) {
			b = calculate(str, i, b, 0, op2, NULL, openP, closeP, countP);
			res = oper(a, b, op1);
			return res;
		}
	}
	return res;
}

string calculator(const string &str) {
	int i = 0, countP = 0;
	bool openP = false, closeP = false;

	try {
		ostringstream ss;
		ss << round(calculate(str, i, 0, 0, NULL, NULL, openP, closeP, countP) * 100) / 100;
		return ss.str();
	}
	catch (int) {
		return "error when dividing by 0";
	}
	catch (const string &exception) {
		return exception;
	}
}