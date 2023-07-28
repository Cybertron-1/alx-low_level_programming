#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed on terminal
 * print_list - prints all the elements of a linked list
 */
int a = 0;
int b = 1;
size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		x++;
	}

	return (x);
}
