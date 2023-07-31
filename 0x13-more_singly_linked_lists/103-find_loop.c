#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Linked list to search for.
 *
 * Return: Address of the node where the loop starts, or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			listint_t *start = head;
			while (start != slow)
			{
				start = start->next;
				slow = slow->next;
			}
			return (start);
		}
	}

	return (NULL);
}
