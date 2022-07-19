#include "sort.h"
#include <stdio.h>
/**
 * swap - swap the elements in the array
 * @array: array
 * @curr_index: current index
 * @p_index: pivot index
 */

void swap(int *array, int curr_index, int p_index)
{
	int temp;

	temp = array[curr_index];
	array[curr_index] = array[p_index];
	array[p_index] = temp;
}

/**
 * heapify - creates a max heap
 * @array: array of integers
 * @size: size of array
 * @parent_idx: parent node index
 * @t_size: Total size of array
 */

void heapify(int *array, int size, int parent_idx, int t_size)
{
	int largest_idx, lt_child_idx, rt_child_idx, tmp;

	largest_idx = parent_idx;
	lt_child_idx = (parent_idx * 2) + 1;
	rt_child_idx = (parent_idx * 2) + 2;

	if (lt_child_idx < size && array[lt_child_idx] > array[largest_idx])
		largest_idx = lt_child_idx;

	if (rt_child_idx < size && array[rt_child_idx] > array[largest_idx])
		largest_idx = rt_child_idx;

	if (largest_idx != parent_idx)
	{
		tmp = array[parent_idx];
		array[parent_idx] = array[largest_idx];
		array[largest_idx] = tmp;
		print_array(array, t_size);
		heapify(array, size, largest_idx, t_size);
	}
}

/**
 * heap_sort - Implementation of heap_sort algorithm
 * @array: array of integers
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int last_parent_idx, i, tmp;

	if (!array || size < 2)
		return;

	last_parent_idx = ((int)size - 1) / 2;
	for (i = last_parent_idx; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

