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
    unsigned int i = 0;

    if (!head || !*head) /* Handle empty list */
        return (-1);

    /* Traverse to the node at the given index */
    while (current && i < index)
    {
        current = current->next;
        i++;
    }

    if (!current) /* Index out of range */
        return (-1);

    /* Update pointers to remove the node */
    if (current->prev) /* If not deleting the head node */
        current->prev->next = current->next;
    else /* Deleting the head node */
        *head = current->next;

    if (current->next) /* If not deleting the tail node */
        current->next->prev = current->prev;

    free(current);
    return (1);
}

