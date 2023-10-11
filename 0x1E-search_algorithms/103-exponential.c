#include "search_algos.h"


/**
 * bin_search - Performs a linear search for a key value
 * @array: Array to search value
 * @size: size of input array
 * @value: value to search
 * @bound: boundary to find value
 * Return: 1 if found and -1 if not found
 */
int bin_search(int *array, int bound, size_t size, int value)
{
	size_t i = 0, first_idx = bound / 2, mid, last_idx;
	
	if (array == NULL || size == 0)
	{
		return (-1);
	}
	last_idx = bound - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", first_idx, last_idx);
	while (first_idx <= last_idx)
	{
		mid = first_idx + (last_idx - first_idx) / 2;
		printf("Searching in array: ");
		for (i = first_idx; i <= last_idx; i++)
		{
			printf("%d", array[i]);
			if (i < last_idx)
			{
				printf(", ");
			}
		}
		printf("\n");
		if (array[mid] == value)
		{
			printf("\n");
			return (mid);
		}
		else if (array[mid] < value)
		{
			first_idx = mid + 1;
		}
		else
		{
			last_idx = mid - 1;
		}
	}
	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: index if found and -1 if not
 */
int exponential_search(int *array, size_t size, int value)
{
	int i, prev;

	if (!array || size == 0 || value < array[0])
		return (-1);
	for (i = 1, prev = 1; 1; i *= 2)
	{
		if (i >= (int)size || array[i] >= value)
		{
			if (i >= (int)size)
				i = size - 1;
			printf("Value found between indexes [%d] and [%d]\n", prev, i);
			return (bin_search(array, prev, i, value));
		}
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		prev = i;
	}
	return (-1);
}
