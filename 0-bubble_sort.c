#include "sort.h"

/**
 * exchange_ints - Swap two integers in an array.
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
 * bubble_sort - function to sort integers in an array in ascending order.
 * @array: integers in the array to be sorted.
 * @size: array size of the func
 *
 * Description: the array is printed after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	booleans bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				exchange_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
