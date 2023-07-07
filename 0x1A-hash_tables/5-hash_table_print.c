#include "hash_tables.h"


/**
 * hash_table_print - Print a hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx;
	int count;
	hash_node_t *current;

	if (ht == NULL)
		return;


	if (ht != NULL)
	{
		for (idx = 0, count = 0; idx < ht->size; idx++)
		{
			current = ht->array[idx];

			if (current != NULL)
			{
				if (count == 1)
					printf(", ");
				printf("'%s': '%s'", current->key, current->value);

				while (current->next != NULL)
				{
					printf(", ");
					printf("'%s': '%s'", current->key, current->value);

					current->next = current->next;
				}
				count = 1;
			}
		}
	}
}



