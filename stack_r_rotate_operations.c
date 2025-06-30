/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:11:33 by fernafer          #+#    #+#             */
/*   Updated: 2025/06/30 16:43:09 by fernando         ###   ########.fr       */
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
	write (1, "rra\n", 4);
}

void	rrb(t_push_swap *data)
{
	ft_reverse_rotate(&(data->stack_b), &(data->tail_b), &(data->size_b));
	write (1, "rrb\n", 4);
}

void	rrr(t_push_swap *data)
{
	ft_reverse_rotate(&(data->stack_a), &(data->tail_a), &(data->size_a));
	ft_reverse_rotate(&(data->stack_b), &(data->tail_b), &(data->size_b));
	write (1, "rrr\n", 4);
}
