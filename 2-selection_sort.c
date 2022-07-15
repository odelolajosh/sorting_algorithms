#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: given array
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (min = i, j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
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
