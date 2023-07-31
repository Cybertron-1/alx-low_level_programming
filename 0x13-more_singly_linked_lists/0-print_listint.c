#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: Linked list of type listint_t to print.
 *
 * Return: Number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;
	const listint_t *current = h;

	while (current)
	{
		printf("%d\n", current->n);
		num++;
		current = current->next;
	}

	return (num);
}
