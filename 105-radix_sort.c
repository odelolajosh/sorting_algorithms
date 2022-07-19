#include "sort.h"
#include <stdlib.h>

/**
 * _max - finds the max value in an array of integers
 * @array: the array to search
 * @size: size of the array
 * Return: the max integer
 */
int _max(int *array, int size)
{
	int max, i;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * init_countarray - initializes count array with zero
 * @count_arr: array to initialize
 * @size: size of count_arr
 */

void init_countarray(int *count_arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		count_arr[i] = 0;
}

/**
 * count_sort - a similar implementation to countingSort algorithm
 * @array: array to sort
 * @size: size of array
 * @pos: place value starting at LSD
 */
void count_sort(int *array, int size, int pos)
{
	int count_arr[10], i, *nw_array;

	nw_array = malloc(size * sizeof(int));
	if (!nw_array)
		return;

	init_countarray(count_arr, 10);
	for (i = 0; i < size; i++)
		++count_arr[(array[i] / pos) % 10];

	for (i = 1; i < 10; i++)
		count_arr[i] = count_arr[i] + count_arr[i - 1];

	for (i = size - 1; i >= 0; i--)
		nw_array[--count_arr[(array[i] / pos) % 10]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = nw_array[i];

	free(nw_array);
	print_array(array, size);
}

/**
 * radix_sort - implementation of radix sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, pos;

	if (!array || size < 2)
		return;

	max = _max(array, size);
	for (pos = 1; (max / pos) > 0; pos = pos * 10)
		count_sort(array, size, pos);
}
