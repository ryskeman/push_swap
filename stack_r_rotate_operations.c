/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:11:33 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/24 12:00:52 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_node **head, t_node **tail, int *size)
{
	t_node	*old_first;
	t_node	*old_last;
	t_node	*second_last;

	if (*size < 2 || !*head || !(*head)->next)
		return ;
	old_first = *head;
	old_last = *tail;
	second_last = old_first;
	while (second_last->next != old_last)
		second_last = second_last->next;
	second_last->next = NULL;
	old_last->next = old_first;
	*head = old_last;
	*tail = second_last;
}

void	rra(t_push_swap *data)
{
	ft_reverse_rotate(&(data->stack_a), &(data->tail_a), &(data->size_a));
	ft_printf("rra\n");
}

void	rrb(t_push_swap *data)
{
	ft_reverse_rotate(&(data->stack_b), &(data->tail_b), &(data->size_b));
	ft_printf("rrb\n");
}

void	rrr(t_push_swap *data)
{
	ft_reverse_rotate(&(data->stack_a), &(data->tail_a), &(data->size_a));
	ft_reverse_rotate(&(data->stack_b), &(data->tail_b), &(data->size_b));
	ft_printf("rrr\n");
}
