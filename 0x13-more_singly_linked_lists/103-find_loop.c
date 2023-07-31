#include "lists.h"

/**
 * find_listint_loop - Finds the start node of the loop in a linked list.
 * @head: Pointer to the first node of the list.
 *
 * Return: The address of the node where the loop starts, or NULL if there's no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Loop detected, reset slow to head and start from the beginning */
			slow = head;

			/* Move slow and fast at the same pace until they meet again */
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			return (slow); /* Return the address of the loop start node */
		}
	}

	return (NULL); /* No loop found, return NULL */
}
