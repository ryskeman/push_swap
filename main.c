/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:38:23 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/23 19:14:45 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	data;
	t_node		*new_node_ptr;
	int			i;
	long long	num_ll;
	t_node		*current;

	/* 1. Initial validation of arguments */
	check_arguments(ac, av);
	// /* Temporal debugging message */
	// ft_printf("Todos los argumentos son validos y sin duplicados.\n");
	// ft_printf("Listo para construir el stack 'a' y comenzar el ordenamiento.\n");

	/* 2. Init stacks */
	data.stack_a = NULL;
	data.stack_b = NULL;
	data.size_a = 0;
	data.size_b = 0;
	data.tail_a = NULL;
	data.tail_b = NULL;

	/* 3. Fill stack_a with argv values convert in integer */
	i = ac - 1;
	while (i >= 1)
	{
		num_ll = ft_atol(av[i]);
		new_node_ptr = new_node((int)num_ll);
		add_front(&(data.stack_a), &(data.tail_a), new_node_ptr);
		data.size_a++;
		i--;
	}
	ft_printf("\n--- Estado actual de los stacks ---\n");
	print_stack (data.stack_a, "Stack A", data.size_a);
	print_stack (data.stack_b, "Stack B", data.size_b);
	ft_printf("\n-----------------------------------\n");

	/* 4. Add index at stack elements */
	assign_index(&data);
	current = data.stack_a;
	ft_printf("\nStack A con Indices:\n");
	while (current)
	{
		ft_printf("  Value: %d, Index: %d\n", current->value, current->index);
		current = current->next;
	}
	ft_printf("-------------------------------------\n");

	/* 5. Executing sort algorithm */
	//TO DO

	/* 6. Print instructions list */
	//TO DO

	/* 7. Free memory */
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	return (0);
}
