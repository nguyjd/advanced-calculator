#include "biginteger.h"

BigInteger::BigInteger()
{

	/**
	* The positive does not matter
	* However the validNumber must be zero
	* So a function does not try to work on a empty array.
	*/
	positive = true;
	validNumber = false;

}

BigInteger::BigInteger(const std::string number)
{

	/**
	* The positive does not still does not matter
	* The correct value for positive will be set by SetInteger()
	*/
	positive = true;
	validNumber = SetInteger(number);

}

BigInteger::BigInteger(const char number)
{

	/**
	* The positive does not still does not matter
	* The correct value for positive will be set by SetInteger()
	*/
	positive = true;
	validNumber = SetInteger(number);

}

BigInteger::BigInteger(const int number)
{

	/**
	* The positive does not still does not matter
	* The correct value for positive will be set by SetInteger()
	*/
	positive = true;
	validNumber = SetInteger(number);

}

BigInteger::BigInteger(const long number)
{

	/**
	* The positive does not still does not matter
	* The correct value for positive will be set by SetInteger()
	*/
	positive = true;
	validNumber = SetInteger(number);

}

BigInteger::BigInteger(const long long number)
{

	/**
	* The positive does not still does not matter
	* The correct value for positive will be set by SetInteger()
	*/
	positive = true;
	validNumber = SetInteger(number);

}

BigInteger::BigInteger(const BigInteger& number)
{

	validNumber = number.validNumber;
	positive = number.positive;
	strInteger = number.strInteger;
	integer = number.integer;

}

bool BigInteger::SetInteger(const std::string number)
{

	/** Checks the number for bad characters */
	validNumber = VerifyNumber(number);
	if (validNumber)
	{

		/** Sets all the values to store it within the object */
		strInteger = number;
		ConvertStringToBigInteger(strInteger, integer, positive);
		CleanUpNumber(integer);
		return true;

	}

	/** Returns false if the number failed to validate. */
	return false;
}

bool BigInteger::SetInteger(const char number)
{

	return SetInteger(std::string(1, number));

}

bool BigInteger::SetInteger(const int number)
{

	return SetInteger(std::to_string(number));

}

bool BigInteger::SetInteger(const long number)
{

	return SetInteger(std::to_string(number));

}

bool BigInteger::SetInteger(const long long number)
{

	return SetInteger(std::to_string(number));

}

bool BigInteger::IsIntegerPositive()
{

	/** Return the sign of the number */
	return positive;

}

std::string BigInteger::GetInteger()
{

	/** Make sure that the number is valid to convert to string. */
	if (validNumber)
	{

		/** Convert the number to a string and return the string. */
		ConvertBigIntegerToString(strInteger, integer, positive);
		return strInteger;

	}

	/** Return a message the the number is invalid. */
	return "Invalid Number";

}

