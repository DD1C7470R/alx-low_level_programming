#include "search_algos.h"

/**
 * interpol_search_rec - Recursive interpolation search
 * @array: Array to search in
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @value: Value to search
 * @size: Size of the array
 * Return: Index of the found value or -1 if not found
 */
int interpol_search_rec(int *array, int low, int high, int value, size_t size)
{
	int pos = low + ((double)(high - low)
			/ (array[high] - array[low])) * (value - array[low]);
	if (pos > high)
	{
		printf("Value checked array[%d] is out of range\n", pos);
		return (-1);
	}
	if (pos <= high)
	{
		printf("Value checked array[%d] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);

		if (array[pos] < value)
			return (interpol_search_rec(array, pos + 1, high, value, size));

		return (interpol_search_rec(array, low, pos - 1, value, size));
	}

	printf("Value checked array[%d] is out of range\n", low);

	return (-1);
}

/**
 * interpolation_search - Initiates interpolation search
 * @array: Array to search in
 * @size: Size of the array
 * @value: Value to search
 * Return: Index of the found value or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (interpol_search_rec(array, 0, size - 1, value, size));
}

