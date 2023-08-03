#include "lists.h"

/**
 * pop_listint - Deletes the head of the linked list.
 * @head: Double pointer to the first node of the list.
 *
 * Return: The head's node's data (n) or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int first_node_data = 0;
	listint_t *kobbycyber, *next_node;

	/* If list is empty, return 0 */
	if (head == NULL || *head == NULL)
		return (0);

	kobbycyber = *head; /* Set head's address to kobbycyber */
	next_node = kobbycyber->next; /* Get address of the next node */
	first_node_data = kobbycyber->n; /* Get the element of the first node */

	free(kobbycyber); /* Free the first node */
	*head = next_node; /* Set head to the second node */

	return (first_node_data); /* Return the element of the first node */
}
