/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:38:23 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/05 18:53:18 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Handles initial argument checking, stack init, and printing. */
static void	setup_push_swap(t_push_swap *data, int ac, char **av)
{
	check_arguments(ac, av);
	init_and_fill(data, ac, av);
	print_initial_stack(data);
}

/* Handles final result validation and memory deallocation. */
static void	cleanup_push_swap(t_push_swap *data)
{
	if (is_sorted(data->stack_a, data->stack_b))
		ft_printf("\nOK!\n");
	else
		ft_printf("\nKO!\n");
	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
}

/* --- MAIN FUNCTION --- */
int	main(int ac, char **av)
{
	t_push_swap	data;

	setup_push_swap(&data, ac, av);
	/* --- TEMP TEST --- */
	/* --- TEST END --- */
	if (is_sorted(data.stack_a, data.stack_b))
		ft_printf("\nStack ya ordenado al inicio.\n");
	else if (data.size_a == 2)
		sort_two(&data);
	else if (data.size_a == 3)
		sort_three(&data);
	else if (data.size_a <= 5)
		sort_five(&data);
	else
		sort_big(&data);
	cleanup_push_swap(&data);
	return (0);
}
