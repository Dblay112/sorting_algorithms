#include "sort.h"

void swap_ints(int *a, int *b);
int lomutopart(int *array, size_t size, int up, int down);
void sortlomuto(int *array, size_t size, int up, int down);
void quick_sort(int *array, size_t size);

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
 * lomutopart - function that implements the lomuto partion scheme
 * @array: integers array
 * @size: array size
 * @up: beginning of the index of the subset
 * @down: the end of the index of the subset
 *
 * Return: final index of the partition
 */
int lomutopart(int *array, size_t size, int up, int down)
{
	int *center, top, bottom;

	center = array + down;
	for (top = bottom = up; bottom < down; bottom++)
	{
		if (array[bottom] < *center)
		{
			if (top < bottom)
			{
				exchange_ints(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *center)
	{
		exchange_ints(array + top, center);
		print_array(array, size);
	}

	return (top);
}

/**
 * sortlomuto - function to implement quick sort.
 * @array: array of the integers to use in sorting.
 * @size: array size.
 * @up: top index of the array.
 * @down: end index of the array.
 *
 */
void sortlomuto(int *array, size_t size, int up, int down)
{
	int portion;

	if (down - up > 0)
	{
		portion = lomutopart(array, size, up, down);
		sortlomuto(array, size, up, portion - 1);
		sortlomuto(array, size, portion + 1, down);
	}
}

/**
 * quick_sort - quick sort function
 * @array: integers array
 * @size: array size
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sortlomuto(array, size, 0, size - 1);
}
