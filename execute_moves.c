/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:16:14 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/11 00:33:47 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute rotations in samne direction (rr, rrr) */
void	execute_same_direction_rot(t_push_swap *data, t_rot_costs *rot_needs,
		int pos_a_target, int pos_b)
{
	// A CASE. Both rot up -> rr.
	if (pos_a_target <= data->size_a / 2 && pos_b <= data->size_b / 2)
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

/* Execute individual rotations in A and B*/
void	execute_remaining_rot(t_push_swap *data, t_rot_costs rot_needs)
{
	if (rot_needs.ra > 0)
		while (rot_needs.ra-- > 0)
			ra(data);
	else if (rot_needs.rra > 0)
		while (rot_needs.rra-- > 0)
			rra(data);
	if (rot_needs.rb > 0)
		while (rot_needs.rb-- > 0)
			rb(data);
	else if (rot_needs.rrb > 0)
		while (rot_needs.rrb-- > 0)
			rrb(data);
}

t_rot_costs	calculate_rot_needs(t_push_swap *data, t_node *b_node,
		t_node *target_a_node)
{
	t_rot_costs	rot_needs;
	int			pos_b;
	int			pos_a_target;

	pos_b = get_node_position(data->stack_b, b_node);
	pos_a_target = get_node_position(data->stack_a, target_a_node);
	rot_needs.ra = pos_a_target;
	rot_needs.rra = data->size_a - pos_a_target;
	rot_needs.rb = pos_b;
	rot_needs.rrb = data->size_b - pos_b;
	return (rot_needs);
}

// MODIFICAR FUNCION CON NUEVOS VALORES, ANIADIR PROTOTIPOS AL .H
void	execute_optimal_moves(t_push_swap *data, t_node *b_node_to_push)
{
	t_node		*target_a_node;
	t_rot_costs	rot_needs;

	// 1. calculates position
	target_a_node = find_target_in_a(data->stack_a, b_node_to_push);
	// 2. Calculates number of rot needed.
	rot_needs = calculate_rot_needs(data, b_node_to_push, target_a_node);
	// 3. Exec sync rotations(rr, rrr)
	execute_same_direction_rot(data, &rot_needs,
		get_node_position(data->stack_a, target_a_node),
		get_node_position(data->stack_b, b_node_to_push));
	// 4. Exec remaining individual rotations
	execute_remaining_rot(data, rot_needs);
	// 5. Finally moves node B to A
	pa(data);
}
