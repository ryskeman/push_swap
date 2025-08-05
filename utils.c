/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:07:54 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/05 19:27:08 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/* Function that assign calculated index at current node */
void	assign_index(t_push_swap *data)
{
	t_node	*current;
	t_node	*comparer;
	int		indx;

	current = data->stack_a;
	while (current)
	{
		indx = 0;
		comparer = data->stack_a;
		while (comparer)
		{
			if (comparer->value < current->value)
				indx++;
			comparer = comparer->next;
		}
		current->index = indx;
		current = current->next;
	}
}

/* Function that DEBUG Stack movements. */
/*
void	print_stacks_debug(t_push_swap *data)
{
	t_node *current_a = data->stack_a;
	t_node *current_b = data->stack_b;
	int	i = 0;

	ft_printf("--- DEBUG STACKS ---\n");
	ft_printf("Stack A (size: %d):\n", data->size_a);
	while (current_a)
	{
		ft_printf("  [%d] Value: %d, Index: %d\n",
		 i++, current_a->value, current_a->index);
		current_a = current_a->next;
	}
	if (data->size_a == 0)
		ft_printf("  (empty)\n");
	i = 0;
	ft_printf("Stack B (size: %d):\n", data->size_b);
        while (current_b)
        {
                ft_printf("  [%d] Value: %d, Index: %d\n",
				 i++, current_b->value, current_b->index);
                current_b = current_b->next;
        }
        if (data->size_b == 0)
                ft_printf("  (empty)\n");
	ft_printf("--------------------\n\n");
}
*/
