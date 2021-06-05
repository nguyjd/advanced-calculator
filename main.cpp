#include "main.h"

int main()
{

	//test.TestingBigIntAdd(1000, false);

	//test.TestingBigIntSub(1000, false);

	//test.TestingBigIntAdditionOperator(100000, true);
	//test.TestingBigIntSubtractionOperator(100000, true);
	test.TestingBigIntPrefixIncrementOperator(10000, true);
	test.TestingBigIntPostfixIncrementOperator(10000, true); // failed
	test.TestingBigIntPrefixDecrementOperator(10000, true);
	test.TestingBigIntPostfixDecrementOperator(10000, true);
	
	/*
	
	a.SetInteger("99");

	BigInteger c;

	c = a.Sub("1");

	BigInteger d(80);

	std::cout << d.GetInteger() << std::endl;

	c.AddToThis('1');

	d.SetInteger(10);

	d = 10;

	

	//b.SetInteger("1999");

	//a.SubToThis(b);

	std::cout << a.GetInteger() << std::endl;
	std::cout << c.GetInteger() << std::endl;
	std::cout << d.GetInteger() << std::endl;

	*/

	return 0;

}