#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Supprime le nœud à un index donné
 * @head: Pointeur vers le pointeur du premier élément
 * @index: Index du nœud à supprimer
 * * Return: 1 en cas de succès, -1 en cas d'échec
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp = *head;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    /* Trouver le nœud à supprimer */
    while (tmp != NULL && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    /* Si l'index est hors limites */
    if (tmp == NULL)
        return (-1);

    /* Si c'est la tête */
    if (tmp == *head)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Relier le nœud précédent au nœud suivant */
        tmp->prev->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp->prev;
    }

    free(tmp);
    return (1);
}
