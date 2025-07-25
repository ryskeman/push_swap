/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 20:12:53 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/24 11:58:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *data)
{
	t_node	*node_to_move;

	if (data->size_b == 0 || !data->stack_b)
		return ;
	node_to_move = pop_front(&(data->stack_b), &(data->tail_b),
			&(data->size_b));
	add_front(&(data->stack_a), &(data->tail_a), node_to_move);
	data->size_a++;
	ft_printf("pa\n");
}

void	pb(t_push_swap *data)
{
	t_node	*node_to_move;

	if (data->size_a == 0 || !data->stack_a)
		return ;
	node_to_move = pop_front(&(data->stack_a), &(data->tail_a),
			&(data->size_a));
	add_front(&(data->stack_b), &(data->tail_b), node_to_move);
	data->size_b++;
	ft_printf("pb\n");
}
