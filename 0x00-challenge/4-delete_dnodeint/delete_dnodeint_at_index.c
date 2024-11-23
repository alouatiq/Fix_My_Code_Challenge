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
    dlistint_t *current;
    unsigned int i; /* Declare variables at the top */

    if (!head || !*head) /* Handle empty list */
        return (-1);

    current = *head;
    i = 0;

    /* Traverse to the node at the given index */
    while (current && i < index)
    {
        current = current->next;
        i++;
    }

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