void BigInteger::AddToThis(const std::string number)
{

	/** The local arrays used for computation */
	std::deque<char> firstNumber = integer;
	std::deque<char> secondNumber;
	bool secondNumberPositive = true;

	/** Check to ensure that both numbers are valid. */
	if (!VerifyNumber(number) || !VerifyNumber(strInteger))
	{ 
		
		std::cout << "Invalid number to add." << std::endl;
		return;
		
	}

	/** Convert the string into something usable. */
	ConvertStringToBigInteger(number, secondNumber, secondNumberPositive);

	/**
	* A trick to handle the internal number being negitive.
	* The trick is from simple algebra, converting the first number to positive.
	*/
	bool invertSign = false;
	if (!positive)
	{

		/** Flip all the signs in the equation */
		invertSign = true;
		positive = !positive;
		secondNumberPositive = !secondNumberPositive;


	}

	/** If the second number is negitive, then the equation can be treated as a subtraction. */
	if (!secondNumberPositive)
	{

		/** Remove the minus from the string. */
		std::string temp = number;
		if (!invertSign)
		{

			temp.erase(temp.begin());

		}

		/** Start the addition */
		SubToThis(temp);

		/** Invert the sign of the number. */
		if (invertSign)
		{

			positive = !positive;

		}

		/** Exit the function */
		return;

	}

	/** This will set the first number to the largest number. */
	if (firstNumber.size() < secondNumber.size())
	{

		/** Swap the numbers. */
		std::deque<char> tempDeque = secondNumber;
		secondNumber = firstNumber;
		firstNumber = tempDeque;

	}

	char sum = 0;
	char carry = 0;
	integer.clear();
	std::deque<char>::const_reverse_iterator firstNumberPtr = firstNumber.crbegin();
	std::deque<char>::const_reverse_iterator secondNumberPtr = secondNumber.crbegin();
	
	/** Add the smallest number to the larger number */
	while (secondNumberPtr != secondNumber.crend())
	{

		sum = (*secondNumberPtr + *firstNumberPtr + carry);
		integer.push_front(sum % 10);
		carry = sum / 10;

		firstNumberPtr++;
		secondNumberPtr++;

	}

	/** Carry the number until there is nothing to carry or you are a end of the larger number */
	while (carry != 0 && firstNumberPtr != firstNumber.crend())
	{

		sum = (*firstNumberPtr + carry);
		integer.push_front(sum % 10);
		carry = sum / 10;

		firstNumberPtr++;

	}

	/** Fill the array with the remaining digits missing. */
	while (firstNumberPtr != firstNumber.crend())
	{

		integer.push_front(*firstNumberPtr);

		firstNumberPtr++;

	}

	/** If there is a carry left, attach it to the front of the number. */
	if (carry != 0)
	{

		integer.push_front(carry);

	}

	/** Invert the sign of the internal number */
	if (invertSign)
	{

		positive = !positive;

	}

	/** Remove the leading zero if there are any. */
	CleanUpNumber(integer);

	/** Update the stored string */
	ConvertBigIntegerToString(strInteger, integer, positive);

}

void BigInteger::AddToThis(BigInteger number)
{

	/** Get the string and feed it to the other function */
	AddToThis(number.GetInteger());

}

void BigInteger::AddToThis(char number)
{

	/** Convert to string and pass it to the main function. */
	AddToThis(std::string(1, number));

}

void BigInteger::AddToThis(int number)
{

	/** Convert to string and pass it to the main function. */
	AddToThis(std::to_string(number));

}

void BigInteger::AddToThis(long number)
{

	/** Convert to string and pass it to the main function. */
	AddToThis(std::to_string(number));

}

void BigInteger::AddToThis(long long number)
{

	/** Convert to string and pass it to the main function. */
	AddToThis(std::to_string(number));

}

