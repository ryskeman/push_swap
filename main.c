/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:38:23 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/24 02:45:01 by fernafer         ###   ########.fr       */
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

	/* 4. Executing sort algorithm */
	//TO DO

	/* 5. Print instructions list */
	//TO DO

	/* 6. Free memory */
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	return (0);
}
