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

	Testing();

	void TestingBigIntMathTiming(int trialsCount, bool isRandom);

	void TestingBigIntMultiplication(int trialsCount, bool stopOnFail);
	void TestingBigIntDivisionRandom(int trialsCount, bool stopOnFail);
	void TestingBigIntDivision(int trialsCount, bool stopOnFail);

	void TestingBigIntGreaterThanOrEqualComparisonOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntLessThanOrEqualComparisonOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntGreaterThanComparisonOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntLessThanComparisonOperator(int trialsCount, bool stopOnFail);

	void TestingBigIntNotEqualComparisonOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntEqualComparisonOperator(int trialsCount, bool stopOnFail);

	void TestingBigIntAdditionAssessmentOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntSubtractionAssessmentOperator(int trialsCount, bool stopOnFail);

	void TestingBigIntPrefixDecrementOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntPostfixDecrementOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntPrefixIncrementOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntPostfixIncrementOperator(int trialsCount, bool stopOnFail);

	void TestingBigIntAssignmentOperator(int trialsCount, bool stopOnFail);

	void TestingBigIntAdditionOperator(int trialsCount, bool stopOnFail);
	void TestingBigIntSubtractionOperator(int trialsCount, bool stopOnFail);

	void TestingBigIntAdd(int trialsCount, bool stopOnFail);
	void TestingBigIntSub(int trialsCount, bool stopOnFail);

	void TestingBigIntAddToThis(int trialsCount, bool stopOnFail);
	void TestingBigIntSubToThis(int trialsCount, bool stopOnFail);

private:

	BigInteger a;
	BigInteger b;
	int long long passCount;
	int long long trialCount;

};