#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index in a doubly linked list
 *
 * @head: Pointer to the pointer to the first node of the list
 * @index: Index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;

    if (!head || !*head) /* Handle empty list */
        return (-1);

    /* Traverse to the node at the given index */
    for (unsigned int i = 0; current && i < index; i++)
        current = current->next;

    if (!current) /* Index out of range */
        return (-1);

    /* Update links for the previous node */
    if (current->prev)
        current->prev->next = current->next;
    else /* If deleting the head node */
        *head = current->next;

    /* Update links for the next node */
    if (current->next)
        current->next->prev = current->prev;

    /* Free the node */
    free(current);

    return (1);
}
