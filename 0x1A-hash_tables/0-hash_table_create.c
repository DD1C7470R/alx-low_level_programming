#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: size of table to create
 * Return: nothing.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *mytable = malloc(sizeof(hash_table_t *) * size);

	if (mytable == NULL)
	{
		return (NULL);
	}
	mytable->size = size;
	mytable->counter = 0;
	mytable->array = malloc(sizeof(hash_node_t *) * size);
	if (mytable->array == NULL)
	{
		return (NULL);
	}
	return (mytable);
}

