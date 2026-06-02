#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* Parcourir jusqu'à l'index */
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	/* Si l'index est hors limite */
	if (current == NULL)
		return (-1);

	/* Si c'est le premier nœud (tête) */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		/* Relier le précédent au suivant */
		current->prev->next = current->next;
		/* Relier le suivant au précédent (s'il existe) */
		if (current->next != NULL)
			current->next->prev = current->prev;
	}

	free(current);
	return (1);
}