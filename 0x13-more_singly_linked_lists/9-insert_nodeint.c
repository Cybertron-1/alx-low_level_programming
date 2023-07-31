#include "lists.h"
#include <stdlib.h>

/**
 * custom_insert_node_at - Inserts a new node at a specific position in the list.
 * @pointer_to_start: Pointer to the start of the list.
 * @position: Position where the new node should be inserted.
 * @value: Value to be assigned to the new node.
 *
 * Return: Address of the newly inserted node or NULL if failed.
 */
listint_t *custom_insert_node_at(listint_t **pointer_to_start, unsigned int position, int value)
{
	listint_t *new_node, *current_node;
	unsigned int counter = 0;

	if (pointer_to_start == NULL)
		return (NULL);

	if (position != 0)
	{
		current_node = *pointer_to_start;
		while (counter < position - 1 && current_node != NULL)
		{
			current_node = current_node->next;
			counter++;
		}

		if (current_node == NULL)
			return (NULL);
	}

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;

	if (position == 0)
	{
		new_node->next = *pointer_to_start;
		*pointer_to_start = new_node;
		return (new_node);
	}

	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
