#include "lists.h"

/**
 * free_listint2 - Frees a linked list and sets the head to NULL.
 * @head: Double pointer to the listint_t list to be freed.
 *
 * Description: This function frees the entire linked list starting from the
 * given head node and sets the head to NULL after freeing all nodes.
 */
void free_listint2(listint_t **head)
{
	if (head == NULL)
		return;

	listint_t *current = *head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}
