#include "testing.h"

Testing::Testing()
{

	passCount = 0;
	trialCount = 0;

}

void Testing::TestingBigIntMathTiming(int trialsCount)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN, INT_MAX);
	passCount = 0;
	trialCount = 0;

	if (trialsCount <= 0)
	{

		return;

	}

	std::cout << "---------------------TESTING BIG INTEGER MATH TIMING----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	std::chrono::microseconds addTotalTime = std::chrono::microseconds::zero();
	std::chrono::microseconds subTotalTime = std::chrono::microseconds::zero();
	std::chrono::microseconds multiTotalTime = std::chrono::microseconds::zero();

	BigInteger add;
	BigInteger sub;
	BigInteger multi;


	std::cout << "Running the timing trials" << std::endl;
	for (int i = 0; i < trialsCount; i++)
	{
		
		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);
		std::string randNum2Str = std::to_string(randNum2);

		trialCount++;

		add = randNum1;
		sub = randNum1;
		multi = randNum1;
		
		auto addStartTime = std::chrono::steady_clock::now();
		add.AddToThis(randNum2Str);
		auto addStopTime = std::chrono::steady_clock::now();

		auto subStartTime = std::chrono::steady_clock::now();
		sub.SubToThis(randNum2Str);
		auto subStopTime = std::chrono::steady_clock::now();

		auto multiStartTime = std::chrono::steady_clock::now();
		multi.LongMultiplicationToThis(randNum2Str);
		auto multiStopTime = std::chrono::steady_clock::now();

		addTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(addStopTime - addStartTime);
		subTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(subStopTime - subStartTime);
		multiTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(multiStopTime - multiStartTime);

	}

	if (trialsCount > 0)
	{

		addTotalTime /= trialsCount;
		subTotalTime /= trialsCount;
		multiTotalTime /= trialsCount;

	}
	

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Adding Time Average: " << addTotalTime.count() << " microseconds" << std::endl;
	std::cout << "Subtracing Time Average: " << subTotalTime.count() << " microseconds" << std::endl;
	std::cout << "Multiplying Time Average: " << multiTotalTime.count() << " microseconds" << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntLongMultiplication(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN, INT_MAX);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER LongMultiplicationToThis()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{
		BigInteger temp;
		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		long long int correctAns = static_cast<long long int>(randNum1) * static_cast<long long int>(randNum2);

		a = randNum1;

		a.LongMultiplicationToThis(std::to_string(randNum2));

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << randNum1 << " * " << randNum2 << std::endl;
		std::cout << "Correct Answer: " << correctAns << std::endl;
		std::cout << "Computed Answer: " << a << std::endl;

		if (a == correctAns)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntGreaterThanOrEqualComparisonOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator>=()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a = randNum1;
		b = randNum2;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Comparing Numbers " << randNum1 << " and " << randNum2 << std::endl;

		if ((a >= b) == (randNum1 >= randNum2))
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntLessThanOrEqualComparisonOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator<=()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a = randNum1;
		b = randNum2;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Comparing Numbers " << randNum1 << " and " << randNum2 << std::endl;

		if ((a <= b) == (randNum1 <= randNum2))
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntGreaterThanComparisonOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator>()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a = randNum1;
		b = randNum2;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Comparing Numbers " << randNum1 << " and " << randNum2 << std::endl;

		if ((a > b) == (randNum1 > randNum2))
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntLessThanComparisonOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator<()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a = randNum1;
		b = randNum2;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Comparing Numbers " << randNum1 << " and " << randNum2 << std::endl;

		if ((a < b) == (randNum1 < randNum2))
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntNotEqualComparisonOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator!=()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a = randNum1;
		b = randNum2;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;

		if (a != randNum2)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntEqualComparisonOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator==()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);

		trialCount++;

		a = randNum1;
		b = randNum1;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;

		if (a == randNum1)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntAdditionAssessmentOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator+=()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a = randNum1;
		std::string correctStr = std::to_string(randNum1 + randNum2);

		a += randNum2;
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntSubtractionAssessmentOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator-=()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a = randNum1;
		std::string correctStr = std::to_string(randNum1 - randNum2);



		a -= randNum2;
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntPostfixIncrementOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator++()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a.SetInteger(randNum1);
		std::string randNum1Str = std::to_string(randNum1);
		randNum1++;
		std::string correctStr = std::to_string(randNum1);



		a++;
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntPrefixDecrementOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator--()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a.SetInteger(randNum1);
		std::string randNum1Str = std::to_string(randNum1);
		std::string correctStr = std::to_string(--randNum1);



		--a;
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntPostfixDecrementOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator--()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a.SetInteger(randNum1);
		std::string randNum1Str = std::to_string(randNum1);
		randNum1--;
		std::string correctStr = std::to_string(randNum1);

		a--;
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntPrefixIncrementOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator++()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		a.SetInteger(randNum1);
		std::string randNum1Str = std::to_string(randNum1);
		std::string correctStr = std::to_string(++randNum1);
		

		
		++a;
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntAssignmentOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator=()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);

		trialCount++;

		a = randNum1;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << randNum1 << std::endl;
		std::cout << "Computed Answer: " << a << std::endl;

		if (a == randNum1)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntAdditionOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator+()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		std::string correctStr = std::to_string(randNum1 + randNum2);
		std::string randNum1Str = std::to_string(randNum1);

		a.SetInteger(randNum1);
		BigInteger temp = a + randNum2;
		std::string ans = temp.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr && a.GetInteger() == randNum1Str)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntSubtractionOperator(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER operator-()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		std::string correctStr = std::to_string(randNum1 - randNum2);
		std::string randNum1Str = std::to_string(randNum1);

		a.SetInteger(randNum1);
		BigInteger temp = a - randNum2;
		std::string ans = temp.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr && a.GetInteger() == randNum1Str)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntAdd(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER ADD()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{
		BigInteger temp;
		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		std::string correctStr = std::to_string(randNum1 + randNum2);
		std::string randNum1Str = std::to_string(randNum1);
		std::string randNum2Str = std::to_string(randNum2);

		a.SetInteger(randNum1Str);
		temp = a.Add(randNum2Str);
		std::string ans = temp.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr && a.GetInteger() == randNum1Str)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;


}

