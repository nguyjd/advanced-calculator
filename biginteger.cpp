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

	// TODO: REDO THE TEMP SOLUTION
	BigInteger tempBigInt(*this);
	tempBigInt.MultiplyToThis(num.strInteger);
	return tempBigInt;
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
	bool leadingZerosRemoved = false;
	for (char character : numStr)
	{

		if (character != '0')
		{

			leadingZerosRemoved = true;

		}

		if (character >= '0' && character <= '9')
		{ 
		
			numVec.push_back(character - ASCIIOFFSET);

		}

	}

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

void BigInteger::MultiplyToThis(const std::string number)
{

	/** The local arrays used for computation */
	std::deque<char> firstNumber = integer;
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
	if (firstNumber.size() < secondNumber.size())
	{

		/** Swap the numbers. */
		std::deque<char> tempDeque = secondNumber;
		secondNumber = firstNumber;
		firstNumber = tempDeque;

	}


	BigInteger counter = 0;
	std::deque<char> tempDeque;
	std::string tempBigIntStr;
	char product = 0;
	char carry = 0;
	*this = 0;

	std::deque<char>::const_reverse_iterator firstNumberPtr = firstNumber.crbegin();
	std::deque<char>::const_reverse_iterator secondNumberPtr = secondNumber.crbegin();
	while (secondNumberPtr != secondNumber.crend())
	{

		tempDeque.clear();
		for (BigInteger i = 0; i < counter; i++)
		{

			tempDeque.push_front(0);

		}

		firstNumberPtr = firstNumber.crbegin();
		while (firstNumberPtr != firstNumber.crend())
		{

			product = *secondNumberPtr * *firstNumberPtr + carry;
			tempDeque.push_front(product % 10);
			carry = product / 10;

			firstNumberPtr++;

		}

		if (carry != 0)
		{

			tempDeque.push_front(carry);
			carry = 0;

		}

		CleanUpNumber(tempDeque);
		ConvertBigIntegerToString(tempBigIntStr, tempDeque, true);

		*this += tempBigIntStr;
		counter++;
		secondNumberPtr++;

	}

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
