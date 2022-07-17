#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * Knuth sequence: n+1 = n * 3 + 1
 * 1, 4, 13, 40, 121, ...
 * @array: given array
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h;
	int temp, didSwap = 0;

	if (size < 2)
		return;

	/* get initial maximum gap (h) */
	h = 1;
	while (h < size)
		h = h * 3 + 1;

	while (h >= 1)
	{
		didSwap = 0;
		for (i = h; i < size; i++)
		{
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
			{
				temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
				didSwap = 1;
			}
		}
		/* decrease h */
		h /= 3;
		if (didSwap)
			print_array(array, size);
	}
}