BigInteger BigInteger::Add(const std::string number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the addition */
	tempBigInt.AddToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Add(BigInteger number)
{

	/** Get the string and feed it to the other function */
	return Add(number.GetInteger());

}

BigInteger BigInteger::Add(char number)
{

	/** Convert to string and pass it to the main function. */
	return Add(std::string(1, number));

}

BigInteger BigInteger::Add(int number)
{

	/** Convert to string and pass it to the main function. */
	return Add(std::to_string(number));

}

BigInteger BigInteger::Add(long number)
{

	/** Convert to string and pass it to the main function. */
	return Add(std::to_string(number));

}

BigInteger BigInteger::Add(long long number)
{

	/** Convert to string and pass it to the main function. */
	return Add(std::to_string(number));

}

void BigInteger::SubToThis(const std::string number)
{
	
	/** The local arrays used for computation */
	std::deque<char> firstNumber = integer;
	std::deque<char> secondNumber;
	bool secondNumberPositive = true;

	/** Check to ensure that both numbers are valid. */
	if (!VerifyNumber(number) || !VerifyNumber(strInteger))
	{

		std::cout << "Invalid number to subtract." << std::endl;
		return;

	}

	/** Convert the string into something usable. */
	ConvertStringToBigInteger(number, secondNumber, secondNumberPositive);

	/** 
	* A trick to handle the internal number being negitive. 
	* The trick is from simple algebra, converting the first number to positive.
	*/
	bool invertSign = false;
	if (!positive)
	{

		/** Flip all the signs in the equation */
		invertSign = true;
		positive = !positive;
		secondNumberPositive = !secondNumberPositive;


	}

	/** If the second number is negitive, then the equation can be treated as a addition. */
	if (!secondNumberPositive)
	{

		/** Remove the minus from the string. */
		std::string temp = number;
		if (!invertSign)
		{

			temp.erase(temp.begin());

		}

		/** Start the addition */
		AddToThis(temp);

		/** Invert the sign of the number. */
		if (invertSign)
		{

			positive = !positive;

		}

		/** Exit the function */
		return;

	}
	
	/** Start the addition */
	if (!positive)
	{

		AddToThis(number);
		return;

	}

	/** This will set the first array to the largest number. */
	if (firstNumber.size() < secondNumber.size())
	{

		/** 
		* Swap the numbers.
		* Declare the result negative. 
		*/
		std::deque<char> tempDeque = secondNumber;
		secondNumber = firstNumber;
		firstNumber = tempDeque;
		positive = false;

	}
	/** This will check step by step each number to find the larger number. */
	else if (firstNumber.size() == secondNumber.size())
	{

		/** look at the number at the front to determine the larger number. */
		std::deque<char>::const_iterator firstNumberPtr = firstNumber.cbegin();
		std::deque<char>::const_iterator secondNumberPtr = secondNumber.cbegin();

		while (firstNumberPtr != firstNumber.cend())
		{

			/** The second array is the larger number. */
			if (*firstNumberPtr < *secondNumberPtr)
			{

				/**
				* Swap the numbers.
				* Declare the result negative.
				*/
				std::deque<char> tempDeque = secondNumber;
				secondNumber = firstNumber;
				firstNumber = tempDeque;
				positive = false;

				/** Break out of the loop. */
				break;

			}
			/** The first array is already the larger number. */
			else if (*firstNumberPtr > *secondNumberPtr)
			{

				/** Break out of the loop. */
				break;

			}

			/** Increment the Iterator */
			firstNumberPtr++;
			secondNumberPtr++;

		}

	}

	/** Local vars to hold the values */
	char differnce = 0;
	char carry = 0;

	/** Clear the array */
	integer.clear();

	/** Get the iterator starting from the end. */
	std::deque<char>::const_reverse_iterator firstNumberPtr = firstNumber.crbegin();
	std::deque<char>::const_reverse_iterator secondNumberPtr = secondNumber.crbegin();
	while (secondNumberPtr != secondNumber.crend())
	{

		/** Test if we need to carry a number. */
		if (*firstNumberPtr < (*secondNumberPtr + carry))
		{

			differnce = (*firstNumberPtr + 10 - (*secondNumberPtr + carry));
			carry = 1;

		}
		else
		{

			differnce = (*firstNumberPtr - (*secondNumberPtr + carry));
			carry = 0;

		}

		/** Add the digit to the array. */
		integer.push_front(differnce);

		/** Increment the Iterator */
		firstNumberPtr++;
		secondNumberPtr++;

	}

	/** Process the rest of the digits */
	while (firstNumberPtr != firstNumber.crend())
	{

		/** Continue to subtract due to the carry. */
		if (carry == 1)
		{

			/** Check if we need a addition carry. */
			if (*firstNumberPtr < carry)
			{

				integer.push_front(*firstNumberPtr + 10 - carry);
				carry = 1;

			}
			else
			{

				integer.push_front(*firstNumberPtr - carry);
				carry = 0;

			}

		}
		else
		{

			/** Fill the array with the rest of the digits. */
			integer.push_front(*firstNumberPtr);

		}

		firstNumberPtr++;

	}

	/** Invert the sign of the internal number */
	if (invertSign)
	{

		positive = !positive;

	}

	/** Remove the leading zero if there are any. */
	CleanUpNumber(integer);

	/** Update the stored string */
	ConvertBigIntegerToString(strInteger, integer, positive);

}

void BigInteger::SubToThis(BigInteger number)
{

	/** Get the string and feed it to the other function */
	SubToThis(number.GetInteger());

}

void BigInteger::SubToThis(char number)
{

	/** Convert to string and pass it to the main function. */
	SubToThis(std::string(1, number));

}

void BigInteger::SubToThis(int number)
{

	/** Convert to string and pass it to the main function. */
	SubToThis(std::to_string(number));

}

void BigInteger::SubToThis(long number)
{

	/** Convert to string and pass it to the main function. */
	SubToThis(std::to_string(number));

}

void BigInteger::SubToThis(long long number)
{

	/** Convert to string and pass it to the main function. */
	SubToThis(std::to_string(number));

}

BigInteger BigInteger::Sub(const std::string number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the Subtraction */
	tempBigInt.SubToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Sub(BigInteger number)
{

	/** Get the string and feed it to the other function */
	return Sub(number.GetInteger());

}

BigInteger BigInteger::Sub(char number)
{

	/** Convert to string and pass it to the main function. */
	return Sub(std::string(1, number));

}

BigInteger BigInteger::Sub(int number)
{

	/** Convert to string and pass it to the main function. */
	return Sub(std::to_string(number));

}

BigInteger BigInteger::Sub(long number)
{

	/** Convert to string and pass it to the main function. */
	return Sub(std::to_string(number));

}

BigInteger BigInteger::Sub(long long number)
{

	/** Convert to string and pass it to the main function. */
	return Sub(std::to_string(number));

}

BigInteger& BigInteger::operator=(BigInteger num)
{

	std::swap(validNumber, num.validNumber);
	std::swap(positive, num.positive);
	std::swap(strInteger, num.strInteger);
	std::swap(integer, num.integer);

	return *this;

}

BigInteger BigInteger::operator+(const BigInteger& num)
{

	return Add(num);

}

BigInteger BigInteger::operator-(const BigInteger& num)
{
	return Sub(num);
}

BigInteger BigInteger::operator*(const BigInteger& num)
{

	return Multiply(num);

}

BigInteger BigInteger::operator/(const BigInteger& num)
{

	return Divide(num);

}

BigInteger BigInteger::operator%(const BigInteger& num)
{

	return Modulus(num);

}

BigInteger BigInteger::operator*=(const BigInteger& num)
{

	MultiplyToThis(num);

	return *this;

}

BigInteger BigInteger::operator/=(const BigInteger& num)
{

	DivideToThis(num);

	return *this;

}

BigInteger BigInteger::operator%=(const BigInteger& num)
{

	ModulusToThis(num);

	return *this;

}

BigInteger& BigInteger::operator++()
{

	AddToThis("1");

	return *this;

}

BigInteger BigInteger::operator++(int)
{

	BigInteger temp = *this;
	++* this;

	return temp;

}

BigInteger& BigInteger::operator--()
{
	SubToThis("1");

	return *this;
}

BigInteger BigInteger::operator--(int)
{

	BigInteger temp = *this;
	--* this;

	return temp;

}

BigInteger& BigInteger::operator+=(const BigInteger& rhs)
{
	
	AddToThis(rhs);

	return *this;

}

BigInteger& BigInteger::operator-=(const BigInteger& rhs)
{
	
	SubToThis(rhs);

	return *this;

}

bool BigInteger::operator==(const BigInteger& num)
{

	return this->integer == num.integer && this->strInteger == num.strInteger 
		&& this->positive == num.positive && this->validNumber == num.validNumber;

}

bool BigInteger::operator!=(const BigInteger& num)
{
	return !(*this == num);
}

bool BigInteger::operator<(const BigInteger& num)
{

	bool lhsPositive = this->positive;
	bool rhsPositive = num.positive;
	std::deque<char> lhsNum = this->integer;
	std::deque<char> rhsNum = num.integer;

	if (lhsNum.size() < rhsNum.size())
	{

		if (!rhsPositive)
		{

			return false;

		}

		return true;

	}
	/** This will check step by step each number to find the larger number. */
	else if (lhsNum.size() == rhsNum.size())
	{

		/** look at the number at the front to determine the larger number. */
		std::deque<char>::const_iterator lhsNumPtr = lhsNum.cbegin();
		std::deque<char>::const_iterator rhsNumPtr = rhsNum.cbegin();

		while (lhsNumPtr != lhsNum.cend())
		{

			/** The second array is the larger number. */
			if (*lhsNumPtr < *rhsNumPtr)
			{

				if (rhsPositive)
				{

					return true;

				}

				return false;
				

			}
			/** The first array is already the larger number. */
			else if (*lhsNumPtr > *rhsNumPtr)
			{

				if (!lhsPositive)
				{

					return true;

				}

				return false;

			}

			/** Increment the Iterator */
			lhsNumPtr++;
			rhsNumPtr++;

		}

		return false;

	}

	if (!lhsPositive)
	{

		return true;

	}

	return false;
}

bool BigInteger::operator>(const BigInteger& num)
{

	return !(*this < num) && *this != num;

}

bool BigInteger::operator>=(const BigInteger& num)
{

	return *this > num || *this == num;

}

bool BigInteger::operator<=(const BigInteger& num)
{

	return *this < num || *this == num;

}

bool BigInteger::VerifyNumber(const std::string number)
{

	/** Checks the length of the number. */
	if (number.length() == 0)
	{

		return false;

	}

	/** Checks each character */
	for (char character : number)
	{

		if ((character < '0' || character > '9') && character != '-')
		{

			/** Quit out if a non valid character is found. */
			std::cout << "Invalid character detected." << std::endl;
			return false;

		}

	}

	/** Return true if nothing detect it from being invalid. */
	return true;
}

void BigInteger::ConvertStringToBigInteger(const std::string numStr, std::deque<char>& numVec, bool &positive)
{

	/** Clear the deque */
	numVec.clear();

	/** Test for the sign of the number. */
	(numStr[0] == '-') ? positive = false : positive = true;

	
	/** Filled the array with the numbers from the string. */
	for (char character : numStr)
	{

		if (character >= '0' && character <= '9')
		{ 
		
			numVec.push_back(character - ASCIIOFFSET);

		}

	}

	/** Remove the leading zero if there are any. */
	CleanUpNumber(numVec);

}

void BigInteger::ConvertBigIntegerToString(std::string& numStr, const std::deque<char> numVec, const bool positive)
{
	
	/** Clear the string */
	numStr.clear();

	/** Add the negitive sign. */
	if (!positive)
	{

		numStr.push_back('-');

	}

	/** Append the character to the string. */
	for (char digit : numVec)
	{
	
		numStr.push_back(digit + ASCIIOFFSET);

	}

}

void BigInteger::CleanUpNumber(std::deque<char>& numVec)
{

	/** Check if the deque is valid */
	if (numVec.empty()) { return; }

	/** Get the beginning of the deque */
	std::deque<char>::iterator numIt = numVec.begin();

	/** Loop until there is only on digit left. */
	while (numIt != (numVec.end() - 1))
	{

		/** Check for the leading zero */
		if (*numIt == 0)
		{

			/** Remove the zero */
			numVec.pop_front();
			numIt = numVec.begin();

		}
		else
		{

			/** If there is any number expect a zero, exit the loop. */
			break;

		}

	}

	/** Update the string. */
	ConvertBigIntegerToString(strInteger, integer, positive);

}

BigInteger BigInteger::LongMultiplyThread(std::deque<char> firstNum, char digit, unsigned long long int place)
{
	
	/** A temp object to hold the multiplied value in order to avoid a data race. */
	BigInteger returnInt;

	/** Holds the value of the multiplication */
	char product = 0;
	char carry = 0;
	
	/** Extends the digits based off the digit position it was in the array. */
	for (unsigned long long int i = 0; i < place; i++)
	{

		returnInt.integer.push_front(0);

	}
	
	/** Does the multiplication */
	std::deque<char>::const_reverse_iterator firstNumberPtr = firstNum.crbegin();
	while (firstNumberPtr != firstNum.crend())
	{

		product = digit * *firstNumberPtr + carry;
		returnInt.integer.push_front(product % 10);
		carry = product / 10;

		firstNumberPtr++;

	}

	/** Append the carry the front of the number if there is a carry left. */
	if (carry != 0)
	{

		returnInt.integer.push_front(carry);

	}

	/** Update the string in the object. */
	ConvertBigIntegerToString(returnInt.strInteger, returnInt.integer, returnInt.positive);

	/** Makes sure the number is valid. */
	returnInt.validNumber = returnInt.VerifyNumber(returnInt.strInteger);

	return returnInt;
}

void BigInteger::MultiplyToThis(const std::string number)
{

	/** The local arrays used for computation */
	std::deque<char> secondNumber;
	bool firstNumberPositive = positive;
	bool secondNumberPositive = true;

	/** Check to ensure that both numbers are valid. */
	if (!VerifyNumber(number) || !VerifyNumber(strInteger))
	{

		std::cout << "Invalid number to multiply." << std::endl;
		return;

	}

	/** Convert the string into something usable. */
	ConvertStringToBigInteger(number, secondNumber, secondNumberPositive);

	/** This will set the first number to the largest number. */
	if (integer.size() < secondNumber.size())
	{

		/** Swap the numbers. */
		std::deque<char> tempDeque = secondNumber;
		secondNumber = integer;
		integer = tempDeque;

	}

	/** Counts the digits place in base 10 */
	unsigned long long int counter = 0;

	/** Holds all the values from the threads made. */
	std::deque<std::future<BigInteger>> futures;
	std::deque<char>::const_reverse_iterator secondNumberPtr = secondNumber.crbegin();
	while (secondNumberPtr != secondNumber.crend())
	{

		/** Skip multiplying by 0 */
		if (*secondNumberPtr == 0)
		{

			/** Increment the iterator and digits place. */
			counter++;
			secondNumberPtr++;
			continue;

		}
		
		/** Create the thread to multiply the array with a single digit. */
		futures.push_back(std::async(std::launch::async, &BigInteger::LongMultiplyThread, this, integer, *secondNumberPtr, counter));

		/** Increment the iterator and digits place. */
		counter++;
		secondNumberPtr++;

	}

	/** Set the array to zero so we can add all the values from the threads. */
	*this = 0;

	/** Get all the values from the threads and add it to the array. */
	for (auto& future : futures)
	{

		*this += future.get();

	}

	/** Determine the sign for the number. */
	if (secondNumberPositive != firstNumberPositive)
	{

		positive = false;

	}
	else
	{

		positive = true;

	}

	/** Remove the leading zero if there are any. */
	CleanUpNumber(integer);

	/** Update the stored string */
	ConvertBigIntegerToString(strInteger, integer, positive);

}

void BigInteger::MultiplyToThis(BigInteger number)
{

	/** Get the string and feed it to the other function */
	MultiplyToThis(number.GetInteger());

}

void BigInteger::MultiplyToThis(char number)
{

	/** Convert to string and pass it to the main function. */
	MultiplyToThis(std::string(1, number));

}

void BigInteger::MultiplyToThis(int number)
{

	/** Convert to string and pass it to the main function. */
	MultiplyToThis(std::to_string(number));

}

void BigInteger::MultiplyToThis(long number)
{

	/** Convert to string and pass it to the main function. */
	MultiplyToThis(std::to_string(number));

}

void BigInteger::MultiplyToThis(long long number)
{

	/** Convert to string and pass it to the main function. */
	MultiplyToThis(std::to_string(number));

}

BigInteger BigInteger::Multiply(const std::string number)
{
	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the multiplication */
	tempBigInt.MultiplyToThis(number);

	return tempBigInt;
}

BigInteger BigInteger::Multiply(BigInteger number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the multiplication */
	tempBigInt.MultiplyToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Multiply(char number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the multiplication */
	tempBigInt.MultiplyToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Multiply(int number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the multiplication */
	tempBigInt.MultiplyToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Multiply(long number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the multiplication */
	tempBigInt.MultiplyToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Multiply(long long number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the multiplication */
	tempBigInt.MultiplyToThis(number);

	return tempBigInt;

}

void BigInteger::DivideToThis(const std::string number)
{

	BigInteger dividend = *this;
	BigInteger divisor = number;
	bool firstNumberPositive = dividend.positive;
	bool secondNumberPositive = divisor.positive;

	/** Check to ensure that both numbers are valid. */
	if (!VerifyNumber(number) || !VerifyNumber(strInteger))
	{

		std::cout << "Invalid number to divide." << std::endl;
		return;

	}

	/** Set both of the number to positive*/
	dividend.positive = true;
	divisor.positive = true;

	/** Check to see if the divisor is 0. */
	if (divisor == 0)
	{

		std::cout << "Invalid number to divide. (Tried to divide by zero)" << std::endl;
		return;

	}

	/** Optimizing the code. */
	/** Check to see if the divisor is 1. */
	if (divisor == 1)
	{

		return;

	}

	/** Optimizing the code. */
	/** Return zero due to intger division */
	if (dividend < divisor)
	{

		*this = 0;
		return;

	}
	else if (dividend == divisor)
	{

		*this = 1;
		return;

	}

	/** Multiply the divisor so the amount of digits are the same.*/
	unsigned long long int amountofUnprocessedDigits = dividend.integer.size() - divisor.integer.size();
	for (unsigned long long int i = 0; i < amountofUnprocessedDigits; i++)
	{

		divisor.integer.push_back(0);

	}

	/** Divide until there is no more digits left to process. */
	char lastQuotientDigit = 0;
	integer.clear();
	while (amountofUnprocessedDigits >= 0)
	{

		/** Pop back the array and add the quotient digit to the array. */
		if (dividend < divisor)
		{

			integer.push_back(lastQuotientDigit);
			divisor.integer.pop_back();
			lastQuotientDigit = 0;

			/** Break out of the loop when there is no more digits to process. */
			if (amountofUnprocessedDigits == 0) { break; }

			amountofUnprocessedDigits--;
			continue;

		}

		/** Subtract by the divisor. */
		dividend -= divisor;
		lastQuotientDigit++;

	}	

	/** Determine the sign for the number. */
	if (secondNumberPositive != firstNumberPositive)
	{

		positive = false;

	}
	else
	{

		positive = true;

	}

	/** Remove the leading zero if there are any. */
	CleanUpNumber(integer);

	/** Update the stored string */
	ConvertBigIntegerToString(strInteger, integer, positive);

}

void BigInteger::DivideToThis(BigInteger number)
{

	/** Get the string and feed it to the other function */
	DivideToThis(number.GetInteger());

}

void BigInteger::DivideToThis(char number)
{

	/** Convert to string and pass it to the main function. */
	DivideToThis(std::string(1, number));

}

void BigInteger::DivideToThis(int number)
{

	/** Convert to string and pass it to the main function. */
	DivideToThis(std::to_string(number));

}

void BigInteger::DivideToThis(long number)
{

	/** Convert to string and pass it to the main function. */
	DivideToThis(std::to_string(number));

}

void BigInteger::DivideToThis(long long number)
{

	/** Convert to string and pass it to the main function. */
	DivideToThis(std::to_string(number));

}

BigInteger BigInteger::Divide(const std::string number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Divide(BigInteger number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Divide(char number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Divide(int number)
{
	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;
}

BigInteger BigInteger::Divide(long number)
{
	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;
}

BigInteger BigInteger::Divide(long long number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

void BigInteger::ModulusToThis(const std::string number)
{

	/** Uses almost the same code as divide */
	BigInteger divisor = number;

	/** Check to ensure that both numbers are valid. */
	if (!VerifyNumber(number) || !VerifyNumber(strInteger))
	{

		std::cout << "Invalid number to divide." << std::endl;
		return;

	}

	/** Set both of the number to positive*/
	bool isPositive = positive;
	positive = true;
	divisor.positive = true;

	/** Check to see if the divisor is 0. */
	if (divisor == 0)
	{

		std::cout << "Invalid number to divide. (Tried to divide by zero)" << std::endl;
		std::cout << "Could not find the modulus." << std::endl;
		return;

	}

	/** Optimizing the code. */
	/** Check to see if the divisor is 1. */
	if (divisor == 1)
	{

		*this = 0;
		return;

	}

	/** Optimizing the code. */
	/** Return zero due to intger division */
	if (*this < divisor)
	{

		positive = isPositive;
		return;

	}
	else if (*this == divisor)
	{

		*this = 0;
		return;

	}

	/** Multiply the divisor so the amount of digits are the same. */
	unsigned long long int amountofUnprocessedDigits = integer.size() - divisor.integer.size();
	for (unsigned long long int i = 0; i < amountofUnprocessedDigits; i++)
	{

		divisor.integer.push_back(0);

	}

	/** Divide until there is no more digits left to process. */
	while (amountofUnprocessedDigits >= 0)
	{

		/** Pop back the array */
		if (*this < divisor)
		{

			divisor.integer.pop_back();

			/** Break out of the loop when there is no more digits to process. */
			if (amountofUnprocessedDigits == 0) { break; }

			amountofUnprocessedDigits--;
			continue;

		}

		/** Subtract by the divisor. */
		*this -= divisor;

	}

	/** Add the minus sign if the number is not zero. */
	if (*this != 0)
	{

		positive = isPositive;

	}

	/** Remove the leading zero if there are any. */
	CleanUpNumber(integer);

	/** Update the stored string */
	ConvertBigIntegerToString(strInteger, integer, positive);

}

void BigInteger::ModulusToThis(BigInteger number)
{

	/** Get the string and feed it to the other function */
	ModulusToThis(number.GetInteger());

}

void BigInteger::ModulusToThis(char number)
{

	/** Convert to string and pass it to the main function. */
	ModulusToThis(std::string(1, number));

}

void BigInteger::ModulusToThis(int number)
{

	/** Convert to string and pass it to the main function. */
	ModulusToThis(std::to_string(number));

}

void BigInteger::ModulusToThis(long number)
{

	/** Convert to string and pass it to the main function. */
	ModulusToThis(std::to_string(number));

}

void BigInteger::ModulusToThis(long long number)
{

	/** Convert to string and pass it to the main function. */
	ModulusToThis(std::to_string(number));

}

BigInteger BigInteger::Modulus(const std::string number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Modulus(BigInteger number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Modulus(char number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Modulus(int number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Modulus(long number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

BigInteger BigInteger::Modulus(long long number)
{

	/** A object to hold the current values temporarily */
	BigInteger tempBigInt(*this);

	/** Do the divison */
	tempBigInt.DivideToThis(number);

	return tempBigInt;

}

std::ostream& operator<<(std::ostream& output, const BigInteger& num)
{
	
	output << num.strInteger;

	return output;

}

std::istream& operator>>(std::istream& input, BigInteger& num)
{

	std::string inputString;
	input >> inputString;

	num.SetInteger(inputString);
	return input;

}
