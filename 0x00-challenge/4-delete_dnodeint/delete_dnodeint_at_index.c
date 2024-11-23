#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index from a list
 *
 * @head: A pointer to the pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int count = 0;

    if (!head || !*head)
        return (-1);

    /* Traverse to the node at the given index */
    while (current && count < index)
    {
        current = current->next;
        count++;
    }

    /* If index is out of range */
    if (!current)
        return (-1);

    /* If deleting the head node */
    if (current == *head)
    {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
    }
    else /* Deleting a node other than the head */
    {
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
    }

    /* Free the node */
    free(current);
    return (1);
}
