#include "lists.h"

/**
  * find_listint_loop - find loop in linked list
  * @head: pointer to head of linked list
  *
  * Return: start of loop or NULL
  **/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortise, *hare;

	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}
	tortise = head;
	hare = head;
	while (hare->next && hare->next->next)
	{
		tortise = tortise->next;
		hare = hare->next->next;
		if (tortise == hare)
		{
			tortise = head;
			while (hare != NULL)
			{
				if (tortise == hare)
				{
					return (hare);
				}
				tortise = tortise->next;
				hare = hare->next;
			}
		}
	}
	return (NULL);
}
