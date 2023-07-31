#include "lists.h"

/**
 * add_nodeint_end - Adds a node at the end of a linked list.
 * @head: Pointer to the first element in the list.
 * @n: Data to insert in the new element.
 *
 * Return: Pointer to the new node, or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* Create a new node and allocate memory for it */
	listint_t *new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node with data and set the next pointer to NULL */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, set the new node as the head */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list until the last node is reached */
	listint_t *current = *head;
	while (current->next != NULL)
		current = current->next;

	/* Attach the new node at the end of the list */
	current->next = new_node;

	return (new_node);
}
