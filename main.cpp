#include "main.h"

// Recursion function to calulate the factorial.
// The function loops until n == 0
BigInteger FindFactorial(const int n)
{

	// Base Condition.
	if (n == 0)
	{

		return 1;

	}

	// This multiply the n * n-1
	return static_cast<BigInteger>(n) * FindFactorial(n - 1);

}

int main()
{

	
	//test.TestingBigIntAdd(1000, true);

	//test.TestingBigIntSub(1000, false);

	//test.TestingBigIntAssignmentOperator(1000, false);

	//test.TestingBigIntAdditionOperator(1000, false);
	//test.TestingBigIntSubtractionOperator(1000, false);
	//test.TestingBigIntPrefixIncrementOperator(1000, false);
	//test.TestingBigIntPostfixIncrementOperator(1000, false);
	//test.TestingBigIntPrefixDecrementOperator(1000, false);
	//test.TestingBigIntPostfixDecrementOperator(1000, false);

	//test.TestingBigIntAdditionAssessmentOperator(1000, false);
	//test.TestingBigIntSubtractionAssessmentOperator(1000, false);
	//test.TestingBigIntEqualComparisonOperator(1000, false);
	//test.TestingBigIntNotEqualComparisonOperator(1000, false);

	//test.TestingBigIntLessThanComparisonOperator(1000, false);
	//test.TestingBigIntGreaterThanComparisonOperator(1000, false);
	//test.TestingBigIntLessThanOrEqualComparisonOperator(1000, false);
	//test.TestingBigIntGreaterThanOrEqualComparisonOperator(1000, false);
	
	//test.TestingBigIntMultiplication(1000, false);
	test.TestingBigIntDivision(10000, true);
	test.TestingBigIntDivisionRandom(10000, true);
	test.TestingBigIntMathTiming(1000, true);

	const int numFact = 100;
	BigInteger fact = FindFactorial(numFact);
	
	std::cout << numFact << "! = " << fact << std::endl;

	a.SetInteger("0");

	BigInteger c;

	std::string g = "100";

	c = g;

	std::cout << "c: " << c << std::endl;
	c.DivideToThis("50");
	std::cout << "c: " << c << std::endl;

	BigInteger d(80);

	//std::cout << d << std::endl;

	c.AddToThis('1');

	d.SetInteger(10);

	d = 10;

	//b.SetInteger("1999");

	//a.SubToThis(b);

	//a.LongMultiplicationToThis("99");

	//std::cout << a << std::endl;
	//std::cout << fact << std::endl;
	std::cout << c << std::endl;
	//std::cout << d << std::endl;

	return 0;

}