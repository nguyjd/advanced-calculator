#pragma once
#include <climits>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "time.h"
#include "biginteger.h"


class Testing
{

public:

	static void TestingBigIntMathTiming(int trialsCount, bool isRandom);

	static void TestingBigIntMultiplication(int trialsCount, bool stopOnFail);
	static void TestingBigIntDivisionRandom(int trialsCount, bool stopOnFail);
	static void TestingBigIntDivision(int trialsCount, bool stopOnFail);
	static void TestingBigIntModulusRandom(int trialsCount, bool stopOnFail);
	static void TestingBigIntModulus(int trialsCount, bool stopOnFail);

	static void TestingBigIntGreaterThanOrEqualComparisonOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntLessThanOrEqualComparisonOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntGreaterThanComparisonOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntLessThanComparisonOperator(int trialsCount, bool stopOnFail);

	static void TestingBigIntNotEqualComparisonOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntEqualComparisonOperator(int trialsCount, bool stopOnFail);

	static void TestingBigIntAdditionAssessmentOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntSubtractionAssessmentOperator(int trialsCount, bool stopOnFail);

	static void TestingBigIntPrefixDecrementOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntPostfixDecrementOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntPrefixIncrementOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntPostfixIncrementOperator(int trialsCount, bool stopOnFail);

	static void TestingBigIntAssignmentOperator(int trialsCount, bool stopOnFail);

	static void TestingBigIntAdditionOperator(int trialsCount, bool stopOnFail);
	static void TestingBigIntSubtractionOperator(int trialsCount, bool stopOnFail);

	static void TestingBigIntAdd(int trialsCount, bool stopOnFail);
	static void TestingBigIntSub(int trialsCount, bool stopOnFail);

	static void TestingBigIntAddToThis(int trialsCount, bool stopOnFail);
	static void TestingBigIntSubToThis(int trialsCount, bool stopOnFail);

};