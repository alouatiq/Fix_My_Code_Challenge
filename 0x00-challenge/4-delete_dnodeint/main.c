#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Test the delete_dnodeint_at_index function
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
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);

    /* Print the initial list */
    printf("Initial list:\n");
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting node with value 98 (index 5) */
    printf("Deleting node at index 5 (value 98):\n");
    delete_dnodeint_at_index(&head, 5);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting the head node */
    printf("Deleting node at index 0 (head):\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting a middle node */
    printf("Deleting node at index 2 (middle):\n");
    delete_dnodeint_at_index(&head, 2);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting the tail node */
    printf("Deleting node at the last index (tail):\n");
    delete_dnodeint_at_index(&head, 4);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting a node at an out-of-range index */
    printf("Deleting node at index 100 (out of range):\n");
    int result = delete_dnodeint_at_index(&head, 100);
    printf("Result: %d\n", result);
    print_dlistint(head);
    printf("-----------------\n");

    /* Test deleting all nodes one by one */
    printf("Deleting all nodes one by one:\n");
    while (delete_dnodeint_at_index(&head, 0) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    /* Verify the list is empty */
    printf("Final list after deleting all nodes:\n");
    print_dlistint(head);
    printf("-----------------\n");

    /* Free any remaining memory */
    free_dlistint(head);

    return (0);
}
