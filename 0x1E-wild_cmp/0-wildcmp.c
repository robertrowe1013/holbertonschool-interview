#include "holberton.h"

/**
  * wildcmp - compare two strings
  * @s1: first string
  * @s2: second string, may contain wildcards
  *
  * Return: 1 is match, else 0
  */

int wildcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		return (0);
	}

	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s2 == '*')
	{
		s2 = move2(s2);
	}
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	return (0);
}

/**
  * move2 - move s2
  * @s2: pointer to s2
  *
  * Return: new pointer location
  */

char *move2(char *s2)
{
	if (*s2 == '\0')
	{
		return (s2);
	}
	if (*s2 == '*')
	{
		return (move2(s2 + 1));
	}
	return (s2);
}
