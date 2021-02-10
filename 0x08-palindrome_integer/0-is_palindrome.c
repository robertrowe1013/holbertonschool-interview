
#include "palindrome.h"

/**
  * is_palindrome - is palindrome
  *
  * @n: number
  *
  * Return: 1 if palindrome else 0
  */

int is_palindrome(unsigned long n)
{
    unsigned long int remainder = 0;
    unsigned long int reverse = 0;
    unsigned long int temp = n;

	if (n < 10)
	{
		return (1);
	}
	while (temp != 0)
	{
		remainder = temp % 10;
		reverse = reverse * 10 + remainder;
		temp /= 10;
	}
	if (reverse == n)
	{
		return (1);
	}

	return (0);
}
