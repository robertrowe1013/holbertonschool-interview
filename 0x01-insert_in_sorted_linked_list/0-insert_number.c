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

	current = *head;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->n = nunmber;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (current->next != NULL || current->n < number)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	return (newNode);	
}
