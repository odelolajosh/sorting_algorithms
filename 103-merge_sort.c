#include "sort.h"
#include <stdio.h>

/**
 * print_larray - Prints an array of integers with exclusive
 * boundaries
 * @s: remark
 * @array: The array to be printed
 * @low: lower boundary
 * @high: upper boundary
 */
void print_larray(char *s, const int *array, size_t low, size_t high)
{
	size_t i;

	printf("[%s]: ", s);
	i = low;
	while (array && i <= high)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * merge_conquer - merges two sub arrays
 * [low ... middle] and [middle + 1, ..., high]
 * @array: given array
 * @low: lower boundary
 * @middle: lower exclusive separator
 * @high: upper boundary
 * @working: working array
 */
void merge_conquer(int *array, size_t low,
size_t middle, size_t high, int *working)
{
	size_t current1, current2, current3, i;

	printf("Merging...\n");
	print_larray("left", array, low, middle);
	print_larray("right", array, middle + 1, high);

	current1 = current3 = low;
	current2 = middle + 1;
	while (current1 <= middle && current2 <= high)
	{
		if (array[current1] <= array[current2])
			working[current3++] = array[current1++];
		else
			working[current3++] = array[current2++];
	}

	while (current1 <= middle)
		working[current3++] = array[current1++];

	while (current2 <= high)
		working[current3++] = array[current2++];

	for (i = low; i <= high; i++)
		array[i] = working[i];

	print_larray("Done", working, low, high);
}

/**
 * merge_divide - implements merge sort
 * divides and conquer technique
 * [low ... middle] and [middle + 1, ..., high]
 * @array: given array
 * @low: lower boundary
 * @high: upper boundary
 * @working: working array
 */
void merge_divide(int *array, size_t low, size_t high, int *working)
{
	size_t middle;

	if (low >= high)
		return;

	middle = (high + low - 1) / 2;

	merge_divide(array, low, middle, working);
	merge_divide(array, middle + 1, high, working);
	merge_conquer(array, low, middle, high, working);
}

/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: given array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *working;

	if (!array || size < 2)
		return;

	working = malloc(sizeof(int) * size);
	if (!working)
		return;

	merge_divide(array, 0, size - 1, working);
	free(working);
}
