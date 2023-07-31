#include "lists.h"

/**
 * print_listint_safe - Function that prints a linked list with a loop safely.
 * @head: Pointer to the 1st node of the linked list.
 * Return: Number of nodes in the linked list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	size_t counter = 0;

	while (slow && fast && fast->next)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		counter++;
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			return (counter);
		}
	}

	return (counter);
}
