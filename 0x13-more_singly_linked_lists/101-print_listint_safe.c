#include "lists.h"

/**
 * print_listint_safe - function that prints a linked list with a loop safely.
 * @head: pointer to the 1st node of the linked list
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = NULL;
	const listint_t *check_node = NULL;
	size_t counter = 0;
	size_t new_counter;

	current = head;
	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		counter++;
		current = current->next;
		check_node = head;
		new_counter = 0;
		while (new_counter < counter)
		{
			if (current == check_node)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (counter);
			}
			check_node = check_node->next;
			new_counter++;
		}
		if (!head)
			exit(98);
	}
	return (counter);
}
