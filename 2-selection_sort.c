#include "sort.h"

/**
 * exchange_ints - interchanges two integers in an array.
 * @a: first of the integers to swap
 * @b: second of the integers to swap.
 */
void exchange_ints(int *a, int *b)
{
	int ex;

	ex = *a;
	*a = *b;
	*b = ex;
}

/**
 * selection_sort - selection sort array used to sort array of integers.
 * @array: array integers
 * @size: array size
 *
 */
void selection_sort(int *array, size_t size)
{
	int *ints;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		ints = array + i;
		for (j = i + 1; j < size; j++)
			ints = (array[j] < *ints) ? (array + j) : ints;

		if ((array + i) != ints)
		{
			swap_ints(array + i, ints);
			print_array(array, size);
		}
	}
}
