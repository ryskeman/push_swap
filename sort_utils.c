/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:59:20 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/05 19:26:41 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return 1 if stack A is sorted and stack B is empty, 0 otherwise. */
int	is_sorted(t_node *stack_a, t_node *stack_b)
{
	if (stack_b != NULL)
		return (0);
	if (stack_a == NULL || stack_a->next == NULL)
		return (1);
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

/* Sorts Stack A if it contains exactly two elements. */
void	sort_two(t_push_swap *data)
{
	if (data->size_a != 2)
		return ;
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}

/* Sorts Stack A if it contains exactly three elements. */
void	sort_three(t_push_swap *data)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = data->stack_a->value;
	n2 = data->stack_a->next->value;
	n3 = data->stack_a->next->next->value;
	if (is_sorted(data->stack_a, data->stack_b))
		return ;
	if (n1 > n2 && n1 < n3)
		sa(data);
	else if (n1 > n2 && n2 > n3)
	{
		sa(data);
		rra(data);
	}
	else if (n1 > n3 && n3 > n2)
		ra(data);
	else if (n2 > n1 && n1 > n3)
		rra(data);
	else if (n2 > n3 && n3 > n1)
	{
		sa(data);
		ra(data);
	}
}

/* Helper to find and push a specific indx from Stack A to stack B. */
static void	push_indx_to_b(t_push_swap *data, int target_idx)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = data->stack_a;
	while (current && current->index != target_idx)
	{
		current = current->next;
		pos++;
	}
	if (pos <= data->size_a / 2)
		while (data->stack_a->index != target_idx)
			ra(data);
	else
		while (data->stack_a->index != target_idx)
			rra(data);
	pb(data);
}

/* Sorts Stack A if it contains 4 or 5 elements. */
void	sort_five(t_push_swap *data)
{
	int		initial_size_a;

	if (is_sorted(data->stack_a, data->stack_b))
		return ;
	// Phase 1: push smallest elements to B.
	initial_size_a = data->size_a;
	push_indx_to_b(data, 0);
	// If original stack had 5 elements, index 1 to B.
	if (initial_size_a == 5)
		push_indx_to_b(data, 1);
	// Phase 2: Sort remaining 2 or 3 elememnts in A
	if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a == 2)
		sort_two(data);
	// Phase 3: Push elements back from B to A in correct order.
	while (data->size_b > 0)
		pa(data);
}
