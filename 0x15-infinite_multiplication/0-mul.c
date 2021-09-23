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
	char *product;
	int len;
	int i;

	if (argc != 3 || _isdigit(argv[1]) != 0 || _isdigit(argv[2]) != 0)
	{
		_puts("Error\n");
		exit(98);
	}
	product = mul(argv[1], argv[2]);
	len = _strlen(product);
	len--;
	while (product[len] == '0')
	{
		len--;
	}
	if (len == -1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	for (i = len; i >= 0; i--)
	{
		_putchar(product[i]);
	}
	_putchar('\n');
	free(product);
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

/**
  * mul - multiply numbers
  * @num1: first number
  * @num2: second number
  *
  * Return: product
  */
char *mul(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int i, j, n1, n2, i_n1 = 0, i_n2 = 0;
	int carry = 0, sum = 0;
	char *product = malloc(sizeof(char) * (len1 + len2));

	for (i = 0; i < (len1 + len2); i++)
	{
		product[i] = '0';
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		i_n2 = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			if (product[i_n1 + i_n2] > 9)
				product[i_n1 + i_n2] -= '0';
			sum = n1 * n2 + product[i_n1 + i_n2] + carry;
			carry = sum / 10;
			product[i_n1 + i_n2] = (sum % 10) + '0';
			i_n2++;
		}
		if (carry > 0)
		{
			product[i_n1 + i_n2] += carry;
		}
		i_n1++;
	}
	return (product);
}
