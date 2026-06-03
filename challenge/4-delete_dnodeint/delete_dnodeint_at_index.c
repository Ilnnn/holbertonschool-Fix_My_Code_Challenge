int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp = *head;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    /* 1. Trouver le nœud à supprimer */
    while (tmp != NULL && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    /* Si l'index est hors limites */
    if (tmp == NULL)
        return (-1);

    /* 2. Suppression de la tête */
    if (tmp == *head)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    /* 3. Suppression au milieu ou à la fin */
    else
    {
        tmp->prev->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp->prev;
    }

    free(tmp);
    return (1);
}
