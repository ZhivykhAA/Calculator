#include "pch.h"
#include "../Calculator/Calculator.cpp"

TEST(Calculator, Test1) {
	ASSERT_EQ("1", calculator("-1 + 5 - 3"));
}

TEST(Calculator, Test2) {
	ASSERT_EQ("-24", calculator("-1 * 2 * 3 * 4"));
}

TEST(Calculator, Test3) {
	ASSERT_EQ("1", calculator("6 / 1,5 - 1 * 3"));
}

TEST(Calculator, Test4) {
	ASSERT_EQ("6", calculator("2 + 2*2"));
}

TEST(Calculator, Test5) {
	ASSERT_EQ("3.18", calculator("(2,51+3.84)/2"));
}

TEST(Calculator, Test6) {
	ASSERT_EQ("8", calculator("2*(2+2)"));
}

TEST(Calculator, Test7) {
	ASSERT_EQ("8", calculator("-10 + (8 * 2,5) - (3 / 1.5)"));
}

TEST(Calculator, Test8) {
	ASSERT_EQ("11", calculator("1 + (2 * (2,5 + 2,5 + (3 - 2))) - (3 / 1.5)"));
}

TEST(Calculator, Test9) {
	ASSERT_EQ("2", calculator("4 * (1 + (3 - (2 * (9 / 3) + 1) * 3) / 9) + 6"));
}

TEST(Calculator, Test10) {
	ASSERT_EQ("5", calculator("7-(2+((5-(3+(8-7)*4)*2)/(-3))*2)/4"));
}

TEST(Calculator, Test11) {
	ASSERT_EQ("18", calculator("(((1+2)*4+3)/5)*6"));
}

TEST(Calculator, Test12) {
	ASSERT_EQ("-7", calculator("7*(-1)"));
}

TEST(Calculator, Test13) {
	ASSERT_EQ("13.03", calculator("   5    /  3    *    7,2    +   (    8.5 -  7 /   3   )  /6"));
}

TEST(Calculator, Test14) {
	ASSERT_EQ("error when dividing by 0", calculator("5 + 7 / 0"));
}

TEST(Calculator, Test15) {
	ASSERT_EQ("invalid input, the string contains an invalid expression abc", calculator("1.1 + 2.1 + abc"));
}