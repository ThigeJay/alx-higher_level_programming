#include "lists.h"

/**
 * check_cycle - Determines if a linked list has a cycle
 * @head: Pointer to the head of the linked list
 *
 * Return: 1 if a cycle is detected, 0 otherwise
 */
int check_cycle(listint_t *head)
{
	listint_t *turtle = head;	/* Slow-moving pointer */
	listint_t *hare = head;		/* Fast-moving pointer */

	if (!head)
		return (0);

	while (turtle && hare && hare->next)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (turtle == hare)
			return (1);	/* Cycle detected */
	}

	return (0);	/* No cycle found */
}
