#include "sort.h"
#include <stdio.h>

/**
 * _max - find the maximum element in an array
 * @array: given array
 * @size: size of array
 * Return: maximum element
 */
int _max(int *array, size_t size)
{
	int max;
	size_t i;

	for (i = 1, max = *array; i < size; i++)
		if (max < array[i])
			max = array[i];

	return (max);
}

/**
 * create_and_fill_array - creates an array filled with zero
 * @size: size of array
 * Return: new array
 */
int *create_and_fill_array(size_t size)
{
	size_t i;
	int *array;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = 0;

	return (array);
}

/**
 * counting_sort -  sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: given array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int max;
	size_t i;
	int *count_array;
	int *output;

	if (size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	max = _max(array, size);
	count_array = create_and_fill_array(max + 1);
	if (!count_array)
		return;

	/* Store the count of each element */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Store cumulative count of each array */
	for (i = 1; i <= (unsigned int) max; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max + 1);

	for (i = 0; i < size; i++)
	{
		output[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count_array);
}
