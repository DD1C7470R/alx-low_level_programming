#include "search_algos.h"

/**
 * interpolation_search - Performs a linear search for a key value
 * @array: Array to search value
 * @size: size of input array
 * @value: value to search
 * Return: 1 if found and -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	int low = 0;
	int high = size - 1;
	int mid;

	if (!array)
		return (-1);

	while (
		(array[high] != array[low]) && (value >= array[low])
		&& (value <= array[high])
	)
	{
		mid = low + ((value - array[low])
				* (high - low) / (array[high] - array[low]));
		printf("Value checked array[%d] = [%d]\n", mid, array[mid]);

		if (array[mid] < value)
			low = mid + 1;
		else if (value < array[mid])
			high = mid - 1;
		else
			return (mid);
	}

	if (value == array[low])
		return (low);
	else
		return (-1);
}

