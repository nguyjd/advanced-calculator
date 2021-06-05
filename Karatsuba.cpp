#include "Karatsuba.h"

using namespace std;

int numDigits(int num);
int pow10(int n);

int karatsuba(int x, int y)
{

    // Finds the amount of digits in each number.
    int xDigitCount = numDigits(x);
    int yDigitCount = numDigits(y);

    // Find the largest amount of digits.
    int largestDigitCount;
    if (xDigitCount > yDigitCount)
    {

        largestDigitCount = xDigitCount;

    }
    else // if yDigitCount >= xDigitCount
    {

        largestDigitCount = yDigitCount;

    }

    // Base Case
    if (largestDigitCount <= 1)
    {

        return x * y;

    }

    // Largest number of digits divided by 2.
    int n2 = largestDigitCount / 2;

    int powerOfTenN = pow10(2 * n2);
    int powerOfTenN2 = pow10(n2);

    // Split the number.
    int a, b, c, d;
    a = x / powerOfTenN2;
    b = x % powerOfTenN2;
    c = y / powerOfTenN2;
    d = y % powerOfTenN2;

    // A * C
    int AandC = karatsuba(a, c);

    // B * D
    int BandD = karatsuba(b, d);

    // (a + b) * (c + d)
    int ABandCD = karatsuba((a + b), (c + d));

    // (a + b) * (c + d) - (A * C) - (B * D)
    int ADandBC = ABandCD - AandC - BandD;

    // (A * C) * 10^N + (A + D)*(B + C) * 10^(N/2) + (B * D) 
    return ((AandC * powerOfTenN) + (ADandBC * powerOfTenN2) + BandD);

}

// Helper function - returns number of digits
int numDigits(int num) {

    int digitCount = 0;

    // Count until no more digits.
    while (num != 0)
    {

        // Strip the least signifcant digit.
        num = num / 10;
        // Add one to the count.
        digitCount++;

    }

    return digitCount;

}

// Helper function - integer exponentiation
int pow10(int n) {

    int number = 1;

    for (int i = 0; i < n; i++)
    {

        number = number * 10;

    }

    return number;
}