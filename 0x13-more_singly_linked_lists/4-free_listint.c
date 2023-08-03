#include "lists.h"

/**
 * free_listint - Frees a linked list.
 * @head: Pointer to the first node of the list.
 *
 * Return: Nothing.
 */
void free_listint(listint_t *head)
{
	listint_t *current, *next_node;

	current = head;

	/* Iterate through each node in the list */
	while (current != NULL)
	{
		next_node = current->next; /* Store the next node before freeing */
		free(current); /* Free the current node */
		current = next_node; /* Move to the next node */
	}
}
