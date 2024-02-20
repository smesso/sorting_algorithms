#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
    if (array == NULL)
        return;

    int tmp = array[l];
    array[l] = array[r];
    array[r] = tmp;
}

/**
 * partition - Partitions the array using Lomuto's scheme.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The length of the array.
 * @return: The partition index.
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low;

    for (size_t j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            if (i != j)
            {
                swap_items(array, i, j);
                print_array(array, size);
            }
            i++;
        }
    }

    swap_items(array, i, high);
    print_array(array, size);

    return i;
}

/**
 * quick_sort_recursive - Recursively sorts the array using quicksort.
 * @array: The array to sort.
 * @low: The starting index of the array.
 * @high: The ending index of the array.
 * @size: The length of the array.
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t pi = partition(array, low, high, size);

        if (pi > 0)
            quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array != NULL && size > 1)
    {
        quick_sort_recursive(array, 0, size - 1, size);
    }
}

