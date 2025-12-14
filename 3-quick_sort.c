#include "sort.h"

/**
 * swap - Swaps two integers and prints the array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * @array: The array being sorted (for printing)
 * @size: Number of elements in the array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions a subarray using Lomuto scheme
 *
 * @array: The array being sorted
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray (pivot is array[high])
 * @size: Number of elements in the array
 *
 * Return: The final index of the pivot element
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j], array, size);
			i++;
		}
	}
	swap(&array[i], &array[high], array, size);
	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts subarrays using Quick sort
 *
 * @array: The array being sorted
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, low, high, size);

		if (p > 0)
			quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}
/**
 * quick_sort - Quick sort an array using Lomuto scheme
 *
 * @array: The array to sort
 * @size: Number of elements
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
