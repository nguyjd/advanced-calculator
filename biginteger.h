#pragma once
#include <string>
#include <deque>
#include <iostream>
#include <iterator>

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
	
	/** Destructor */
	~BigInteger();
	
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
	 * Adds a number to the stored number in the array.
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
	 * A overloaded assignment operator using the copy and swap idiom
	 * @param num - The BigInteger that is being assigned to the BigInteger left of the equal sign.
	 * @return The copied BigInteger
	 */
	BigInteger& operator=(BigInteger num);
	BigInteger& operator=(const std::string num);
	BigInteger& operator=(const char num);
	BigInteger& operator=(const int num);
	BigInteger& operator=(const long num);
	BigInteger& operator=(const long long num);

	/**
	 * A overloaded addition operator
	 * @param num - A number that is being added to the BigInteger left of the equal sign.
	 * @return A Biginteger with the value of the addition.
	 */
	BigInteger operator+(const BigInteger& num);
	BigInteger operator+(const std::string& num);
	BigInteger operator+(const char& num);
	BigInteger operator+(const int& num);
	BigInteger operator+(const long& num);
	BigInteger operator+(const long long& num);

	/**
	 * A overloaded Subtraction operator
	 * @param num - A number that is being subtracted to the BigInteger left of the equal sign.
	 * @return A Biginteger with the value of the subtraction.
	 */
	BigInteger operator-(const BigInteger& num);
	BigInteger operator-(const std::string& num);
	BigInteger operator-(const char& num);
	BigInteger operator-(const int& num);
	BigInteger operator-(const long& num);
	BigInteger operator-(const long long& num);


	BigInteger& operator++();      // Prefix increment
	BigInteger operator++(int); // Postfix increment

	BigInteger& operator--();      // Prefix decrement
	BigInteger operator--(int); // Postfix decrement

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
	void ConvertBigIntegerToString(std::string& numStr, const std::deque<char> numVec);

	/** Removes leading zero from the number. */
	void CleanUpNumber(std::deque<char>& numVec);

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