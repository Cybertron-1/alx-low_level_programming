#include "lists.h"

/**
 * free_listint_safe - Frees a linked list.
 * @h: Pointer to the first node in the linked list.
 *
 * Return: Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current_node = *h;
	listint_t *next_node = NULL;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		current_node->next = NULL;
		free(current_node);
		len++;
		current_node = next_node;

		/* Check for loops */
		if (current_node == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (len);
}
