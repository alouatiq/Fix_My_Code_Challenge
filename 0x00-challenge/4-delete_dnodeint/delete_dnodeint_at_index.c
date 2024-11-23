#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index in a doubly linked list
 *
 * @head: Pointer to the pointer to the first node of the list
 * @index: The index of the node to delete
 *
 * Return: 1 if successful, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int count = 0;

    if (!head || !*head) /* Handle empty list */
        return (-1);

    while (current && count < index)
    {
        current = current->next;
        count++;
    }

    if (!current) /* Index out of range */
        return (-1);

    if (current == *head) /* Deleting the head node */
    {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
    }
    else if (current->next == NULL) /* Deleting the tail node */
    {
        current->prev->next = NULL;
    }
    else /* Deleting a middle node */
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
