#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node in a linked list at a certain index.
 * @head: Pointer to the first element in the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 (Success), or -1 (Fail).
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	listint_t *current_node = *head;
	listint_t *prev_node = NULL;
	unsigned int i;

	if (index == 0)
	{
		*head = current_node->next;
		free(current_node);
		return (1);
	}

	for (i = 0; current_node && i < index; i++)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}

	if (current_node == NULL)
		return (-1);

	prev_node->next = current_node->next;
	free(current_node);

	return (1);
}
