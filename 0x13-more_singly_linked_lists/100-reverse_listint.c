#include "lists.h"

/**
 * reverse_listint_recursive - Helper function to reverse a linked list recursively.
 * @current: Current node to reverse.
 * @prev: Previous node (NULL initially).
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint_recursive(listint_t *current, listint_t *prev)
{
    listint_t *next = current->next;
    current->next = prev;

    if (next == NULL)
        return current;

    return reverse_listint_recursive(next, current);
}

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;

    return reverse_listint_recursive(*head, NULL);
}
