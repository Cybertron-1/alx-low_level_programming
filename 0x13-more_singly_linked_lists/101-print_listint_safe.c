#include "lists.h"

/**
 * print_listint_safe - prints a linked list.
 * @head: head of a list.
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nnodes = 0;
	listint_t *fast, *slow;

	fast = slow = (listint_t *)head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("Loop detected, stopping printing...\n");
			return (nnodes);
		}
	}

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nnodes++;
	}

	return (nnodes);
}
