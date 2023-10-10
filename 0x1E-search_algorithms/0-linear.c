#include "search_algos.h"

/**
 * linear_search - Performs a linear search for a key value
 * @array: Array to search value
 * @size: size of input array
 * @value: value to search
 * Return: 1 if found and -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (size == 0 || array == NULL)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}