void Testing::TestingBigIntSub(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER SUBTOTHIS()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		BigInteger temp;
		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		std::string correctStr = std::to_string(randNum1 - randNum2);
		std::string randNum1Str = std::to_string(randNum1);
		std::string randNum2Str = std::to_string(randNum2);

		a.SetInteger(randNum1Str);
		temp = a.Sub(randNum2Str);
		std::string ans = temp.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr && a.GetInteger() == randNum1Str)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntAddToThis(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER ADDTOTHIS()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		std::string correctStr = std::to_string(randNum1 + randNum2);
		std::string randNum1Str = std::to_string(randNum1);
		std::string randNum2Str = std::to_string(randNum2);

		a.SetInteger(randNum1Str);
		a.AddToThis(randNum2Str);
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

}

void Testing::TestingBigIntSubToThis(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN / 2, INT_MAX / 2);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER SUBTOTHIS()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{

		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;
		
		std::string correctStr = std::to_string(randNum1 - randNum2);
		std::string randNum1Str = std::to_string(randNum1);
		std::string randNum2Str = std::to_string(randNum2);

		a.SetInteger(randNum1Str);
		a.SubToThis(randNum2Str);
		std::string ans = a.GetInteger();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << "Correct Answer: " << correctStr << std::endl;
		std::cout << "Computed Answer: " << ans << std::endl;

		if (ans == correctStr)
		{

			std::cout << "PASSED" << std::endl;
			passCount++;

		}
		else
		{

			std::cout << "FAILED" << std::endl;
			if (stopOnFail)
			{

				break;

			}

		}

	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Passed: " << passCount << std::endl;
	std::cout << "Trials: " << trialCount << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

}
