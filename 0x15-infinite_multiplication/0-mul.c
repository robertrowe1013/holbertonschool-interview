#include "holberton.h"

/**
  * main - multiplies two positive numbers
  * @argc: number of arguments
  * @argv: arguments
  *
  * Return: 0 else 98 on error
  */
int main(int argc, char *argv[])
{
	if (argc != 3 || _isdigit(argv[1]) != 0 || _isdigit(argv[2]) != 0)
	{
		_puts("Error\n");
		exit(98);
	}
	return (0);
}

/**
  * _puts - prints a string
  * @str: string to print
  *
  * Return: 0 else 1 on error
  */
int _puts(char *str)
{
	int i;
	int len = _strlen(str);

	if (str == NULL)
	{
		return (1);
	}
	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}
	return (0);
}

/**
  * _isdigit - verifies if a string is numerical
  * @str: string to verify
  *
  * Return: 0 if digit, else 1
  */
int _isdigit(char *str)
{
	int i;
	int len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
	}
	return (0);
}

/**
  * _strlen - length of string
  * @str: string to check
  *
  * Return: length of string
  */
int _strlen(char *str)
{
	int len = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		len++;
	}
	return (len);
}
