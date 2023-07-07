#include "hash_tables.h"


/**
 * key_index - implementation of the key index
 * @key: string used to generate hash value
 * @size: size of table
 * Return: an index a unsigned long int
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;
	unsigned long int index;

	if (size == 0 || strlen((const char *)key) == 0)
		return (0);

	hash = hash_djb2(key);
	index = hash % size;

	return (index);
}

