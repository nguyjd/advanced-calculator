#include "testing.h"

Testing::Testing()
{

	passCount = 0;
	trialCount = 0;

}

void Testing::TestingBigIntMathTiming(int trialsCount, bool isRandom)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<long long int> distrib(LLONG_MIN, LLONG_MAX);
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
	std::chrono::microseconds divideTotalTime = std::chrono::microseconds::zero();

	BigInteger add;
	BigInteger sub;
	BigInteger multi;
	BigInteger divide;

	if (isRandom)
	{

		std::cout << "Running the Timing Trials (Random Number)" << std::endl;
		for (int i = 0; i < trialsCount; i++)
		{

			std::cout << "Running Trial " << i << std::endl;

			long long int randNum1 = distrib(gen);
			long long int randNum2 = distrib(gen);
			std::string randNum2Str = std::to_string(randNum2) + "191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834191283709127098471092819783648712638947612938764189764123843126812347681972634987612398763421698713283476863784267831297683967849367842169784367891324967836927814961783246879134869714326879132468971324689713248967132648791893247668719342687123467891234687913246879132468791324689734714327869867913249687134269877328736498176239847612647162767893127968678149239786416287683419128370912709847109281978364871263894761293876418976412384312681234768197263498761239876342169871328347686378426783129768396784936784216978436789132496783692781496178324687913486971432687913246897132468971324896713264879189324766871934268712346789123468791324687913246879132468973471432786986791324968713426987732873649817623984761264716276789312796867814923978641628768341912837091270984710928197836487126389476129387641897641238431268123476819726349876123987634216987132834768637842678312976839678493678421697843678913249678369278149617832468791348697143268791324689713246897132489671326487918932476687193426871234678912346879132468791324687913246897347143278698679132496871342698773287364981762398476126471627678931279686781492397864162876834";

			trialCount++;

			add = randNum1;
			sub = randNum1;
			multi = randNum1;
			divide = randNum1;

			auto addStartTime = std::chrono::steady_clock::now();
			add.AddToThis(randNum2Str);
			auto addStopTime = std::chrono::steady_clock::now();

			auto subStartTime = std::chrono::steady_clock::now();
			sub.SubToThis(randNum2Str);
			auto subStopTime = std::chrono::steady_clock::now();

			auto multiStartTime = std::chrono::steady_clock::now();
			multi.MultiplyToThis(randNum2Str);
			auto multiStopTime = std::chrono::steady_clock::now();

			auto divideStartTime = std::chrono::steady_clock::now();
			divide.DivideToThis(randNum2Str);
			auto divideStopTime = std::chrono::steady_clock::now();

			addTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(addStopTime - addStartTime);
			subTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(subStopTime - subStartTime);
			multiTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(multiStopTime - multiStartTime);
			divideTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(divideStopTime - divideStartTime);

			std::cout << "Trial " << i << " completed." << std::endl;
			std::cout << std::endl;

		}

	}
	else
	{

		std::cout << "Running the Timing Trials (Based on trial numbers)" << std::endl;
		for (int i = 0; i < trialsCount; i++)
		{

			std::cout << "Running Trial " << i << std::endl;

			long long int randNum1 = distrib(gen);
			std::string randNum2Str = std::to_string(i);

			trialCount++;

			add = randNum1;
			sub = randNum1;
			multi = randNum1;
			divide = randNum1;

			auto addStartTime = std::chrono::steady_clock::now();
			add.AddToThis(randNum2Str);
			auto addStopTime = std::chrono::steady_clock::now();

			auto subStartTime = std::chrono::steady_clock::now();
			sub.SubToThis(randNum2Str);
			auto subStopTime = std::chrono::steady_clock::now();

			auto multiStartTime = std::chrono::steady_clock::now();
			multi.MultiplyToThis(randNum2Str);
			auto multiStopTime = std::chrono::steady_clock::now();

			auto divideStartTime = std::chrono::steady_clock::now();
			divide.DivideToThis(randNum2Str);
			auto divideStopTime = std::chrono::steady_clock::now();

			addTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(addStopTime - addStartTime);
			subTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(subStopTime - subStartTime);
			multiTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(multiStopTime - multiStartTime);
			divideTotalTime += std::chrono::duration_cast<std::chrono::microseconds>(divideStopTime - divideStartTime);

			std::cout << "Trial " << i << " completed." << std::endl;
			std::cout << std::endl;

		}

	}

	



	if (trialsCount > 0)
	{

		addTotalTime /= trialsCount;
		subTotalTime /= trialsCount;
		multiTotalTime /= trialsCount;
		divideTotalTime /= trialsCount;

	}
	

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test Results: " << std::endl;
	std::cout << "Adding Time Average: " << addTotalTime.count() << " microseconds" << std::endl;
	std::cout << "Subtracing Time Average: " << subTotalTime.count() << " microseconds" << std::endl;
	std::cout << "Multiplying(Long) Time Average: " << multiTotalTime.count() << " microseconds" << std::endl;
	std::cout << "Dividing(Long) Time Average: " << divideTotalTime.count() << " microseconds" << std::endl;

	std::cout << "---------------------TESTING COMPLETED----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;

	std::cin >> x;

}

void Testing::TestingBigIntMultiplication(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN, INT_MAX);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER MultiplyToThis()----------------------" << std::endl;
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

		a.MultiplyToThis(std::to_string(randNum2));

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

void Testing::TestingBigIntDivisionRandom(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN, INT_MAX);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER DivideToThis() Random----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 0; i < trialsCount; i++)
	{
		BigInteger temp;
		int randNum1 = distrib(gen);
		int randNum2 = distrib(gen);

		trialCount++;

		long long int correctAns = static_cast<long long int>(randNum1) / static_cast<long long int>(randNum2);

		a = randNum1;

		a.DivideToThis(std::to_string(randNum2));

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << randNum1 << " / " << randNum2 << std::endl;
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

void Testing::TestingBigIntDivision(int trialsCount, bool stopOnFail)
{

	std::string x;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(INT_MIN, INT_MAX);
	passCount = 0;
	trialCount = 0;

	std::cout << "---------------------TESTING BIG INTEGER DivideToThis()----------------------" << std::endl;
	std::cout << "Enter any character into the console to continue." << std::endl;
	std::cin >> x;

	for (int i = 1; i <= trialsCount; i++)
	{
		BigInteger temp;
		int randNum1 = distrib(gen);

		trialCount++;

		long long int correctAns = static_cast<long long int>(randNum1) / static_cast<long long int>(i);

		a = randNum1;

		a.DivideToThis(std::to_string(i));

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Trial " << trialCount << ": " << std::endl;
		std::cout << randNum1 << " / " << i << std::endl;
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
