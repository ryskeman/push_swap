/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:49:38 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/02 16:30:12 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_node **head, t_node **tail, int *size)
{
	t_node	*old_first;

	if (*size < 2 || !*head || !(*head)->next)
		return ;
	old_first = *head;
	*head = (*head)->next;
	(*tail)->next = old_first;
	old_first->next = NULL;
	*tail = old_first;
}

void	ra(t_push_swap *data)
{
	ft_rotate(&(data->stack_a), &(data->tail_a), &(data->size_a));
	ft_printf("ra\n");
	//print_stacks_debug(data);
}

void	rb(t_push_swap *data)
{
	ft_rotate(&(data->stack_b), &(data->tail_b), &(data->size_b));
	ft_printf("rb\n");
	//print_stacks_debug(data);
}

void	rr(t_push_swap *data)
{
	ft_rotate(&(data->stack_a), &(data->tail_a), &(data->size_a));
	ft_rotate(&(data->stack_b), &(data->tail_b), &(data->size_b));
	ft_printf("rr\n");
	//print_stacks_debug(data);
}
