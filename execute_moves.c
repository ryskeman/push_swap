/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernafer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:16:14 by fernando          #+#    #+#             */
/*   Updated: 2025/08/03 20:01:26 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_same_direction_rot(t_push_swap *data, t_rot_costs *rot_needs, int pos_a_target, int pos_b)
{
	// A CASE. Both rot up -> rr.
	if (pos_a_target <= data->size.a / 2 && pos_b <= data->size_b / 2)
	{
		while (rot_needs->ra > 0 && rot_needs->rb > 0)
		{
			rr(data);
			rot_needs->ra--;
			rot_needs->rb--;
		}
	}
	// B CASE. Both rot down -> rrr
	else if (pos_a_target > data->size_a / 2 && pos_b > data->size_b / 2)
	{
		while (rot_needs->rra > 0 && rot_needs->rrb > 0)
		{
			rrr(data);
			rot_needs->rra--;
			rot_needs->rrb--;
		}
	}
}

void	execute_remaining_rot(t_push_swap *data, t_rot_costs rot_needs)
{
	while (rot_needs.ra-- > 0)
		ra(data);
        while (rot_needs.rb-- > 0)
                rb(data);
        while (rot_needs.rra-- > 0)
                rra(data);
        while (rot_need.rrb-- > 0)
                rrb(data);
}

t_rot_costs	calculate_rot_needs(t_push_swap *data, t_node *b_node, t_node *target_a_node)
{
	t_rot_costs	rot_needs;
	int		pos_b;
	int		pos_a_target;

	pos_b = get_node_position(data->stack_b, b_node);
	pos_a_target = get_node_position(data->stack_a, target_a_node);
	rot_needs.ra = pos_a_target;
	rot_needs.rra = data->size_a - pos_a_target;
	rot_needs.rb = pos_b;
	rot_needs.rrb = data->size_b - pos_b;
	return (rot_needs);
}

// MODIFICAR FUNCION CON NUEVOS VALORES, ANIADIR PROTOTIPOS AL .H
void	execute_optimal_moves(t_push_swap *data, t_node *b_node_to_push, int ra_need, int rb_need, int rra_need, int rrb_need)
{
	t_node	*target_a_node;
	int		pos_b;
	int		pos_a_target;

	// 1. calculates position
	pos_b
}
