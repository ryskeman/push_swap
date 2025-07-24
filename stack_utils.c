/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:07:13 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/23 18:17:43 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Create a New Node with received value*/
t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_error();
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/* Add node in front of stack*/
void	add_front(t_node **head, t_node **tail, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
	if (!*tail)
		*tail = new_node;
}

/* Delete the first node in stack and returns it like 'pop'*/
t_node	*pop_front(t_node **head, t_node **tail, int *size)
{
	t_node	*tmp;

	if (!*head)
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	if (!*head)
		*tail = NULL;
	tmp->next = NULL;
	(*size)--;
	return (tmp);
}

/* Print stacks state. Only depuration */
void	print_stack(t_node *stack, const char *name, int size)
{
	ft_printf("%s (size %d):\n", name, size);
	if (!stack)
	{
		ft_printf("   [empty]\n");
		return ;
	}
	while (stack)
	{
		ft_printf("   %d\n", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

/* Free all stack memory */
void	free_stack(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
