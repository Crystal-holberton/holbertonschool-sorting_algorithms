#include "sort.h"

/**
 * swap - swaps two elements in array
 * @a: first element
 * @b: second element
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - partition array and pivot
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of array
 * Return: index of pivot after partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
		j++;
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursively sorts array using quick sort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of array
 * Return: void
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}
