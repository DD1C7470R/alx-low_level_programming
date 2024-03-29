#include "lists.h"

/**
 * add_dnodeint_end - Add a new node at the end of a `dlistint_t` list
 * @head: double pointer to head node
 * @n: value to store in new node
 * Return: Address of new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *current = *head;
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (current == NULL)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = new_node;
		new_node->prev = current;
		current = new_node;
	}

	return (new_node);
}

