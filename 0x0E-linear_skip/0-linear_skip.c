#include "search.h"

/**
  * linear_skip - search thru skip list
  * @list: list to search
  * @value: value searching for
  *
  * Return: pointer to node or null
  */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *xp = NULL;
	skiplist_t *i = NULL;

	if (list == NULL)
		return (NULL);

	xp = list->express;
	i = list;
	while (xp != NULL && xp->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", xp->index, xp->n);
		i = xp;
		xp = xp->express;
	}
	if (xp == NULL)
	{
		xp = i->next;
		while (xp->next != NULL)
		{
			xp = xp->next;
		}
		printf("Value found between indexes [%lu] and [%lu]\n", i->index, xp->index);
	}
	else
	{
		printf("Value checked at index [%lu] = [%d]\n", xp->index, xp->n);
		printf("Value found between indexes [%lu] and [%lu]\n", i->index, xp->index);
	}
	while (i != NULL && i->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", i->index, i->n);
		i = i->next;
	}
	if (i != NULL)
		printf("Value checked at index [%lu] = [%d]\n", i->index, i->n);
	return (i);
}
