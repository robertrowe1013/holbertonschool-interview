#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * insert_node - insert node
  * @head: head of linked list
  * @number: number to insert
  *
  * Return: linked list
  */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *current;
	listint_t *prev;

	current = *head;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->n = number;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else if (*head->n > number)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		while (current->next != NULL && current->n < number)
		{
			prev = current;
			current = current->next;
		}
		prev->next = newNode;
		newNode->next = current;
	}

	return (newNode);
}
