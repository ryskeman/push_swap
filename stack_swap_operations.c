/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:40:22 by fernafer          #+#    #+#             */
/*   Updated: 2025/07/24 12:01:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap two first elements in a stack*/
static void	ft_swap(t_node **head, int *size)
{
	t_node	*first;
	t_node	*second;

	if (*size < 2 || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_push_swap *data)
{
	ft_swap(&(data->stack_a), &(data->size_a));
	ft_printf("sa\n");
}

void	sb(t_push_swap *data)
{
	ft_swap(&(data->stack_b), &(data->size_b));
	ft_printf("sb\n");
}

void	ss(t_push_swap *data)
{
	ft_swap(&(data->stack_a), &(data->size_a));
	ft_swap(&(data->stack_b), &(data->size_b));
	ft_printf("ss\n");
}
