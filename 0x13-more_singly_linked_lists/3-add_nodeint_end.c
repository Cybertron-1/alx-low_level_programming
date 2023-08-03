#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of the list.
 * @head: Pointer to the first node of the list.
 * @n: Element (int) to add to the new node.
 *
 * Return: Address of the new element or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *last_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	last_node = *head;

	/* If the list is empty, set the new node as the head */
	if (last_node == NULL)
		*head = new_node;
	else
	{
		/* Traverse the list until the last node is reached */
		while (last_node->next != NULL)
			last_node = last_node->next;

		/* Attach the new node at the end of the list */
		last_node->next = new_node;
	}

	return (new_node);
}
