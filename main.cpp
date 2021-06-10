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

	//test.TestingBigIntAdd(1000, false);

	//test.TestingBigIntSub(1000, false);

	//test.TestingBigIntAssignmentOperator(10000, true);

	//test.TestingBigIntAdditionOperator(100000, true);
	//test.TestingBigIntSubtractionOperator(100000, true);
	//test.TestingBigIntPrefixIncrementOperator(10000, true);
	//test.TestingBigIntPostfixIncrementOperator(10000, true);
	//test.TestingBigIntPrefixDecrementOperator(10000, true);
	//test.TestingBigIntPostfixDecrementOperator(10000, true);

	//test.TestingBigIntAdditionAssessmentOperator(10000, true);
	//test.TestingBigIntSubtractionAssessmentOperator(10000, true);
	//test.TestingBigIntEqualComparisonOperator(10000, true);
	//test.TestingBigIntNotEqualComparisonOperator(10000, true);

	//test.TestingBigIntLessThanComparisonOperator(500000, false);
	//test.TestingBigIntGreaterThanComparisonOperator(500000, false);
	//test.TestingBigIntLessThanOrEqualComparisonOperator(100000, false);
	//test.TestingBigIntGreaterThanOrEqualComparisonOperator(100000, false);
	test.TestingBigIntMultiplication(10000, true);
	test.TestingBigIntMathTiming(10);
	
	std::string x = "1111";
	std::string y = "20";

	BigInteger test35 = x;

	std::cout << x << std::endl;

	test35.MultiplyToThis(y);

	std::cout << test35 << std::endl;

	long long int stringSplitPoint = 2;

	if (x[0] == '-')
	{

		x = x.substr(1);

	}

	std::cout << x.substr(stringSplitPoint, -stringSplitPoint) << std::endl;
	std::cout << x.substr(stringSplitPoint) << std::endl;

	const int numFact = 500;
	BigInteger fact = FindFactorial(numFact);
	
	std::cout << numFact << "! = " << fact << std::endl;


	a.SetInteger("0");

	BigInteger c;

	std::string g = "1";

	c = g;

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
	//std::cout << c << std::endl;
	//std::cout << d << std::endl;

	

	return 0;

}