#include "lists.h"
#include <stdlib.h>

/**
 * custom_insert_nodeint_at_index - Insert a new node at a given position.
 * @list: Address of the first node of the list.
 * @index: Position of the new node to be inserted in.
 * @data: Data of the new node.
 *
 * Return: Address of the new node.
 **/
listint_t *custom_insert_nodeint_at_index(listint_t **list, unsigned int index, int data)
{
	listint_t *new_node, *current;
	unsigned int i = 0;

	if (*list == NULL && index != 0)
		return (NULL);

	if (index != 0)
	{
		current = *list;
		while (i < index - 1 && current != NULL)
		{
			current = current->next;
			i++;
		}

		if (current == NULL)
			return (NULL);
	}

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = data;

	if (index == 0)
	{
		new_node->next = *list;
		*list = new_node;
		return (new_node);
	}

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
