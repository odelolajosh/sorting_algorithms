#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: given array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, flag = 1;

	if (size <= 2)
		return;

	for (i = 0; i < size && flag; i++)
	{
		for (j = 0, flag = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
	}
}
