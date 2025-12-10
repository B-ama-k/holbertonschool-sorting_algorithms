#include "sort.h"

/**
 * bubble_sort - Trie un tableau d'entiers par la méthode du tri à bulles
 * @array: Le tableau à trier
 * @size: Le nombre d'éléments dans le tableau
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;

    if (array == NULL)
        return;

    if (size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
        }
    }
}
