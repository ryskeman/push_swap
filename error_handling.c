/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:55:16 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/01 16:10:26 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_int_in_range(char *str)
{
	long long	num;

	num = ft_atol(str);
	if (num > 2147483647LL || num < -2147483648LL)
		return (0);
	return (1);
}

void	check_arguments(int ac, char **av)
{
	int	i;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
			ft_error();
		if (!is_int_in_range(av[i]))
			ft_error();
		i++;
	}
	if (has_duplicates(av))
		ft_error();
}
