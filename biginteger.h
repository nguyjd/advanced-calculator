#pragma once
#include <string>
#include <deque>
#include <iostream>
#include <iterator>
#include <future>
#include <vector>
#include <chrono>

/** The offset from the character 0 */
#define ASCIIOFFSET 48

class BigInteger 
{

public:

	/** Default Contructor */
	BigInteger();

	/** Contructs the object and convert the string to the array.*/
	BigInteger(const std::string number);

	/** Contructs the object and convert the number to the array.*/
	BigInteger(const char number);
	BigInteger(const int number);
	BigInteger(const long number);
	BigInteger(const long long number);

	/** Copy Constuctor */
	BigInteger(const BigInteger& integer);
	
	/**
	 * Converts the string into a array and stores it and sets it.
	 * @param number - The number to be stored into the Big Integer.
	 * @return The state of the operation. Returns true if the fuction worked.
	 */
	bool SetInteger(const std::string number);
	bool SetInteger(const char number);
	bool SetInteger(const int number);
	bool SetInteger(const long number);
	bool SetInteger(const long long number);

	/** The sign of the number. Returns true if positive. */
	bool IsIntegerPositive();

	/** The value of the number as a string. */
	std::string GetInteger();

	/**
	 * Adds a number to the stored number in the array.
	 * @param number - The number being added to the array.
	 */
	void AddToThis(const std::string number);
	void AddToThis(BigInteger number);
	void AddToThis(char number);
	void AddToThis(int number);
	void AddToThis(long number);
	void AddToThis(long long number);

	/**
	 * Adds a number to the stored number in the array.
	 * @param number - The number being added with the array.
	 * @return The addition of the internal number and the given number as a BigInteger
	 */
	BigInteger Add(const std::string number);
	BigInteger Add(BigInteger number);
	BigInteger Add(char number);
	BigInteger Add(int number);
	BigInteger Add(long number);
	BigInteger Add(long long number);

	/**
	 * Subtracts a number to the stored number in the array.
	 * @param number - The number being subtracted to the array.
	 */
	void SubToThis(const std::string number);
	void SubToThis(BigInteger number);
	void SubToThis(char number);
	void SubToThis(int number);
	void SubToThis(long number);
	void SubToThis(long long number);

	/**
	 * Subtracts a number to the stored number in the array.
	 * @param number - The number being subtracted with the array.
	 * @return The subtraction of the internal number and the given number as a BigInteger
	 */
	BigInteger Sub(const std::string number);
	BigInteger Sub(BigInteger number);
	BigInteger Sub(char number);
	BigInteger Sub(int number);
	BigInteger Sub(long number);
	BigInteger Sub(long long number);

	/**
	 * Multiplied a number to the stored number in the array.
	 * @param number - The number being multiplied to the array.
	 */
	void MultiplyToThis(const std::string number);
	void MultiplyToThis(BigInteger number);
	void MultiplyToThis(char number);
	void MultiplyToThis(int number);
	void MultiplyToThis(long number);
	void MultiplyToThis(long long number);

	/**
	 * Multiplied a number to the stored number in the array.
	 * @param number - The number being multiplied with the array.
	 * @return The multiplication of the internal number and the given number as a BigInteger
	 */
	BigInteger Multiply(const std::string number);
	BigInteger Multiply(BigInteger number);
	BigInteger Multiply(char number);
	BigInteger Multiply(int number);
	BigInteger Multiply(long number);
	BigInteger Multiply(long long number);

	/**
	 * Divide a number to the stored number in the array.
	 * @param number - The number being divided to the array.
	 */
	void DivideToThis(const std::string number);
	void DivideToThis(BigInteger number);
	void DivideToThis(char number);
	void DivideToThis(int number);
	void DivideToThis(long number);
	void DivideToThis(long long number);

	/**
	 * Divide a number to the stored number in the array.
	 * @param number - The number being divided with the array.
	 * @return The division of the internal number and the given number as a BigInteger
	 */
	BigInteger Divide(const std::string number);
	BigInteger Divide(BigInteger number);
	BigInteger Divide(char number);
	BigInteger Divide(int number);
	BigInteger Divide(long number);
	BigInteger Divide(long long number);

	/**
	 * Modulus a number to the stored number in the array.
	 * @param number - The number being modulus to the array.
	 */
	void ModulusToThis(const std::string number);
	void ModulusToThis(BigInteger number);
	void ModulusToThis(char number);
	void ModulusToThis(int number);
	void ModulusToThis(long number);
	void ModulusToThis(long long number);

