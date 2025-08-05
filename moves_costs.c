/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:28:21 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/05 21:19:10 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that finds node by index. */
t_node	*find_node_by_index(t_node *head, int target_index)
{
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->index == target_index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

/* Get the cheapest rotations costs. */
int	get_cheap_rot_cost(t_node *stack_head, t_node *node_to_move, int stack_size)
{
	int	pos;
	int	cost_ra_rb;
	int	cost_rra_rrb;

	pos = get_node_position(stack_head, node_to_move);
	// If node is in first half of stack is cheaper rot up.
	if (pos <= stack_size / 2)
	{
		cost_ra_rb = pos;
		return (cost_ra_rb);
	}
	else
	{
		cost_rra_rrb = stack_size - pos;
		return (cost_rra_rrb);
	}
}

/* Calculates individual cost of rotations moves. */
void	get_indiv_rot_cost(t_push_swap *data, t_node *b_node, int *cost_a_ptr,
		int *cost_b_ptr)
{
	t_node	*target_node_a;

	// 1. Get target A node for current b_node.
	target_node_a = find_target_in_a(data->stack_a, b_node);
	// 2. Calculate B rotation cost to push up.
	*cost_b_ptr = get_cheap_rot_cost(data->stack_b, b_node, data->size_b);
	// 3. Calculate A rotation cost to push up.
	*cost_a_ptr = get_cheap_rot_cost(data->stack_a, target_node_a,
			data->size_a);
}

/* Get final total costs. */
int	get_final_total_cost(t_push_swap *data, int cost_a, int cost_b,
		t_node *b_node)
{
	int		total_cost;
	int		pos_b;
	int		pos_a_target;
	t_node	*target_node_a;

	target_node_a = find_target_in_a(data->stack_a, b_node);
	pos_b = get_node_position(data->stack_b, b_node);
	pos_a_target = get_node_position(data->stack_a, target_node_a);
	total_cost = cost_a + cost_b;
	// If both rotates up...
	if (pos_a_target <= data->size_a / 2 && pos_b <= data->size_b / 2)
	{
		if (cost_a > cost_b)
			total_cost = cost_a;
		else
			total_cost = cost_b;
	}
	// Else both rotates down..
	else if (pos_a_target > data->size_a / 2 && pos_b > data->size_b / 2)
	{
		if (cost_a > cost_b)
			total_cost = cost_a;
		else
			total_cost = cost_b;
	}
	//total_cost++;
	return (total_cost);
}

/* Calculate total moves costs. */
int	calculate_total_push_cost(t_push_swap *data, t_node *b_node)
{
	int	cost_a;
	int	cost_b;
	int	total_cost;

	get_indiv_rot_cost(data, b_node, &cost_a, &cost_b);
	total_cost = get_final_total_cost(data, cost_a, cost_b, b_node);
	return (total_cost);
}
