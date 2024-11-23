#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Test delete_dnodeint_at_index function
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;

    /* Add nodes to the list */
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 5);

    printf("Initial list:\n");
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting the head node */
    printf("Deleting node at index 0:\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting a middle node */
    printf("Deleting node at index 2:\n");
    delete_dnodeint_at_index(&head, 2);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting the tail node */
    printf("Deleting node at index 3 (tail):\n");
    delete_dnodeint_at_index(&head, 3);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting out of range index */
    printf("Deleting node at index 10 (out of range):\n");
    int result = delete_dnodeint_at_index(&head, 10);
    printf("Result: %d\n", result);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting all remaining nodes */
    while (delete_dnodeint_at_index(&head, 0) == 1)
        ;
    printf("After deleting all nodes:\n");
    print_dlistint(head);
    printf("-----------------\n");

    free_dlistint(head);
    return (0);
}
