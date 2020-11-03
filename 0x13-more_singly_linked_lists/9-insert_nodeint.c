#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * listint_len - counts number of elements in a list
 * @h: head of list
 *
 * Return: # of nodes
 */

size_t listint_len(const listint_t *h)
{
	const listint_t *scout = h;
	size_t node_count = 0;

	while (scout != NULL)
	{
		node_count++;
		scout = scout->next;
	}
	return (node_count);
}

/**
 * get_nodeint_at_index - returns node at given index
 * @head: the list
 * @index: index of the node starting at 0
 *
 * Return: Address of new node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;
	unsigned int current_index = 0;

	if (head == NULL)
		return (NULL);

	current = head;
	while (current != NULL)
	{
		if (current_index == index)
			return (current);
		current_index++;
		current = current->next;
	}
	return (NULL);
}

/**
 * add_nodeint - adds node to list
 * @head: the list
 * @n: a number
 *
 * Return: Address of new node
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (*head);
}

/**
 * insert_nodeint_at_index - inserts a node at index
 * @head: the list
 * @idx: index
 * @n: a number
 *
 * Return: Address of new node or NULL if failure
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp_head, *current, *temp, *new;
	unsigned int len = 0;

	temp_head = *head;
	len = listint_len(temp_head);
	if (head == NULL || *head == NULL || idx == len)
		return (add_nodeint_end(head, n));
	if (idx == 0)
		return (add_nodeint(head, n));
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	temp = get_nodeint_at_index(temp_head, idx);
	current = get_nodeint_at_index(temp_head, idx - 1);
	if (current == NULL || temp == NULL)
	{
		free(new);
		return (NULL);
	}
	current->next = new;
	new->next = temp;
	return (new);
}
