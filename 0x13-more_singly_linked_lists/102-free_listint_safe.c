#include "lists.h"
#include <stdio.h>

/**
 * free_listint_safe - Frees a linked list and sets the head to NULL.
 * @h: Double pointer to the first node of the listint_t list to be freed.
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	if (h == NULL)
		return (0);

	size_t count = 0;
	listint_t *current = *h;
	listint_t *next_node;

	while (current != NULL)
	{
		if (current <= current->next)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		else
		{
			free(current);
			current = NULL;
		}
		count++;
	}

	*h = NULL;
	return count;
}
