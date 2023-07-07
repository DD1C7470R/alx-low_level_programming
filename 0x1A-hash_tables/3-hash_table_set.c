#include "hash_tables.h"

/**
 * hash_table_set - implementation of table insertion
 * @ht: table to insert data
 * @key: key of value to insert
 * @key: value of key to insert
 * Return: hash value
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long index;
	hash_node_t *current_item;

	if (ht == NULL || strlen(key) == 0 || strlen(value) == 0)
		return (0);


	index = key_index((const unsigned char *)key, ht->size);
	current_item = ht->array[index];

	while (current_item != NULL)
	{
		if (strcmp(current_item->key, key) == 0)
		{
			free(current_item->value);
			current_item->value = strdup(value);
			return (1);
		}
		current_item = current_item->next;
	}

	hash_node_t *item = malloc(sizeof(hash_node_t));

	if (item == NULL)
	{
		free(item->key);
		free(item->value);
		free(item);
		return (0);
	}

	item->key = strdup(key);
	item->value = strdup(value);

	item->next = ht->array[index];
	ht->array[index] = item;

	return (1);
}


