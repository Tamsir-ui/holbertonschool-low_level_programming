#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node is added
 * @n: value to store in the new node
 *
 * Return: address of new node, or NULL if failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp = *h;
	unsigned int i = 0;

	/* Insert at beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Move temp to idx - 1 */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* If temp is NULL, index is too high */
	if (temp == NULL)
		return (NULL);

	/* Insert at the end */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Normal insertion */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = temp->next;
	new->prev = temp;

	temp->next->prev = new;
	temp->next = new;

	return (new);
}
