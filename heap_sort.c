#include "sort.h"

/**
 * swap - swap two elements in an array and prints the array
 * @array: given array
 * @e1: first element
 * @e2: second element
 * @size: array size
 */
void swap(int *array, size_t e1, size_t e2, size_t size)
{
	int temp;

	temp = array[e1];
	array[e1] = array[e2];
	array[e2] = temp;
	print_array(array, size);
}

/**
 * sift_down - sifts down an ex-parent to its appropriate position
 * in the max heap
 * @array: given array
 * @index: current index to heapify
 * @upper: inclusive upper boundary
 * @size: array size
 */
void sift_down(int *array, size_t index, size_t upper, size_t size)
{
	size_t left, right, max;

	/* index is a leaf */
	if (index >= upper)
		return;

	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left > upper)
		return;

	max = left;
	if (right <= upper && array[right] > array[left])
		max = right;

	if (array[index] < array[max])
	{
		swap(array, index, max, size);
		sift_down(array, max, upper, size);
	}
}

/**
 * heapify - makes a sub-array (0 .. upper) in an array a binary heap
 * @array: given array
 * @index: current index to heapify
 * @upper: inclusive upper boundary
 * @size: array size
 */
void heapify(int *array, size_t index, size_t upper, size_t size)
{
	size_t current = index, parent, max, brother;

	while (current > 0)
	{
		parent = (current - 1) / 2;
		brother = 2 * parent + 1;
		if (brother == current)
			brother++;

		max = current;
		if (brother <= upper && array[brother] > array[current])
			max = brother;

		if (array[max] > array[parent])
		{
			swap(array, max, parent, size);
			sift_down(array, max, upper, size);
		}
		else
		{
			break;
		}

		current = parent;
	}

	if (index > 0)
		heapify(array, index - 1, upper, size);
}

/**
 * heap_sort - ...
 * @array: given array
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;

	for (i = size - 1; i > 0; i--)
	{
		heapify(array, i, i, size);
		swap(array, 0, i, size);
	}
}

