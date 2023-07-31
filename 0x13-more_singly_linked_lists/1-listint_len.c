#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 * @h: Linked list of type listint_t to traverse.
 *
 * Return: Number of nodes.
 */
size_t listint_len(const listint_t *h)
{
	if (!h)
		return (0);

	return (1 + listint_len(h->next));
}
