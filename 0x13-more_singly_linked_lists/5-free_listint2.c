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

	while (*head != NULL)
	{
		listint_t *kobbycyber = *head;
		*head = (*head)->next;
		free(kobbycyber);
	}

	*head = NULL;
}
