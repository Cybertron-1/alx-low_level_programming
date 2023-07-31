#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a linked list.
 * @head: Pointer to the first node in the list.
 * @n: Data to insert in that new node.
 *
 * Return: Pointer to the new node, or NULL if it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = *head;

	/* Set the new node as the new head of the list */
	*head = new_node;

	return (new_node);
}
