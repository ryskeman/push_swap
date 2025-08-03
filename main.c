/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:38:23 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/03 01:46:21 by fernando         ###   ########.fr       */
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
	if (data.size_a >= 3)
	{
		ft_printf("\nTesting find_in_a.\n");
		t_node	test_b_node;
		test_b_node.value = 50;
		test_b_node.index = -1;
		t_node	test_b_node_small;
		test_b_node_small.value = -10000;
		t_node	test_b_node_large;
		test_b_node_large.value = 99999;

		ft_printf("Stack A inicial:\n");
		t_node	*current_a = data.stack_a;
		while(current_a)
		{
			ft_printf("  Value: %d, Index: %d\n", current_a->value, current_a->index);
			current_a = current_a->next;
		}
		t_node	*target1 = find_target_in_a(data.stack_a, &test_b_node);
		if (target1)
			ft_printf("Para b_node (value: %d), target en A es value: %d, index: %d\n", test_b_node.value, target1->value, target1->index);
		else
			ft_printf("Error: target para b_node (value: %d) no encontrado.\n", test_b_node.value);
		t_node *target2 = find_target_in_a(data.stack_a, &test_b_node_small);
		if (target2)
			ft_printf("Para b_node_small (value: %d), target en A es value: %d, index: %d\n", test_b_node_small.value, target2->value, target2->index);
		else
			ft_printf("Error: target para b_node_small (value: %d) no encontrado.\n", test_b_node_small.value);
		t_node *target3 = find_target_in_a(data.stack_a, &test_b_node_large);
		if (target3)
			ft_printf("Para b_node_large (value: %d), target en A es value: %d, index: %d\n", test_b_node_large.value, target3->value, target3->index);
		else
			ft_printf("Error: target para b_node_large (value: %d) no encontrado.\n", test_b_node_large.value);
		ft_printf("-------------------------------\n\n");
	}

	/* --- TEST END --- */
	if (is_sorted(data.stack_a, data.stack_b))
		ft_printf("\nStack ya ordenado al inicio.\n");
	else if (data.size_a == 2)
		sort_two(&data);
	else if (data.size_a == 3)
		sort_three(&data);
	else if (data.size_a <= 5)
		sort_five(&data);
	//Aqui llamaremos al algoritmo TURCO
	//else {main_sort_algorithm(&data);}
	cleanup_push_swap(&data);
	return (0);
}
