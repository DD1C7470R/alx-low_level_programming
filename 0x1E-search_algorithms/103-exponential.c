#include "search_algos.h"



/**
 * _binary_search - searches for a value in a sorted array of integers
 * using the binary search algorithm
 * @array: array of integers
 * @left: Left element
 * @right: Right element
 * @value: value to search for
 * Return: index of value or -1 if not found
 */

int _binary_search(int *array, size_t left, size_t right, int value)
{

	size_t i;

	if (array == NULL)
		return (-1);

	while (right > left)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
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
			return (_binary_search(array, prev, i, value));
		}
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		prev = i;
	}
	return (-1);
}
