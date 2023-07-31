#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to the first node of the list.
 * @idx: The index of the list where the new node should be added.
 * @n: Element to add to the new node.
 *
 * Return: Address of the new node or NULL if anything fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current_node = *head;
	unsigned int i;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		for (i = 0; current_node != NULL && i < idx - 1; i++)
			current_node = current_node->next;

		if (i != idx - 1)
		{
			free(new_node);
			return (NULL);
		}

		new_node->next = current_node->kobbycyber;
		current_node->kobbycyber = new_node;
	}

	return (new_node);
}
