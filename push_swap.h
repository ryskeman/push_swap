/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:51:43 by fernafer          #+#    #+#             */
/*   Updated: 2025/06/28 19:38:17 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}		t_node;

void				ft_error(void);
void				check_arguments(int ac, char **av);
int					is_number(char *str);
int					has_duplicates(char **argv);
int					is_int_in_range(char *str);
long long			ft_atol(const char *str);

#endif
