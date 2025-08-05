/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 00:53:50 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/05 20:16:26 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --- AUX FUNCTIONS FOR TURKISH SORT. --- */
/* Target is the first node in A that is greater than node from B. */
t_node	*find_target_in_a(t_node *stack_a_head, t_node *b_node)
{
	t_node	*target_node;
	t_node	*current_a;
	t_node	*smallest_a;
	long	min_diff;

	target_node = NULL;
	min_diff = 2147483647;
	current_a = stack_a_head;
	while (current_a)
	{
		/* case 1: B match A. Find first element > b_node->value */
		if (b_node->value < current_a->value
			&& current_a->value - b_node->value < min_diff)
		{
			min_diff = current_a->value - b_node->value;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	/* Case 2: B is the smallest or biggest, if not match with
		bigger target B is biggest. */
	if (target_node == NULL)
	{
		current_a = stack_a_head;
		target_node = current_a;
		if (!target_node)
			return (NULL);
		smallest_a = stack_a_head;
		while (current_a)
		{
			if (current_a->index < smallest_a->index)
				smallest_a = current_a;
			current_a = current_a->next;
		}
		target_node = smallest_a;
	}
	return (target_node);
}

/* Gets the current position of node in Stack. */
int	get_node_position(t_node *stack_head, t_node *node_to_find)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack_head;
	while (current)
	{
		if (current == node_to_find)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

/* Get the cheapest node move from stack B to A. */
t_node	*get_cheapest_node(t_push_swap *data)
{
	t_node	*cheapest;
	t_node	*current_b;
	int		min_cost;
	int		current_cost;

	cheapest = NULL;
	min_cost = 2147483647;
	current_b = data->stack_b;
	while (current_b)
	{
		current_cost = calculate_total_push_cost(data, current_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = current_b;
		}
		current_b = current_b->next;
	}
	return (cheapest);
}

/* --- TURKISH MAIN FUNCTION ARCHITECTURE --- */
void	sort_big(t_push_swap *data)
{
	t_node	*cheapest_node;

	// 1. Phase: Push initial elements from A to B, except 0, 1, 2 index.
	while (data->size_a > 3)
	{
		if (data->stack_a->index == 0
			|| data->stack_a->index == 1
			|| data->stack_a->index == 2)
			ra(data);
		else
			pb(data);
	}
	if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a == 2)
		sort_two(data);
	// 2. Phase: Main loop-> while B is not empty.
	while (data->size_b > 0)
	{
		cheapest_node = get_cheapest_node(data);
		// ONLY FOR OUTPUT DEBUGG
		// if (cheapest_node)
		// 	ft_printf("\n--> Nodo mas barato en B para empujar a A: %d (indice %d) con costo %d\n", cheapest_node->value, cheapest_node->index, calculate_total_push_cost(data, cheapest_node));
		// else
		// 	ft_printf("\nNo se encontro nodo mas barato en B. Esto no deber'ia pasar si size_b > 0.\n");
		// AQUI SIGUIENTE PASO PARA EJECUTAR MOVIMIENTOS.
		execute_optimal_moves(data, cheapest_node);
	}
	// 3. Phase: Rotate A if needed.
}
