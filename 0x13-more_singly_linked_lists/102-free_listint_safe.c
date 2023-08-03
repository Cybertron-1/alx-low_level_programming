#include "lists.h"

/**
 * free_listint_safe - frees a linked list.
 * @head: Double pointer to the first node in the linked list.
 *
 * Return: Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **head)
{
	size_t elements_freed = 0;
	int differentiation;
	listint_t *current;

	if (!head || !*head)
		return (0);

	while (*head)
	{
		differentiation = *head - (*head)->next;
		if (differentiation > 0)
		{
			current = (*head)->next;
			free(*head);
			*head = current;
			elements_freed++;
		}
		else
		{
			free(*head);
			*head = NULL;
			elements_freed++;
			break;
		}
	}

	*head = NULL;

	return (elements_freed);
}
