#include "lists.h"

/**
 * insert_dnodeint_at_index - insert a new node at given position
 * @h: double pointer to head
 * @idx: index to insert into
 * @n: value to store in new node
 * Return: Address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
        dlistint_t *current = *h;
        dlistint_t *new_node = NULL;

        new_node = malloc(sizeof(dlistint_t));
        if (new_node == NULL)
        {
                free(new_node);
                return (NULL);
        }
        new_node->n = n;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (idx == 0 && current != NULL)
        {
                new_node->next = (*h);
                if (*h != NULL)
                {
                    (*h)->prev = new_node;
                }
                *h = new_node;
                return (new_node);
        }

        while (idx > 0 && current != NULL)
        {
                if (idx - 1 == 0)
                {
                        new_node->prev = current;
                        new_node->next = current->next;
                        if (current->next != NULL)
                        {
                                current->next->prev = new_node;
                        }
                        current->next = new_node;
                        return (new_node);
                }
                current = current->next;
                idx -= 1;
        }
        return (NULL);
}

