#pragma once
#include <climits>
#include <iostream>
#include <string>
#include <random>
#include "time.h"
#include "biginteger.h"


class Testing
{

public:

	Testing();

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
	int long long passCount;
	int long long trialCount;

};