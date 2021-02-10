
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
	unsigned long reverse = 0;
	unsigned long remainder = 0;
	unsigned long temp = n;

	if (n < 10)
	{
		return (1);
	}
	while (temp != 0)
	{
		printf("start loop\n");
		printf("temp: %lu, remainder: %lu, reverse: %lu\n", temp, remainder, reverse);
		remainder = temp % 10;
		reverse = reverse * 10 + remainder;
		temp /= 10;
		printf("end loop, temp: %lu, remainder: %lu, reverse: %lu\n", temp, remainder, reverse);
	}
	if (reverse == n)
	{
		return (1);
	}

	return (0);
}
