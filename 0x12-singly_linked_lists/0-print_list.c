#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed on terminal
 */
size_t print_list(const list_t *h)
{
	if (h == NULL)
		return (0);

	if (!h->str)
		printf("[0] (nil)\n");
	else
		printf("[%u] %s\n", h->len, h->str);

	return (1 + print_list(h->next));
}
