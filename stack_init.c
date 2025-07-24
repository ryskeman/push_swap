/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:13:42 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/24 02:46:27 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_and_fill(t_push_swap *data, int ac, char **av)
{
	int			i;
	t_node		*new_node_ptr;
	long long	num_ll;

	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->tail_a = NULL;
	data->tail_b = NULL;
	i = ac - 1;
	while (i >= 1)
	{
		num_ll = ft_atol(av[i]);
		new_node_ptr = new_node((int)num_ll);
		add_front(&(data->stack_a), &(data->tail_a), new_node_ptr);
		data->size_a++;
		i--;
	}
	assign_index(data);
}

/* Aux function to print stack a with values and index. For Debugging */

void	print_initial_stack(t_push_swap *data)
{
	t_node	*current;

	ft_printf("\n--- Stack A Inicial (Valores e Indices) ---\n");
	current = data->stack_a;
	while (current)
	{
		ft_printf("Value: %d, Index: %d\n", current->value, current->index);
		current = current->next;
	}
	ft_printf("---------------------------------------------\n");
}
