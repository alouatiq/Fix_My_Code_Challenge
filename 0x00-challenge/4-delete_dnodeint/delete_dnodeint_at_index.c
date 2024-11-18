#include <stdlib.h>
#include <stdio.h> /* Added for debug print statements */
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in a list
 *
 * @head: The address of the pointer to the first element of the list
 * @index: The index of the node to delete (starting from 0)
 *
 * Return: 1 if successful, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    /* Check if the list is empty or head is NULL */
    if (head == NULL || *head == NULL) {
        printf("Error: List is empty or head is NULL\n"); /* Debug print */
        return (-1);
    }

    current = *head;

    /* If deleting the first node */
    if (index == 0) {
        printf("Deleting node at index 0: %d\n", current->n); /* Debug print */
        *head = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        free(current);
        return (1);
    }

    /* Traverse the list to find the node at the given index */
    for (i = 0; current != NULL && i < index; i++) {
        printf("Traversing to node %u: %d\n", i, current->n); /* Debug print */
        current = current->next;
    }

    /* If the node at the given index doesn't exist */
    if (current == NULL) {
        printf("Error: Node at index %u not found\n", index); /* Debug print */
        return (-1);
    }

    printf("Deleting node at index %u: %d\n", index, current->n); /* Debug print */

    /* Update the pointers and delete the node */
    if (current->next != NULL)
        current->next->prev = current->prev;
    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
    return (1);
}
