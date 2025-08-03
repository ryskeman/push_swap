/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernafer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 00:53:50 by fernando          #+#    #+#             */
/*   Updated: 2025/08/03 02:31:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --- AUX FUNCTIONS FOR TURKISH SORT. --- */
/* Target is the first node in A that is greater than node from B. */
t_node	*find_target_in_a(t_node *stack_a_head, t_node *b_node)
{
	t_node	*target_node;
	t_node	*current_a;
	long	min_diff;

	target_node = NULL;
	min_diff = 2147483647;

	current_a = stack_a_head;
	while (current_a)
	{
		/* case 1: B match A. Find first element > b_node->value */
		if (b_node->value < current_a->value && current_a->value - b_node->value < min_diff)
		{
			min_diff = current_a->value - b_node->value;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	/* Case 2: B is the tyniest or biggest, if not match with bigger target B is biggest. */
	if (target_node == NULL)
	{
		current_a = stack_a_head;
		target_node = current_a;
		while (current_a)
		{
			if (current_a->index < target_node->index)
				target_node = current_a;
			current_a = current_a->next;
		}
	}
	return (target_node);
}

/* --- TURKISH MAIN FUNCTION ARCHITECTURE --- */
void	sort_big(t_push_swap *data)
{
	// 1. Phase: Push initial elements from A to B, except 0, 1, 2 index.
	while (data->size_a > 3)
	{
		if (data->stack_a->index == 0 || data->stack_a->index == 1 || data->stack_a->index == 2)
			ra(data);
		else
			pb(data);
	}
	// 2. Phase: Main loop-> while B is not empty.
	// 3. Phase: Rotate A if needed.
}