	/**
	 * Modulus a number to the stored number in the array.
	 * @param number - The number being modulus with the array.
	 * @return The modulus of the internal number and the given number as a BigInteger
	 */
	BigInteger Modulus(const std::string number);
	BigInteger Modulus(BigInteger number);
	BigInteger Modulus(char number);
	BigInteger Modulus(int number);
	BigInteger Modulus(long number);
	BigInteger Modulus(long long number);

	/**
	 * A overloaded assignment operator using the copy and swap idiom
	 * @param num - The BigInteger that is being assigned to the BigInteger left of the equal sign.
	 * @return The copied BigInteger
	 */
	BigInteger& operator=(BigInteger num);

	/**
	 * A overloaded addition operator
	 * @param num - A number that is being added to the BigInteger left of the equal sign.
	 * @return A Biginteger with the value of the addition.
	 */
	BigInteger operator+(const BigInteger& num);

	/**
	 * A overloaded Subtraction operator
	 * @param num - A number that is being subtracted to the BigInteger left of the equal sign.
	 * @return A Biginteger with the value of the subtraction.
	 */
	BigInteger operator-(const BigInteger& num);

	/**
	 * A overloaded multiplication operator
	 * @param num - A number that is being multiplied to the BigInteger left of the equal sign.
	 * @return A Biginteger with the value of the multiplication.
	 */
	BigInteger operator*(const BigInteger& num);

	/**
	 * A overloaded division operator
	 * @param num - A number that is being divided to the BigInteger left of the equal sign.
	 * @return A Biginteger with the value of the division.
	 */
	BigInteger operator/(const BigInteger& num);

	/** A overloaded modulus operator */
	BigInteger operator%(const BigInteger& num);

	/** A overloaded increment operator */
	BigInteger& operator++();
	BigInteger operator++(int);

	/** A overloaded decrement operator */
	BigInteger& operator--();
	BigInteger operator--(int);

	/** A overloaded addition and subtraction assignment operator */
	BigInteger& operator+=(const BigInteger& num);
	BigInteger& operator-=(const BigInteger& num);

	/** A overloaded multiplication assignment operator */
	BigInteger operator*=(const BigInteger& num);

	/** A overloaded division and modulus assignment operator */
	BigInteger operator/=(const BigInteger& num);
	BigInteger operator%=(const BigInteger& num);

	/** All the comparison operators */
	bool operator==(const BigInteger& num);
	bool operator!=(const BigInteger& num);
	bool operator<(const BigInteger& num);
	bool operator>(const BigInteger& num);
	bool operator>=(const BigInteger& num);
	bool operator<=(const BigInteger& num);

protected:

	/** Input and output operator */
	friend std::ostream& operator<<(std::ostream& output, const BigInteger& num);
	friend std::istream& operator>>(std::istream& input, BigInteger& num);

private:

	/**
	 * Verify the number to ensure there is not any unusable characters.
	 * @param number - The number to be verify as a string.
	 * @return The validity of the number.
	 */
	bool VerifyNumber(const std::string number);

	/**
	 * Converts the string given to a deque filled with the numbers from the string.
	 * @param numStr - The string being converted
	 * @param numVec - The array that the number is being stored to
	 * @param positive - The sign of the number.
	 */
	void ConvertStringToBigInteger(const std::string numStr, std::deque<char>& numVec, bool& positive);

	/**
	 * Converts the numbers from the deque into a readable string.
	 * @param numStr - The number as the string.
	 * @param numVec - The array storing the number.
	 */
	void ConvertBigIntegerToString(std::string& numStr, const std::deque<char> numVec, const bool positive);

	/** Removes leading zero from the number. */
	void CleanUpNumber(std::deque<char>& numVec);

	/**
	 * Multiply a number by a single digit.
	 * Used to multi-thread the multiplication function.
	 * @param firstNum - The number being multiplied.
	 * @param digit - The single digit that multiplies with the first number.
	 * @param place - The amount of base 10 digit places to extend the digit. 
	 */
	BigInteger LongMultiplyThread(std::deque<char> firstNum, char digit, unsigned long long int place);

private:

	/** True if the number stored is usable within the functions */
	bool validNumber;

	/** The sign of the number. True if the sign of the number is positive. */
	bool positive;

	/** The number as a string */
	std::string strInteger;

	/** The number stored in the array. */
	std::deque<char> integer;

};