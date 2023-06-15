#include "lists.h"

/**
 * add_dnodeint - Add a new node at the beginning of a `dlistint_t` list
 * @head: double pointer to head node
 * @n: value to store in node
 * Return: address of new node, or NULL if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
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

		(*head)->prev = new_node;
		new_node->next = *head;
		*head = new_node;
	}

	return (*head);
}

