#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Double pointer to the first node of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* List contains a loop */
			slow = *h;
			count = 0;

			while (slow != fast)
			{
				temp = slow;
				slow = slow->next;
				free(temp);
				count++;
			}

			do
			{
				temp = slow;
				slow = slow->next;
				free(temp);
				count++;
			} while (slow != fast);

			*h = NULL; /* Set head to NULL after freeing the list */
			return (count);
		}
	}

	/* No loop, simply free the list and set head to NULL */
	while (*h != NULL)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}

	return (count);
}
