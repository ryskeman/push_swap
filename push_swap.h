/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:51:43 by fernafer          #+#    #+#             */
/*   Updated: 2025/08/03 01:26:00 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_push_swap
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	t_node			*tail_a;
	t_node			*tail_b;
}					t_push_swap;

void				ft_error(void);
void				check_arguments(int ac, char **av);
int					is_number(char *str);
int					has_duplicates(char **argv);
int					is_int_in_range(char *str);
int					is_sorted(t_node *stack_a, t_node *stack_b);

long long			ft_atol(const char *str);
void				assign_index(t_push_swap *data);
void				init_and_fill(t_push_swap *data, int ac, char **av);
void				print_initial_stack(t_push_swap *data);

t_node				*new_node(int value);
t_node				*pop_front(t_node **head, t_node **tail, int *size);
t_node				*find_target_in_a(t_node *stack_a_head, t_node *b_node);
void				add_front(t_node **head, t_node **tail, t_node *new_node);
void				free_stack(t_node **head);
void				print_stack(t_node *stack, const char *name, int size);
/*void				print_stacks_debug(t_push_swap *data);*/
void				sort_two(t_push_swap *data);
void				sort_three(t_push_swap *data);
void				sort_five(t_push_swap *data);

void				sa(t_push_swap *data);
void				sb(t_push_swap *data);
void				ss(t_push_swap *data);
void				pa(t_push_swap *data);
void				pb(t_push_swap *data);
void				ra(t_push_swap *data);
void				rb(t_push_swap *data);
void				rr(t_push_swap *data);
void				rra(t_push_swap *data);
void				rrb(t_push_swap *data);
void				rrr(t_push_swap *data);

#endif
