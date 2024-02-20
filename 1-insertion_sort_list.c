#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
/**
 * insertion_sort_list - sorts a DLL of integers in
 * ascending order using the insertion sort
 * algorithm
 *
 * @list: doubly linked list
 * Return: no return
 */

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->next;
        listint_t *prev = current->prev;

        while (prev != NULL && prev->n > current->n)
        {
            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;

            current->prev = prev->prev;
            current->next = prev;
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;
            prev->prev = current;

            prev = current->prev;
            if (prev != NULL)
                prev = prev->prev;
        }

        current = temp;
    }
}

