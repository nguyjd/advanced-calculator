#include "testing.h"

Testing::Testing()
{

	passCount = 0;
	trialCount = 0;

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
		int randNum2 = distrib(gen);

		trialCount++;

		std::string correctStr = std::to_string(randNum1);
		std::string randNum1Str = std::to_string(randNum1);

		a.SetInteger(randNum1);
		BigInteger temp = a;
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
