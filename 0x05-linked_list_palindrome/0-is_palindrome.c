#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
  * is_palindrome - is palindrome
  * @head: head of list
  *
  * Return: 1 if palindrome, else 0
  */

int is_palindrome(listint_t **head)
{
	listint_t *current;

	if (*head == NULL)
		return (1);
	current = *head;
	if (current->next == NULL)
		return (1);
	return (0);
}

