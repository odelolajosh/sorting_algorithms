#include "sort.h"
#include <stdio.h>

/**
 * swap - swap two elements in an array
 * and prints the array after a swap
 * @array: given array
 * @i: first index
 * @j: second index
 * @size: size of array
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
	int temp = array[i];

	if (i == j)
		return;

	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
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
size_t partition(int *array, size_t left, size_t right, size_t size)
{
	int pivot = array[right];

	while (1)
	{
		while (array[left] < pivot)
			left++;

		while (array[right] > pivot)
			right--;

		if (left > right)
			return (right);

		swap(array, left, right, size);
		left++;
		right--;
	}
}

/**
 * _quicksort - recursion helper function for quicksort function
 * @array: given array
 * @left: left boundary
 * @right: right boundary
 * @size: size of array
 */
void _quicksort(int *array, size_t left, size_t right, size_t size)
{
	size_t pivot;

	if (left >= right)
		return;

	pivot = partition(array, left, right, size);
	_quicksort(array, left, pivot, size);
	_quicksort(array, pivot + 1, right, size);
}

/**
 * quick_sort_hoare - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: given array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quicksort(array, 0, size - 1, size);
}
