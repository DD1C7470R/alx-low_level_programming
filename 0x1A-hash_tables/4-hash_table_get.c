#include "hash_tables.h"


/**
 * hash_table_get - implementation of
 * table value retreival
 * @ht: table to insert data
 * @key: key of value to insert
 * Return: found value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long index;
	hash_node_t *current_item;

	if (ht == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)strdup(key), ht->size);
	current_item = ht->array[index];

	if (current_item != NULL)
	{
		if (strcmp(current_item->key, key) == 0)
			return (current_item->value);
	}

	return (NULL);
}
