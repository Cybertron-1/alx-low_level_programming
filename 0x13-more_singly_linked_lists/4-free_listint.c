#include "lists.h"

/**
 * free_listint - Frees a linked list.
 * @head: Pointer to the listint_t list to be freed.
 */
void free_listint(listint_t *head)
{
	while (head)
	{
		listint_t *next_node = head->next;
		free(head);
		head = next_node;
	}
}
