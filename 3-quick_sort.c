#include "sort.h"

/**
 * swap - swap two elements in an array
 * and prints the array after a swap
 * @array: given array
 * @i: first index
 * @j: second index
 * @size: size of array
 */
void swap(int **array, size_t i, size_t j, size_t size)
{
	int temp = (*array)[i];

	if (i == j)
		return;

	(*array)[i] = (*array)[j];
	(*array)[j] = temp;
	print_array(*array, size);
}

/**
 * partition - implement Lomuto partition scheme such that
 * the array is partitioned into two sub arrays of ints
 * less than the pivot (last element in the array) in the LHS and
 * and ints greater than the pivot in the RHS
 * @array: given array
 * @left: left boundary
 * @right: right boundary
 * @size: size of array
 * Return: the pivot index
 */
size_t partition(int **array, size_t left, size_t right, size_t size)
{
	/* Choose the last element as the pivot */
	int pivot = (*array)[right];
	size_t i, j;

	/* Temporary pivot index */
	i = left;

	for (j = left; j < right; j++)
	{
		/* If the current element is less than or equal to the pivot */
		if ((*array)[j] <= pivot)
		{
			/* Swap the current element with the element at the temporary pivot index */
			swap(array, i, j, size);

			/* Move the temporary pivot index forward */
			i++;
		}
	}
	/*
	 * Move the pivot element to the correct pivot position
	 * between the smaller and the larger elements
	 */
	swap(array, i, right, size);
	return (i); /* the pivot index */
}

/**
 * _quicksort - recursion helper function for quicksort function
 * @array: given array
 * @left: left boundary
 * @right: right boundary
 * @size: size of array
 */
void _quicksort(int **array, size_t left, size_t right, size_t size)
{
	size_t pivot;

	if (left >= right)
		return;

	pivot = partition(array, left, right, size);

	if (pivot - left > 1)
		_quicksort(array, left, pivot - 1, size);

	if (right - pivot > 1)
		_quicksort(array, pivot + 1, right, size);
}

/**
 * quick_sort - sorts an array with quick sort algorithm
 * @array: given array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	_quicksort(&array, 0, size - 1, size);
}
