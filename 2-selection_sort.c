#include "sort.h"
/**
 * selection_sort - trie un tableau d'entiers par sélection (ordre croissant)
 * @array: tableau d'entiers
 * @size: taille du tableau
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (size < 2 || array == NULL)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
