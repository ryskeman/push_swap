/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:07:54 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/23 18:41:12 by fernafer         ###   ########.fr       */
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
