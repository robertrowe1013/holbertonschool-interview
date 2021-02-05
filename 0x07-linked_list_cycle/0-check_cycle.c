#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
  * check_cycle - check for cycle
  * @list: list to check
  *
  * Return: 1 if cycle, else 0
  */

int check_cycle(listint_t *list)
{
	listint_t *tort = list;
	listint_t *hare = list;

	if (list == NULL)
	{
		return (0);
	}
	while (tort != NULL && hare != NULL && hare->next != NULL)
	{
		tort = tort->next;
		hare = hare->next->next;
		if (tort == hare)
		{
			return (1);
		}
	}

	return (0);
}

