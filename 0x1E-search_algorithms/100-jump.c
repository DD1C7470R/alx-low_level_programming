#include "search_algos.h"
#include <math.h>


/**
 * jump_search - Performs a linear search for a key value
 * @array: Array to search value
 * @size: size of input array
 * @value: value to search
 * Return: 1 if found and -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int step;
	int prev = 0, i;

	if (array == NULL || size == 0)
		return (-1);

	step = (int)sqrt(size);
	while (array[prev] < value)
	{
		int cur = fmin(prev + step, size);

		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[cur] >= value)
		{
			printf("Value found between indexes [%d] and [%d]\n", prev, prev + step);
			for (i = prev; i <= cur; i++)
			{
				if (i <= (int)(size - 1))
				{
					printf("Value checked array[%d] = [%d]\n", i, array[i]);
					if (array[i] == value)
					{
						return (i);
					}
				}
			}
			return (-1);
		}

		prev = cur;
		if (prev >= (int)size)
		{
			return (-1);
		}
	}
	return (-1);
}

