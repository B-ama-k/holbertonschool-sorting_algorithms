#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: first integer
 * @b: second integer
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of array
 *
 * Return: pivot index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;
	int pivot = array[high];
	int i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i + 1 != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursion - recursive quicksort
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of array
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot - 1, size);
		quick_sort_recursion(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Quick sort using Lomuto partition
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
