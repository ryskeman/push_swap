/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:38:23 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/24 12:51:28 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	data;

	/* 1. Initial validation of arguments */
	check_arguments(ac, av);

	/* 2. Init and fill stack_a with argv values convert in int */
	init_and_fill(&data, ac, av);

	/* 3. Add index at stack elements (Debugging) */
	print_initial_stack(&data);

	/* 4. Executing sort algorithm and print instructions list. */
	if (is_sorted(data.stack_a, data.stack_b))
		ft_printf("\nStack ya ordenado al inicio.\n");
	else if (data.size_a == 2)
		sort_two(&data);
	else if (data.size_a == 3)
		sort_three(&data);
	//else if (data.size <= 5){ sort_five(&data);}
	//else {main_sort_algorithm(&data);}

	/* 5. Free memory */
	if (is_sorted(data.stack_a, data.stack_b))
		ft_printf("\nRESULTADO FINAL: STACK A ORDENADO Y B VACIO. OK!.\n");
	else
		ft_printf("\nRESULTADO FINAL: STACK A NO ORDENADO  B NO VACIO. KO!.\n");
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	return (0);
}
