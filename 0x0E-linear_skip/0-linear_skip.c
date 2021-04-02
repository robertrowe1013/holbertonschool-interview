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
	if (list == NULL)
		return (NULL);
	if (list->n == value)
		return (list);
	return (NULL);
}
